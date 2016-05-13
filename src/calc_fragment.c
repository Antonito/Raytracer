/*
** calc_fragment.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu Apr 21 20:09:40 2016 Ludovic Petrenko
** Last update Fri May 13 05:35:31 2016 Ludovic Petrenko
*/

#pragma GCC warning "\e[31m\e[1mCommentaires + Norme !\e[0m"

#include <stdio.h>

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
  double	len;

  ray.pos = scene->cam.pos;
  /* ray.dir = add_vec3(scene->cam.origin, */
  /* 		     mult_vec3(scene->cam.incr_x, pix->x)); */
  /* ray.dir = add_vec3(ray.dir, mult_vec3(scene->cam.incr_y, pix->y)); */
  /* ray.dir = vec3_normalize(sub_vec3(ray.dir, ray.pos)); */
  ray.dir.x = scene->cam.origin.x + scene->cam.incr_x.x * pix->x +
    scene->cam.incr_y.x * pix->y - ray.pos.x;
  ray.dir.y = scene->cam.origin.y + scene->cam.incr_x.y * pix->x +
    scene->cam.incr_y.y * pix->y - ray.pos.y;
  ray.dir.z = scene->cam.origin.z + scene->cam.incr_x.z * pix->x +
    scene->cam.incr_y.z * pix->y - ray.pos.z;
  len = sqrt(ray.dir.x * ray.dir.x + ray.dir.y *
	     ray.dir.y + ray.dir.z * ray.dir.z);
  ray.dir.x /= len;
  ray.dir.y /= len;
  ray.dir.z /= len;
  ray.env = NULL;
  return ((calc_ray(scene, &ray, 0)).color.full);
}

void		calc_fragment(t_data *data, unsigned int *buf, t_ivec2 *pos)
{
  t_ivec2	tmp;
  int		size = data->cur_width * data->cur_height;
  int		i = 0;

  tmp = pos[0];
  while (tmp.y <= pos[1].y)
    {
      buf[tmp.x + data->cur_width * tmp.y] = calc_pixel(data->scene, &tmp);
      /* buf[i + 1] = buf[i]; */
      /* buf[i + pos[1].x] = buf[i]; */
      /* buf[i + pos[1].x + 1] = buf[i]; */
      tmp.x = (tmp.x + 1 < pos[1].x) ? tmp.x + 1 : 0;
      tmp.y += (tmp.x == 0);
      if (tmp.x == 0)
	{
	  /* printf("\r%.2f%%   ", 100.0 * i / size); */
	  /* fflush(stdout); */
	}
      /* if (tmp.x == 0) */
      /* 	i += pos[1].x; */
      ++i;
    }
}
