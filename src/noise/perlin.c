/*
** perlin.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:20:41 2016 Antoine Baché
** Last update Tue Apr 19 12:04:09 2016 Antoine Baché
*/

#include <unistd.h>
#include "noise.h"

static double		perlin_noise_2d(t_vec2 *pos, float scale,
					unsigned char *perm)
{
  static t_vec2		*table = NULL;
  t_vec2		smooth;
  t_vec2		smooth_tmp;
  t_ivec2		origin;
  t_mask2		mask;
  t_gradient2		gradient;
  t_perlin_color2	color;
  float			tmp_x;
  float			tmp_y;
  double       		res;

  if (!table)
    table = perlin_2d_table();
  perlin_calc_init(pos, &origin, &mask, (double)scale, 2);
  calc_perlin_gradient(&gradient, &mask, perm, 2);
  perlin_calc_smooth_values(pos, &origin, &smooth_tmp, 2);
  perlin_calc_smooth(&smooth, &smooth_tmp, 2);
  perlin_calc_color(&color, pos, &origin, (void *)table, (void *)&gradient, 2);
  tmp_x = color.a + smooth.x * (color.b - color.a);
  tmp_y = color.c + smooth.x * (color.d - color.c);
  res = (double)(tmp_x + smooth.y * (tmp_y - tmp_x));
  return (res);
}

static double		perlin_noise_3d(t_vec3 *pos, float scale,
					unsigned char *perm)
{
  static t_vec3		*table = NULL;
  t_vec3		smooth;
  t_vec3		smooth_tmp;
  t_ivec3		origin;
  t_mask3		mask;
  t_gradient3		gradient;
  t_perlin_color3	color;

  if (!table && !(table = perlin_3d_table()))
    return (0.0);
  perlin_calc_init(pos, &origin, &mask, (double)scale, 3);
  calc_perlin_gradient(&gradient, &mask, perm, 3);
  perlin_calc_smooth_values(pos, &origin, &smooth_tmp, 3);
  perlin_calc_smooth(&smooth, &smooth_tmp, 3);
  perlin_calc_color(&color, pos, &origin, (void *)table, (void *)&gradient, 3);
  return (perlin_calc_pixel_3d(&color, &smooth));
}

static double		perlin_noise_4d(t_vec4 *pos, float scale,
					unsigned char *perm)
{
  static t_vec4		*table = NULL;
  t_vec4		smooth;
  t_vec4		smooth_tmp;
  t_ivec4		origin;
  t_mask4		mask;
  t_gradient4		gradient;
  t_perlin_color4	color;

  if (!table)
    table = perlin_4d_table();
  perlin_calc_init(pos, &origin, &mask, (double)scale, 4);
  calc_perlin_gradient(&gradient, &mask, perm, 4);
  perlin_calc_smooth_values(pos, &origin, &smooth_tmp, 4);
  perlin_calc_smooth(&smooth, &smooth_tmp, 4);
  perlin_calc_color(&color, pos, &origin, (void *)table, (void *)&gradient, 4);
  return (0.0);
}

double			perlin_noise(void *pos, float scale, int dim)
{
  static unsigned char	*permutation = NULL;

  if (!permutation && !(permutation = permutation_table()))
    return (0.0);
  if (dim == 2)
    return (perlin_noise_2d(pos, scale, permutation));
  if (dim == 3)
    return (perlin_noise_3d(pos, scale, permutation));
  if (dim == 4)
    return (perlin_noise_4d(pos, scale, permutation));
#ifdef	DEBUG
  write(2, "Incorrect dimmension\n", 21);
#endif
  return (0.0);
}
