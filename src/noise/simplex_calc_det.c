/*
** simplex_calc_det.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 11:30:21 2016 Antoine Baché
** Last update Wed Apr 20 11:40:21 2016 Antoine Baché
*/

#include <stdarg.h>
#include "noise.h"

static void		simplex_calc_det_2d(t_vec2 *det, t_vec2 *dist,
					    t_ivec2 *grad, unsigned char *table)
{
  t_vec2		offset;

  if (dist->x > dist->y)
    {
      offset.x = 1;
      offset.y = 0;
    }
  else
    {
      offset.x = 0;
      offset.y = 1;
    }
  det[0].x = dist->x;
  det[0].y = dist->y;
}

static void		simplex_calc_det_3d(t_vec3 *det, t_vec3 *dist,
					    t_ivec3 *grad, unsigned char *table)
{
}

static void		simplex_calc_det_4d(t_vec4 *det, t_vec4 *dist,
					    t_ivec4 *grad, unsigned char *table)
{
}

void			simplex_calc_det(void *det, void *dist,
					 void *grad, ...)
{
  va_list		args;
  unsigned char		*table;
  int			dim;

  va_start(args, grad);
  table = va_arg(args, unsigned char *);
  dim = va_arg(args, int);
  va_end(args);
  if (dim == 2)
    simplex_calc_det_2d(det, dist, grad, table);
  else if (dim == 3)
    simplex_calc_det_3d(det, dist, grad, table);
  else if (dim == 4)
    simplex_calc_det_4d(det, dist, grad, table);
}
