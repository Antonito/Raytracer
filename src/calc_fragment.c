/*
** calc_fragment.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu Apr 21 20:09:40 2016 Ludovic Petrenko
** Last update Sun May  8 23:08:08 2016 Ludovic Petrenko
*/

#pragma GCC warning "\e[31m\e[1mCommentaires + Norme !\e[0m"

#include <math.h>
#include "raytracer.h"
#include "engine/vector.h"

void		set_vectors(t_data *data, t_camera *c)
{
  double	len;
  t_vec3	tmp;

  len = tan(c->fov / 2.0 * M_PI / 180.0) * 2.0 / (double)data->cur_width;
  tmp = vec3_normalize(vec3(c->dir.y, -c->dir.x, 0));
  c->incr_x = mult_vec3(tmp, len);
  /* len = tan(c->fov * data->cur_width / data->cur_height / 2.0 */
  /* 	    * M_PI / 180.0) * 2.0 / data->cur_height; */
  tmp = vec3_normalize(cross_vec3(c->dir, tmp));
  c->incr_y = mult_vec3(tmp, len);
  c->origin = add_vec3(c->pos, c->dir);
  c->origin = sub_vec3(c->origin, mult_vec3(c->incr_x,
					    data->cur_width / 2.0));
  c->origin = sub_vec3(c->origin, mult_vec3(c->incr_y,
					    data->cur_height / 2.0));
}

unsigned int	calc_pixel(t_scene *scene, t_ivec2 *pix)
{
  t_ray		ray;

  ray.pos = scene->cam.pos;
  ray.dir = add_vec3(scene->cam.origin,
		     mult_vec3(scene->cam.incr_x, (double)pix->x));
  ray.dir = add_vec3(ray.dir, mult_vec3(scene->cam.incr_y, (double)pix->y));
  ray.dir = vec3_normalize(sub_vec3(ray.dir, ray.pos));
  ray.src = NULL;
  /* printf("DIR (%.5f, %.5f, %.5f)\n", ray.dir.x, ray.dir.y, ray.dir.z); */
  return (calc_ray(scene, &ray, 0));
}

void		calc_fragment(t_data *data, unsigned int *buf, t_ivec2 *pos)
{
  t_ivec2	tmp;
  int		i;

  tmp = pos[0];
  i = 0;
  while (tmp.y <= pos[1].y)
    {
      buf[i] = calc_pixel(data->scene, &tmp);
      /* buf[i + 1] = buf[i]; */
      /* buf[i + pos[1].x] = buf[i]; */
      /* buf[i + pos[1].x + 1] = buf[i]; */
      tmp.x = (tmp.x + 1 < pos[1].x) ? tmp.x + 1 : 0;
      tmp.y += (tmp.x == 0);
      i+=1;
      /* if (tmp.x == 0) */
      /* 	i += pos[1].x; */
    }
}
