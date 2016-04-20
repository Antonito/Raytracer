/*
** simplex_calc_table.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 19:07:47 2016 Antoine Baché
** Last update Wed Apr 20 20:03:49 2016 Antoine Baché
*/

#include "noise.h"
#include "tools/memory.h"

static void	simplex_calc_table_4d_fill_end(t_ivec4 *table)
{
  table[56].x = 2;
  table[56].y = 1;
  table[56].w = 3;
  table[60].x = 3;
  table[60].y = 1;
  table[60].w = 2;
  table[62].x = 3;
  table[62].y = 2;
  table[62].w = 1;
  table[63].x = 3;
  table[63].y = 2;
  table[63].z = 1;
}

static void	simplex_calc_table_4d_fill_more(t_ivec4 *table)
{
  table[32].x = 1;
  table[32].z = 2;
  table[32].w = 3;
  table[33].x = 1;
  table[33].z = 3;
  table[33].w = 2;
  table[37].x = 2;
  table[37].z = 3;
  table[37].w = 1;
  table[39].x = 2;
  table[39].y = 1;
  table[39].z = 3;
  table[48].x = 2;
  table[48].z = 1;
  table[48].w = 3;
  table[52].x = 3;
  table[52].z = 1;
  table[52].w = 2;
  table[53].x = 3;
  table[53].z = 2;
  table[53].w = 1;
  table[55].x = 3;
  table[55].y = 1;
  table[55].z = 2;
}

static void	simplex_calc_table_4d_fill(t_ivec4 *table)
{
  table[8].y = 2;
  table[8].z = 1;
  table[8].w = 3;
  table[10].y = 3;
  table[10].z = 1;
  table[10].w = 2;
  table[11].y = 3;
  table[11].z = 2;
  table[11].w = 1;
  table[15].x = 1;
  table[15].y = 3;
  table[15].z = 2;
  table[24].x = 1;
  table[24].y = 2;
  table[24].w = 3;
  table[26].x = 1;
  table[26].y = 3;
  table[26].w = 2;
  table[30].x = 2;
  table[30].y = 3;
  table[30].w = 1;
  table[31].x = 2;
  table[31].y = 3;
  table[31].z = 1;
}

t_ivec4		*simplex_calc_table_4d(void)
{
  t_ivec4	*table;

  if (!(table = my_calloc(64, sizeof(t_ivec4))))
    return (NULL);
  table[0].y = 1;
  table[0].z = 2;
  table[0].w = 3;
  table[1].y = 1;
  table[1].z = 3;
  table[1].w = 2;
  table[3].y = 2;
  table[3].z = 3;
  table[3].w = 1;
  table[7].x = 1;
  table[7].y = 2;
  table[7].z = 3;
  simplex_calc_table_4d_fill(table);
  simplex_calc_table_4d_fill_more(table);
  simplex_calc_table_4d_fill_end(table);
  return (table);
}
