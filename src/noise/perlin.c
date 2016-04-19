/*
** perlin.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:20:41 2016 Antoine Baché
** Last update Tue Apr 19 09:25:37 2016 Antoine Baché
*/

#include <unistd.h>
#include "noise.h"

static double		perlin_noise_2d(t_vec2 *pos, float scale,
					unsigned char *perm)
{
  static t_vec2		*table = NULL;
  t_ivec2		origin;
  t_mask2		mask;
  t_gradient2		gradient;

  if (!table)
    table = perlin_2d_table();
  perlin_calc_init(pos, &origin, &mask, scale, 2);
  calc_perlin_gradient(&gradient, &mask, perm, 2);
  return (0.0);
}

static double		perlin_noise_3d(t_vec3 *pos, float scale,
					unsigned char *perm)
{
  static t_vec3		*table = NULL;
  t_ivec3		origin;
  t_mask3		mask;
  t_gradient3		gradient;

  if (!table)
    table = perlin_3d_table();
  perlin_calc_init(pos, &origin, &mask, scale, 3);
  calc_perlin_gradient(&gradient, &mask, perm, 3);
  return (0.0);
}

static double		perlin_noise_4d(t_vec4 *pos, float scale,
					unsigned char *perm)
{
  static t_vec4		*table = NULL;
  t_ivec4		origin;
  t_mask4		mask;
  t_gradient4		gradient;

  if (!table)
    table = perlin_4d_table();
  perlin_calc_init(pos, &origin, &mask, scale, 4);
  calc_perlin_gradient(&gradient, &mask, perm, 4);
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
