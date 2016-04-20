/*
** simplex_calc_det.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 11:30:21 2016 Antoine Baché
** Last update Wed Apr 20 13:01:45 2016 Antoine Baché
*/

#include <stdarg.h>
#include <math.h>
#include "noise.h"

static void		simplex_calc_det_2d(t_vec2 *det, t_vec2 *dist,
					    t_vec2 *offset)
{
  double		tmp;

  tmp = (3.0 - sqrt(3.0)) / 6.0;
  det[0].x = dist->x;
  det[0].y = dist->y;
  det[1].x = det[0].x + offset->x - tmp;
  det[1].y = det[0].y + offset->y - tmp;
  det[2].x = det[0].x + 1.0 - 2.0 * tmp;
  det[2].y = det[0].y + 1.0 - 2.0 * tmp;
}

static void		simplex_calc_det_3d(t_vec3 *det, t_vec3 *dist,
					    t_vec3 *offset)
{
  double		tmp;

  tmp = 1.0 / 6.0;
  det[0].x = dist->x;
  det[0].y = dist->y;
  det[0].z = dist->z;
  det[1].x = det[0].x - offset[0].x + tmp;
  det[1].y = det[0].y - offset[0].y + tmp;
  det[1].z = det[0].z - offset[0].z + tmp;
  det[2].x = det[0].x - offset[1].x + 2.0 * tmp;
  det[2].y = det[0].y - offset[1].y + 2.0 * tmp;
  det[2].z = det[0].z - offset[1].z + 2.0 * tmp;
  det[3].x = det[0].x - 1.0 + 3.0 * tmp;
  det[3].y = det[0].y - 1.0 + 3.0 * tmp;
  det[3].z = det[0].z - 1.0 + 3.0 * tmp;
}

static void		simplex_calc_det_4d(t_vec4 *det, t_vec4 *dist,
					    t_vec4 *offset)
{
  double		tmp;

  tmp = (5.0 - sqrt(5.0)) / 20.0;
  det[0].x = dist->x;
  det[0].y = dist->y;
  det[0].z = dist->z;
  det[0].w = dist->w;
  det[1].x = det[0].x - offset[0].x + tmp;
  det[1].y = det[0].y - offset[0].y + tmp;
  det[1].z = det[0].z - offset[0].z + tmp;
  det[1].w = det[0].w - offset[0].w + tmp;
  det[2].x = det[0].x - offset[1].x + 2.0 * tmp;
  det[2].y = det[0].y - offset[1].y + 2.0 * tmp;
  det[2].z = det[0].z - offset[1].z + 2.0 * tmp;
  det[2].w = det[0].w - offset[1].w + 2.0 * tmp;
  det[3].x = det[0].x - offset[2].x + 3.0 * tmp;
  det[3].y = det[0].y - offset[2].y + 3.0 * tmp;
  det[3].z = det[0].z - offset[2].z + 3.0 * tmp;
  det[3].w = det[0].w - offset[2].w + 3.0 * tmp;
  det[4].x = det[0].x - 1.0 + 4.0 * tmp;
  det[4].y = det[0].y - 1.0 + 4.0 * tmp;
  det[4].z = det[0].z - 1.0 + 4.0 * tmp;
  det[4].w = det[0].w - 1.0 + 4.0 * tmp;
}

void			simplex_calc_det(void *det, void *dist,
					 void *grad, ...)
{
  va_list		args;
  unsigned char		*table;
  void			*offset;
  int			dim;

  va_start(args, grad);
  table = va_arg(args, unsigned char *);
  offset = va_arg(args, void *);
  dim = va_arg(args, int);
  va_end(args);
  if (dim == 2)
    {
      simplex_calc_det_2d(det, dist, offset);
    }
  else if (dim == 3)
    {
      simplex_calc_det_3d(det, dist, grad, offset);
    }
  else if (dim == 4)
    {
      simplex_calc_det_4d(det, dist, grad, offset);
    }
}
