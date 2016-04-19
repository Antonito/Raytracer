/*
** perlin_tables_4d.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:42:53 2016 Antoine Baché
** Last update Mon Apr 18 12:34:48 2016 Antoine Baché
*/

#include "tools/memory.h"
#include "engine/vector.h"
#include "tools/types.h"

void		perlin_4d_table_last(t_vec4 *table)
{
  table[28].x = -1.0;
  table[28].y = 1.0;
  table[28].z = 1.0;
  table[28].w = 0.0;
  table[29].x = -1.0;
  table[29].y = 1.0;
  table[29].z = -1.0;
  table[29].w = 0.0;
  table[30].x = -1.0;
  table[30].y = -1.0;
  table[30].z = 1.0;
  table[30].w = 0.0;
  table[31].x = -1.0;
  table[31].y = -1.0;
  table[31].z = -1.0;
  table[31].w = 0.0;
}
