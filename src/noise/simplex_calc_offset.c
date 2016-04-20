/*
** simplex_calc_offset.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 11:37:59 2016 Antoine Baché
** Last update Wed Apr 20 19:59:53 2016 Antoine Baché
*/

#include "noise.h"
#include "tools/memory.h"

static void		simplex_calc_offset_2d(t_vec2 *offset, t_vec2 *dist)
{
  if (dist->x > dist->y)
    {
      offset->x = 1;
      offset->y = 0;
    }
  else
    {
      offset->x = 0;
      offset->y = 1;
    }
}

static void		simplex_calc_offset_3d(t_vec3 *offset, t_vec3 *dist)
{
  if (dist->x >= dist->y)
    {
      offset[0].x = 1;
      offset[0].y = 0;
      offset[0].z = 0;
      simplex_calc_offset_3d_sup(offset, dist);
    }
  else
    {
      offset[1].x = 0;
      offset[1].y = 1;
      offset[1].z = 1;
      simplex_calc_offset_3d_inf(offset, dist);
    }
}

static void		simplex_calc_offset_4d(t_vec4 *offset, t_vec4 *dist,
					       t_perlin_state state)
{
  static t_ivec4	*table = NULL;

  if (state == FREE)
    {
      if (table)
	my_free(table);
      table = NULL;
      return ;
    }
  if (!table && !(table = simplex_calc_table_4d()))
    return ;
  simplex_calc_offset_4d_table(simplex_calc_index_4d(dist), table, offset);
}

void			simplex_calc_offset(void *offset, void *dist, int dim,
					    t_perlin_state state)
{
  if (dim == 2)
    simplex_calc_offset_2d(offset, dist);
  else if (dim == 3)
    simplex_calc_offset_3d(offset, dist);
  else if (dim == 4)
    simplex_calc_offset_4d(offset, dist, state);
}
