/*
** perlin_calc_smooth.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Apr 19 09:37:18 2016 Antoine Baché
** Last update Tue Apr 19 09:46:36 2016 Antoine Baché
*/

#include "noise.h"

static void	perlin_calc_smooth_2d(t_vec2 *smooth, t_vec2 *value)
{
  smooth->x = value->x * value->x * value->x *
    (value->x * (value->x * 6 - 15) + 10);
  smooth->y = value->y * value->y * value->y *
    (value->y * (value->y * 6 - 15) + 10);
}

static void	perlin_calc_smooth_3d(t_vec3 *smooth, t_vec3 *value)
{
  smooth->x = value->x * value->x * value->x *
    (value->x * (value->x * 6 - 15) + 10);
  smooth->y = value->y * value->y * value->y *
    (value->y * (value->y * 6 - 15) + 10);
  smooth->z = value->z * value->z * value->z *
    (value->z * (value->z * 6 - 15) + 10);
}

static void	perlin_calc_smooth_4d(t_vec4 *smooth, t_vec4 *value)
{
  smooth->x = value->x * value->x * value->x *
    (value->x * (value->x * 6 - 15) + 10);
  smooth->y = value->y * value->y * value->y *
    (value->y * (value->y * 6 - 15) + 10);
  smooth->z = value->z * value->z * value->z *
    (value->z * (value->z * 6 - 15) + 10);
  smooth->w = value->w * value->w * value->w *
    (value->w * (value->w * 6 - 15) + 10);
}

void		perlin_calc_smooth(void *smooth, void *values, int dim)
{
  if (dim == 2)
    perlin_calc_smooth_2d(smooth, values);
  else if (dim == 3)
    perlin_calc_smooth_3d(smooth, values);
  else if (dim == 4)
    perlin_calc_smooth_4d(smooth, values);
}
