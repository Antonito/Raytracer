/*
** simplex_calc_grad.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 14:25:58 2016 Antoine Baché
** Last update Wed Apr 20 18:59:32 2016 Antoine Baché
*/

#include <stdarg.h>
#include "noise.h"

static void		simplex_calc_grad_2d(int *grad, t_ivec2 *mask,
					     t_vec2 *offset,
					     unsigned char *table)
{
  grad[0] = table[mask->x + table[mask->y]] & 7;
  grad[1] = table[mask->x + (int)offset->x + (int)table[mask->y +
							(int)offset->y]] & 7;
  grad[2] = table[mask->x + 1 + (int)table[mask->y + 1]] & 7;
}

static void		simplex_calc_grad_3d(int *grad, t_ivec3 *mask,
					     t_vec3 *offset,
					     unsigned char *table)
{
  grad[0] = table[mask->x + table[mask->y + table[mask->z]]] % 12;
  grad[1] = table[mask->x + (int)offset[0].x +
		  table[mask->y + (int)offset[0].y +
			table[mask->z + (int)offset[0].z]]] % 12;
  grad[1] = table[mask->x + (int)offset[1].x +
		  table[mask->y + (int)offset[1].y +
			table[mask->z + (int)offset[1].z]]] % 12;
  grad[3] = table[mask->x + 1 + table[mask->y + 1 + table[mask->z + 1]]] % 12;
}

static void		simplex_calc_grad_4d(int *grad, t_ivec4 *mask,
					     t_vec4 *offset,
					     unsigned char *table)
{
  grad[0] = table[mask->x + table[mask->y +
				  table[mask->z + table[mask->w]]]] & 31;
  grad[1] = table[mask->x + (int)offset[0].x +
		  table[mask->y + (int)offset[0].y +
			table[mask->z + (int)offset[0].z +
			      table[mask->w + (int)offset[0].w]]]] & 31;
  grad[2] = table[mask->x + (int)offset[1].x +
		  table[mask->y + (int)offset[1].y +
			table[mask->z + (int)offset[1].z +
			      table[mask->w + (int)offset[1].w]]]] & 31;
  grad[3] = table[mask->x + (int)offset[2].x +
		  table[mask->y + (int)offset[2].y +
			table[mask->z + (int)offset[2].z +
			      table[mask->w + (int)offset[2].w]]]] & 31;
  grad[4] = table[mask->x + 1 +
		  table[mask->y + 1 + table[mask->z + 1 +
					    table[mask->w + 1]]]] & 31;
}

void			simplex_calc_grad(int *grad, void *mask,
					  void *offset, ...)
{
  va_list		args;
  unsigned char		*perm;
  int			dim;

  va_start(args, offset);
  perm = va_arg(args, unsigned char *);
  dim = va_arg(args, int);
  va_end(args);
  if (dim == 2)
    {
      simplex_calc_grad_2d(grad, mask, offset, perm);
    }
  else if (dim == 3)
    {
      simplex_calc_grad_3d(grad, mask, offset, perm);
    }
  else if (dim == 4)
    {
      simplex_calc_grad_4d(grad, mask, offset, perm);
    }
}
