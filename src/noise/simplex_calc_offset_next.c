/*
** simplex_calc_offset_next.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 11:45:19 2016 Antoine Baché
** Last update Wed Apr 20 11:53:25 2016 Antoine Baché
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
