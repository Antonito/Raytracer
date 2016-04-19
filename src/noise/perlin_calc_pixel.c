/*
** perlin_calc_pixel.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Apr 19 11:35:24 2016 Antoine Baché
** Last update Tue Apr 19 18:36:27 2016 Antoine Baché
*/

#include "noise.h"

double		perlin_calc_pixel_2d(t_perlin_color2 *color, t_vec2 *smooth)
{
  double	tmp[2];
  double	res;

  tmp[0] = color->a + smooth->x * (color->b - color->a);
  tmp[1] = color->c + smooth->x * (color->d - color->c);
  res = tmp[0] + smooth->y * (tmp[1] - tmp[0]);
  return (res);
}

double		perlin_calc_pixel_3d(t_perlin_color3 *color, t_vec3 *smooth)
{
  double	tmp[6];
  double	res;

  tmp[0] = color->a[0] + smooth->x * (color->b[0] - color->a[0]);
  tmp[1] = color->c[0] + smooth->x * (color->d[0] - color->c[0]);
  tmp[2] = color->a[1] + smooth->x * (color->b[1] - color->a[1]);
  tmp[3] = color->c[1] + smooth->x * (color->d[1] - color->c[1]);
  tmp[4] = tmp[0] + smooth->y * (tmp[1] - tmp[0]);
  tmp[5] = tmp[2] + smooth->y * (tmp[3] - tmp[2]);
  res = tmp[4] + smooth->z * (tmp[5] - tmp[4]);
  return (res);
}

double		perlin_calc_pixel_4d(t_perlin_color4 *color, t_vec4 *smooth)
{
  double	tmp[14];
  double	res;

  tmp[0] = color->a[0] + smooth->x * (color->b[0] - color->a[0]);
  tmp[1] = color->c[0] + smooth->x * (color->d[0] - color->c[0]);
  tmp[2] = color->a[1] + smooth->x * (color->b[1] - color->a[1]);
  tmp[3] = color->c[1] + smooth->x * (color->d[1] - color->c[1]);
  tmp[4] = color->a[2] + smooth->x * (color->b[2] - color->a[2]);
  tmp[5] = color->c[2] + smooth->x * (color->d[2] - color->c[2]);
  tmp[6] = color->a[3] + smooth->x * (color->b[3] - color->a[3]);
  tmp[7] = color->c[3] + smooth->x * (color->d[3] - color->c[3]);
  tmp[8] = tmp[0] + smooth->y * (tmp[1] - tmp[0]);
  tmp[9] = tmp[2] + smooth->y * (tmp[3] - tmp[2]);
  tmp[10] = tmp[4] + smooth->y * (tmp[5] - tmp[4]);
  tmp[11] = tmp[6] + smooth->y * (tmp[7] - tmp[6]);
  tmp[12] = tmp[8] + smooth->z * (tmp[9] - tmp[8]);
  tmp[13] = tmp[10] + smooth->z * (tmp[11] - tmp[10]);
  res = tmp[12] + smooth->w * (tmp[13] - tmp[12]);
  return (res);
}
