/*
** simplex_calc_init.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 10:41:36 2016 Antoine Baché
** Last update Wed Apr 20 11:07:29 2016 Antoine Baché
*/

#include <stdarg.h>
#include <math.h>
#include "noise.h"

static void		simplex_calc_init_2d(t_vec2 *pos, t_ivec2 *origin_int,
					     t_vec2 *origin, ...)
{
  double		scale;
  double		tmp;
  t_vec2		*dist_origin;

  va_start(args, mask);
  dist_origin = va_arg(args, t_vec2 *);
  scale = va_arg(args, double);
  va_end(args);
  pos->x /= scale;
  pos->y /= scale;
  tmp = ((pos->x + pos->y) * 0.5 * (sqrt(3.0) - 1.0));
  origin_int->x = (int)(pos->x + tmp);
  origin_int->y = (int)(pos->y + tmp);
  tmp = (origin_int->x + origin_int->y) * (3.0 - (sqrt(3.0) / 6.0));
  origin->x = origin_int->x - tmp;
  origin->y = origin_int->y - tmp;
  dist_origin->x = pos->x - origin->x;
  dist_origin->y = pos->y - origin->y;
}

static void		simplex_calc_init_3d(t_vec3 *pos, t_ivec3 *origin_int,
					     t_vec3 *origin, ...)
{
  double		scale;
  double		tmp;
  t_vec3		*dist_origin;

  va_start(args, mask);
  dist_origin = va_arg(args, t_vec3 *);
  scale = va_arg(args, double);
  va_end(args);
  pos->x /= scale;
  pos->y /= scale;
  pos->z /= scale;
  tmp = (pos->x + pos->y + pos->z) * (1.0 / 3.0);
  origin_int->x = (int)(pos->x + tmp);
  origin_int->y = (int)(pos->y + tmp);
  origin_int->z = (int)(pos->z + tmp);
  tmp = (origin_int->x + origin_int->y + origin_int->z) * (1.0 / 6.0);
  origin->x = origin_int->x - tmp;
  origin->y = origin_int->y - tmp;
  origin->z = origin_int->z - tmp;
  dist_origin->x = pos->x - origin->x;
  dist_origin->y = pos->y - origin->y;
  dist_origin->z = pos->z - origin->z;
}

static void		simplex_calc_init_4d_dist(t_vec4 *dist_origin,
						  t_vec4 *pos, t_vec4 *origin)
{
  dist_origin->x = pos->x - origin->x;
  dist_origin->y = pos->y - origin->y;
  dist_origin->z = pos->z - origin->z;
  dist_origin->w = pos->w - origin->w;
}

static void		simplex_calc_init_4d(t_vec4 *pos, t_ivec4 *origin_int,
					     t_vec4 *origin, ...)
{
  double		scale;
  double		tmp;
  t_vec4		*dist_origin;

  va_start(args, mask);
  dist_origin = va_arg(args, t_vec4 *);
  scale = va_arg(args, double);
  va_end(args);
  pos->x /= scale;
  pos->y /= scale;
  pos->z /= scale;
  pos->w /= scale;
  tmp = (pos->x + pos->y + pos->z + pos->w) * ((sqrt(5.0) - 1.0) / 4.0);
  origin_int->x = (int)(pos->x + tmp);
  origin_int->y = (int)(pos->y + tmp);
  origin_int->z = (int)(pos->z + tmp);
  origin_int->w = (int)(pos->w + tmp);
  tmp = (origin_int->x + origin_int->y + origin_int->z) *
    ((5.0 - sqrt(5.0)) / 20.0);
  origin->x = origin_int->x - tmp;
  origin->y = origin_int->y - tmp;
  origin->z = origin_int->z - tmp;
  origin->w = origin_int->w - tmp;
  simplex_calc_init_4d_dist(dist_origin, pos, origin);
}

void			simplex_calc_init(void *pos, void *origin_int,
					  void *origin, ...)
{
  va_list		args;
  void			*dist_origin;
  double		scale;
  int			dim;

  va_start(args, mask);
  dist_origin = va_arg(args, void *);
  scale = va_arg(args, double);
  dim = va_arg(args, int);
  va_end(args);
  if (dim == 2)
    simplex_calc_init_2d(pos, origin_int, origin, dist_origin, scale);
  else if (dim == 3)
    simplex_calc_init_3d(pos, origin_int, origin, dist_origin, scale);
  else if (dim == 4)
    simplex_calc_init_4d(pos, origin_int, origin, dist_origin, scale);
}
