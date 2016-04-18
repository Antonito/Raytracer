/*
** perlin.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:20:41 2016 Antoine Baché
** Last update Mon Apr 18 12:45:44 2016 Antoine Baché
*/

#include <unistd.h>
#include "noise.h"

static double  	perlin_noise_2d(t_vec2 *pos, float scale)
{
  static t_vec2	*table = NULL;

  if (!table)
    table = perlin_2d_table();
  return (0.0);
}

static double  	perlin_noise_3d(t_vec3 *pos, float scale)
{
  static t_vec3	*table = NULL;

  if (!table)
    table = perlin_3d_table();
  return (0.0);
}

static double  	perlin_noise_4d(t_vec4 *pos, float scale)
{
  static t_vec4	*table = NULL;

  if (!table)
    table = perlin_4d_table();
  return (0.0);
}

double		perlin_noise(void *pos, float scale, int dim)
{
  if (dim == 2)
    return (perlin_noise_2d(pos, scale));
  if (dim == 3)
    return (perlin_noise_3d(pos, scale));
  if (dim == 4)
    return (perlin_noise_4d(pos, scale));
#ifdef	DEBUG
  write(2, "Incorrect dimmension\n", 21);
#endif
  return (0.0);
}
