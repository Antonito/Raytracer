/*
** simplex_calc_offset_next.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 11:45:19 2016 Antoine Baché
** Last update Wed Apr 20 20:00:51 2016 Antoine Baché
*/

#include "noise.h"

void		simplex_calc_offset_3d_sup(t_vec3 *offset, t_vec3 *dist)
{
  if (dist->y >= dist->z)
    {
      offset[1].x = 1;
      offset[1].y = 1;
      offset[1].z = 0;
    }
  else if (dist->x >= dist->z)
    {
      offset[1].x = 1;
      offset[1].y = 0;
      offset[1].z = 1;
    }
  else
    {
      offset[0].x = 0;
      offset[0].z = 1;
      offset[1].x = 1;
      offset[1].y = 0;
      offset[1].z = 1;
    }
}

void		simplex_calc_offset_3d_inf(t_vec3 *offset, t_vec3 *dist)
{
  if (dist->y < dist->z)
    {
      offset[0].x = 0;
      offset[0].y = 0;
      offset[0].z = 1;
    }
  else if (dist->x < dist->z)
    {
      offset[0].x = 0;
      offset[0].y = 1;
      offset[0].z = 0;
    }
  else
    {
      offset[0].x = 0;
      offset[0].y = 1;
      offset[0].z = 0;
      offset[1].x = 1;
      offset[1].y = 1;
      offset[1].z = 0;
    }
}

int		simplex_calc_index_4d(t_vec4 *dist)
{
  return (((dist->x > dist->y) ? 32 : 0) +
	  ((dist->x > dist->z) ? 16 : 0) +
	  ((dist->y > dist->z) ? 8 : 0) +
	  ((dist->x > dist->w) ? 4 : 0) +
	  ((dist->y > dist->w) ? 2 : 0) +
	  ((dist->z > dist->w) ? 1 : 0));
}

void		simplex_calc_offset_4d_table(int i, t_ivec4 *table, t_vec4 *off)
{
  off[0].x = ((table[i].x >= 3) ? 1 : 0);
  off[0].y = ((table[i].y >= 3) ? 1 : 0);
  off[0].z = ((table[i].z >= 3) ? 1 : 0);
  off[0].w = ((table[i].w >= 3) ? 1 : 0);
  off[1].x = ((table[i].x >= 2) ? 1 : 0);
  off[1].y = ((table[i].y >= 2) ? 1 : 0);
  off[1].z = ((table[i].z >= 2) ? 1 : 0);
  off[1].w = ((table[i].w >= 2) ? 1 : 0);
  off[2].x = ((table[i].x >= 1) ? 1 : 0);
  off[2].y = ((table[i].y >= 1) ? 1 : 0);
  off[2].z = ((table[i].z >= 1) ? 1 : 0);
  off[2].w = ((table[i].w >= 1) ? 1 : 0);
}
