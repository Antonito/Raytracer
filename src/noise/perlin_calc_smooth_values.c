/*
** perlin_calc_smooth_values.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Apr 19 09:49:11 2016 Antoine Baché
** Last update Tue Apr 19 09:58:04 2016 Antoine Baché
*/

#include "noise.h"

static void	perlin_calc_smooth_values_2d(t_vec2 *pos, t_vec2 *origin,
					     t_vec2 *fill)
{
  fill->x = pos->x - origin->x;
  fill->y = pos->y - origin->y;
}

static void	perlin_calc_smooth_values_3d(t_vec3 *pos, t_vec3 *origin,
					     t_vec3 *fill)
{
  fill->x = pos->x - origin->x;
  fill->y = pos->y - origin->y;
  fill->z = pos->z - origin->z;
}

static void	perlin_calc_smooth_values_4d(t_vec4 *pos, t_vec4 *origin,
					     t_vec4 *fill)
{
  fill->x = pos->x - origin->x;
  fill->y = pos->y - origin->y;
  fill->z = pos->z - origin->z;
  fill->w = pos->w - origin->w;
}

void		perlin_calc_smooth_values(void *pos, void *origin, void *fill,
				       int dim)
{
  if (dim == 2)
    perlin_calc_smooth_values_2d(pos, origin, fill);
  else if (dim == 3)
    perlin_calc_smooth_values_3d(pos, origin, fill);
  else if (dim == 4)
    perlin_calc_smooth_values_4d(pos, origin, fill);
}
