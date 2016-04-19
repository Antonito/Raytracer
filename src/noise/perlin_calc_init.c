/*
** perlin_calc_init.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Apr 19 09:16:10 2016 Antoine Baché
** Last update Tue Apr 19 09:30:11 2016 Antoine Baché
*/

#include <stdarg.h>
#include "noise.h"

static void		perlin_calc_init_2d(t_vec2 *pos, t_ivec2 *origin,
					    t_mask2 *mask, float scale)
{
  pos->x /= scale;
  pos->y /= scale;
  origin->x = (int)pos->x;
  origin->y = (int)pos->y;
  mask->x = origin->x & 255;
  mask->y = origin->y & 255;
}

static void		perlin_calc_init_3d(t_vec3 *pos, t_ivec3 *origin,
					    t_mask3 *mask, float scale)
{
  pos->x /= scale;
  pos->y /= scale;
  pos->z /= scale;
  origin->x = (int)pos->x;
  origin->y = (int)pos->y;
  origin->z = (int)pos->z;
  mask->x = origin->x & 255;
  mask->y = origin->y & 255;
  mask->z = origin->z & 255;
}

static void		perlin_calc_init_4d(t_vec4 *pos, t_ivec4 *origin,
					    t_mask4 *mask, float scale)
{
  pos->x /= scale;
  pos->y /= scale;
  pos->z /= scale;
  pos->w /= scale;
  origin->x = (int)pos->x;
  origin->y = (int)pos->y;
  origin->z = (int)pos->z;
  origin->w = (int)pos->w;
  mask->x = origin->x & 255;
  mask->y = origin->y & 255;
  mask->z = origin->z & 255;
  mask->w = origin->w & 255;
}

void		perlin_calc_init(void *pos, void *origin, void *mask, ...)
{
  va_list	args;
  float		scale;
  int		dim;

  va_start(args, mask);
  scale = va_arg(args, float);
  dim = va_arg(args, int);
  va_end(args);
  if (dim == 2)
    perlin_calc_init_2d(pos, origin, mask, scale);
  else if (dim == 3)
    perlin_calc_init_3d(pos, origin, mask, scale);
  else if (dim == 4)
    perlin_calc_init_4d(pos, origin, mask, scale);
}
