/*
** perlin.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:20:41 2016 Antoine Baché
** Last update Tue Apr 19 09:05:11 2016 Antoine Baché
*/

#include <unistd.h>
#include "noise.h"

static double		perlin_noise_2d(t_vec2 *pos, float scale,
					unsigned char *perm)
{
  static t_vec2		*table = NULL;
  t_vec2		origin;
  t_mask2		mask;
  t_gradient2		gradient;

  if (!table)
    table = perlin_2d_table();
  pos.x /= scale;
  pos.y /= scale;
  origin.x = (int)pos.x;
  origin.y = (int)pos.y;
  mask.x = origin.x & 255;
  mask.y = origin.y & 255;
  calc_perlin_gradient(&gradient, &mask, perm, 2);
  return (0.0);
}

static double		perlin_noise_3d(t_vec3 *pos, float scale,
					unsigned char *perm)
{
  static t_vec3		*table = NULL;
  t_vec3		origin;
  t_mask3		mask;
  t_gradient3		gradient;

  if (!table)
    table = perlin_3d_table();
  pos.x /= scale;
  pos.y /= scale;
  pos.z /= scale;
  origin.x = (int)pos.x;
  origin.y = (int)pos.y;
  origin.z = (int)pos.z;
  mask.x = origin.x & 255;
  mask.y = origin.y & 255;
  mask.z = origin.z & 255;
  calc_perlin_gradient(&gradient, &mask, perm, 3);
  return (0.0);
}

static double		perlin_noise_4d(t_vec4 *pos, float scale,
					unsigned char *perm)
{
  static t_vec4		*table = NULL;
  t_vec4		origin;
  t_mask4		mask;
  t_gradient4		gradient;

  if (!table)
    table = perlin_4d_table();
  pos.x /= scale;
  pos.y /= scale;
  pos.z /= scale;
  pos.w /= scale;
  origin.x = (int)pos.x;
  origin.y = (int)pos.y;
  origin.z = (int)pos.z;
  origin.w = (int)pos.w;
  mask.x = origin.x & 255;
  mask.y = origin.y & 255;
  mask.z = origin.z & 255;
  mask.w = origin.w & 255;
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
