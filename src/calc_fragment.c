/*
** calc_fragment.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu Apr 21 20:09:40 2016 Ludovic Petrenko
** Last update Mon May  2 05:31:05 2016 Ludovic Petrenko
*/

#include <math.h>
#include "raytracer.h"
#include "engine/vector.h"

void		set_vectors(t_data *data, t_camera *c)
{
  double	len;
  t_vec3	tmp;

  len = tan(c->fov * M_PI / 360.0) * 2.0 / data->width;
  tmp = vec3_normalize(cross_vec3(c->dir, vec3(0, 0, 1.0)));
  c->incr_x = mult_vec3(tmp, len);
  len *= (double)data->height / data->width;
  tmp = vec3_normalize(cross_vec3(c->dir, tmp));
  c->incr_x = mult_vec3(tmp, len);
  c->origin = add_vec3(c->pos, vec3_normalize(c->dir));
  c->origin = sub_vec3(c->origin, mult_vec3(c->incr_x, data->width / 2.0));
  c->origin = sub_vec3(c->origin, mult_vec3(c->incr_y, data->height / 2.0));
}

unsigned int	calc_pixel(t_scene *scene, t_ivec2 *pix)
{
  t_ray		ray;
  t_intersect	i;

  ray.pos = scene->cam.pos;
  ray.dir = scene->cam.origin;
  ray.dir = add_vec3(ray.dir, mult_vec3(scene->cam.incr_x, pix->x));
  ray.dir = add_vec3(ray.dir, mult_vec3(scene->cam.incr_y, pix->y));
  ray.dir = sub_vec3(ray.dir, ray.pos);
  i = node_intersect(&scene->octree, ray);
  return (calc_ray(scene, ray, 0));
}

void		calc_fragment(t_data *data, unsigned int *buf, t_ivec2 *pos)
{
  t_ivec2	tmp;
  int		i;

  tmp = pos[0];
  i = 0;
  while (tmp.x < pos[1].x && tmp.y < pos[1].y)
    {
      buf[i] = calc_pixel(data->scene, pos);
      tmp.x = (tmp.x + 1 < data->width) ? tmp.x + 1 : 0;
      tmp.y += (tmp.x == 0);
      ++i;
    }
}
