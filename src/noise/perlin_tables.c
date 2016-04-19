/*
** perlin_tables.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:42:53 2016 Antoine Baché
** Last update Mon Apr 18 12:06:52 2016 Antoine Baché
*/

#include "tools/memory.h"
#include "engine/vector.h"
#include "tools/types.h"

t_vec2		*perlin_2d_table(void)
{
  t_vec2	*table;

  if (!(table = my_malloc(sizeof(t_vec2) * 8)))
    return (NULL);
  table[0].x = 1.0;
  table[0].y = 1.0;
  table[1].x = -1.0;
  table[1].y = 1.0;
  table[2].x = 1.0;
  table[2].y = -1.0;
  table[3].x = -1.0;
  table[3].y = -1.0;
  table[4].x = 1.0;
  table[4].y = 0.0;
  table[5].x = -1.0;
  table[5].y = 0.0;
  table[6].x = 0.0;
  table[6].y = 1.0;
  table[7].x = 0.0;
  table[7].y = -1.0;
  return (table);
}

static void	perlin_3d_table_next(t_vec3 *table)
{
  table[5].x = -1.0;
  table[5].y = 0.0;
  table[5].z = 1.0;
  table[6].x = 1.0;
  table[6].y = 0.0;
  table[6].z = -1.0;
  table[7].x = -1.0;
  table[7].y = 0.0;
  table[7].z = -1.0;
  table[8].x = 0.0;
  table[8].y = 1.0;
  table[8].z = 1.0;
  table[9].x = 0.0;
  table[9].y = -1.0;
  table[9].z = 1.0;
  table[10].x = 0.0;
  table[10].y = 1.0;
  table[10].z = -1.0;
  table[11].x = 0.0;
  table[11].y = -1.0;
  table[11].z = -1.0;
}

static void	perlin_3d_table_end(t_vec3 *table)
{
  table[12].x = 1.0;
  table[12].y = 1.0;
  table[12].z = 0.0;
  table[13].x = -1.0;
  table[13].y = 1.0;
  table[13].z = 0.0;
  table[14].x = 0.0;
  table[14].y = -1.0;
  table[14].z = 1.0;
  table[15].x = 0.0;
  table[15].y = -1.0;
  table[15].z = -1.0;
}

t_vec3		*perlin_3d_table(void)
{
  t_vec3	*table;

  if (!(table = my_malloc(sizeof(t_vec3) * 16)))
    return (NULL);
  table[0].x = 1.0;
  table[0].y = 1.0;
  table[0].z = 0.0;
  table[1].x = -1.0;
  table[1].y = 1.0;
  table[1].z = 0.0;
  table[2].x = 1.0;
  table[2].y = -1.0;
  table[2].z = 0.0;
  table[3].x = -1.0;
  table[3].y = -1.0;
  table[3].z = 0.0;
  table[4].x = 1.0;
  table[4].y = 0.0;
  table[4].z = 1.0;
  perlin_3d_table_next(table);
  perlin_3d_table_end(table);
  return (table);
}
