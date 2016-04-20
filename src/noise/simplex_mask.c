/*
** simplex_mask.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 14:05:12 2016 Antoine Baché
** Last update Wed Apr 20 14:12:52 2016 Antoine Baché
*/

#include "noise.h"

static void		simplex_mask_2d(t_ivec2 *mask, t_ivec2 *origin)
{
  mask->x = origin->x & 255;
  mask->y = origin->y & 255;
}

static void		simplex_mask_3d(t_ivec3 *mask, t_ivec3 *origin)
{
  mask->x = origin->x & 255;
  mask->y = origin->y & 255;
  mask->z = origin->z & 255;
}

static void		simplex_mask_4d(t_ivec4 *mask, t_ivec4 *origin)
{
  mask->x = origin->x & 255;
  mask->y = origin->y & 255;
  mask->z = origin->z & 255;
  mask->w = origin->w & 255;
}

void			simplex_mask(void *mask, void *origin, int dim)
{
  if (dim == 2)
    {
      simplex_mask_2d(mask, origin);
    }
  else if (dim == 3)
    {
      simplex_mask_3d(mask, origin);
    }
  else if (dim == 4)
    {
      simplex_mask_4d(mask, origin);
    }
}
