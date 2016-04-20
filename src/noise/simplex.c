/*
** simplex.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 10:26:24 2016 Antoine Baché
** Last update Wed Apr 20 17:49:47 2016 Antoine Baché
*/

#include "noise.h"
#include "tools/memory.h"

static double		simplex_noise_2d(t_vec2 *pos, float scale,
					unsigned char *perm,
					t_perlin_state state)
{
  static t_vec2		*table = NULL;
  t_ivec2		origin_int;
  t_ivec2		mask;
  t_vec2		origin;
  t_vec2		dist_origin;
  t_vec2		det[3];
  t_vec2		offset;
  int			grad[3];

  if (state == FREE)
    {
      if (table)
	my_free(table);
      table = NULL;
      return (0.0);
    }
  if (!table && !(table = perlin_2d_table()))
    return (0.0);
  simplex_calc_init(pos, &origin_int, &origin, (void *)&dist_origin,
		    (double)scale, 2);
  simplex_mask(&mask, &origin_int, 2);
  simplex_calc_offset(&offset, &dist_origin, 2, DRAW);
  simplex_calc_det(det, &dist_origin, &offset, 2);
  simplex_calc_grad(grad, &mask, &offset, perm, 2);
  return (simplex_calc_pixel(det, table, grad, 2));
}

static double		simplex_noise_3d(t_vec3 *pos, float scale,
					unsigned char *perm,
					t_perlin_state state)
{
  static t_vec3		*table = NULL;
  t_ivec3		origin_int;
  t_ivec3		mask;
  t_vec3		origin;
  t_vec3		offset[2];
  t_vec3		det[4];
  t_vec3		dist_origin;
  int			grad[4];

  if (state == FREE)
    {
      if (table)
	my_free(table);
      table = NULL;
      return (0.0);
    }
  if (!table && !(table = perlin_3d_table()))
    return (0.0);
  simplex_calc_init(pos, &origin_int, &origin, (void *)&dist_origin,
		    (double)scale, 3);
  simplex_mask(&mask, &origin_int, 3);
  simplex_calc_offset(offset, &dist_origin, 3, DRAW);
  simplex_calc_det(det, &dist_origin, offset, 3);
  simplex_calc_grad(grad, &mask, &offset, perm, 3);
  return (simplex_calc_pixel(det, table, grad, 3));
}

static double		simplex_noise_4d(t_vec4 *pos, float scale,
					unsigned char *perm,
					t_perlin_state state)
{
  static t_vec4		*table = NULL;
  t_ivec4		origin_int;
  t_ivec4		mask;
  t_vec4		origin;
  t_vec4		offset[3];
  t_vec4		det[5];
  t_vec4		dist_origin;
  int			grad[5];

  if (state == FREE)
    {
      if (table)
	my_free(table);
      simplex_calc_offset(offset, &dist_origin, 4, FREE);
      return ((table = NULL), 0.0);
    }
  if (!table && !(table = perlin_4d_table()))
    return (0.0);
  simplex_calc_init(pos, &origin_int, &origin, (void *)&dist_origin,
		    (double)scale, 4);
  simplex_mask(&mask, &origin_int, 4);
  simplex_calc_offset(offset, &dist_origin, 4, DRAW);
  simplex_calc_det(det, &dist_origin, offset, 4);
  simplex_calc_grad(grad, &mask, &offset, perm, 4);
  return (simplex_calc_pixel(det, table, grad, 4));
}

double			simplex_noise(void *pos, float scale, int dim,
				      t_perlin_state state)
{
  static unsigned char	*permutation = NULL;

  if (state == FREE)
    {
      if (permutation)
	my_free(permutation);
      permutation = NULL;
      simplex_noise_2d(pos, scale, permutation, FREE);
      simplex_noise_3d(pos, scale, permutation, FREE);
      simplex_noise_4d(pos, scale, permutation, FREE);
      return (0.0);
    }
  if (!permutation && !(permutation = permutation_table()))
    return (0.0);
  if (dim == 2)
    return (simplex_noise_2d(pos, scale, permutation, DRAW));
  if (dim == 3)
    return (simplex_noise_3d(pos, scale, permutation, DRAW));
  if (dim == 4)
    return (simplex_noise_4d(pos, scale, permutation, DRAW));
  return (0.0);
}
