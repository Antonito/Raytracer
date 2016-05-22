/*
** calc_fragment.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu Apr 21 20:09:40 2016 Ludovic Petrenko
** Last update Sun May 22 22:48:15 2016 Antoine Baché
*/

#include <stdio.h>
#include <math.h>
#include "raytracer.h"
#include "engine/vector.h"

void		set_vectors(t_data *data, t_camera *c)
{
  double	len;
  t_vec3	tmp;

  len = tan(c->fov / 2.0 * M_PI / 180.0) * 2.0 /
    (double)data->config.cur_width;
  tmp = vec3_normalize(vec3(c->dir.y, -c->dir.x, 0));
  c->incr_x = mult_vec3(tmp, len);
  tmp = vec3_normalize(cross_vec3(c->dir, tmp));
  c->incr_y = mult_vec3(tmp, len);
  c->origin = add_vec3(c->pos, c->dir);
  c->origin = sub_vec3(c->origin, mult_vec3(c->incr_x,
					    data->config.cur_width / 2.0));
  c->origin = sub_vec3(c->origin, mult_vec3(c->incr_y,
					    data->config.cur_height / 2.0));
}

unsigned int	calc_pixel(t_scene *scene, t_ivec2 *pix, t_data *data,
			   pthread_mutex_t *mutex)
{
  t_ray		ray;
  t_intersect	inter;

  ray.pos = scene->cam.pos;
  ray.dir = add_vec3(scene->cam.origin,
  		     mult_vec3(scene->cam.incr_x, pix->x));
  ray.dir = add_vec3(ray.dir, mult_vec3(scene->cam.incr_y, pix->y));
  ray.dir = vec3_normalize(sub_vec3(ray.dir, ray.pos));
  ray.env = NULL;
  pthread_mutex_lock(mutex);
  calc_ray(scene, &ray, 0, &inter);
  if (inter.dist < 0.00001 || inter.dist == INFINITY)
    scene->zbuf[pix->x + pix->y * data->config.cur_width] =
      (float)scene->cam.focale;
  else
    scene->zbuf[pix->x + pix->y * data->config.cur_width] = (float)inter.dist;
  pthread_mutex_unlock(mutex);
  return (inter.color.full);
}

void		calc_fragment(t_data *data, unsigned int *buf, t_ivec2 *pos,
			      pthread_mutex_t *mutex)
{
  t_ivec2	tmp;

  tmp = pos[0];
  while (tmp.y <= pos[1].y && (tmp.x = pos[0].x - 1))
    {
      while (++tmp.x < pos[1].x)
	buf[tmp.x + data->config.cur_width * tmp.y] =
	  calc_pixel(data->scene, &tmp, data, mutex);
      ++tmp.y;
    }
}
