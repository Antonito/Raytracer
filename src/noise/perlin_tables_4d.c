/*
** perlin_tables_4d.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:42:53 2016 Antoine Baché
** Last update Mon Apr 18 12:36:26 2016 Antoine Baché
*/

#include "tools/memory.h"
#include "noise.h"

static void	perlin_4d_table_end(t_vec4 *table)
{
  table[22].x = -1.0;
  table[22].y = -1.0;
  table[22].z = 0.0;
  table[22].w = 1.0;
  table[23].x = -1.0;
  table[23].y = -1.0;
  table[23].z = 0.0;
  table[23].w = -1.0;
  table[24].x = 1.0;
  table[24].y = 1.0;
  table[24].z = 1.0;
  table[24].w = 0.0;
  table[25].x = 1.0;
  table[25].y = 1.0;
  table[25].z = -1.0;
  table[25].w = 0.0;
  table[26].x = 1.0;
  table[26].y = -1.0;
  table[26].z = 1.0;
  table[26].w = 0.0;
  table[27].x = 1.0;
  table[27].y = -1.0;
  table[27].z = -1.0;
  table[27].w = 0.0;
}

static void	perlin_4d_table_middle_next(t_vec4 *table)
{
  table[16].x = 1.0;
  table[16].y = 1.0;
  table[16].z = 0.0;
  table[16].w = 1.0;
  table[17].x = 1.0;
  table[17].y = 1.0;
  table[17].z = 0.0;
  table[17].w = -1.0;
  table[18].x = 1.0;
  table[18].y = -1.0;
  table[18].z = 0.0;
  table[18].w = 1.0;
  table[19].x = 1.0;
  table[19].y = -1.0;
  table[19].z = 0.0;
  table[19].w = -1.0;
  table[20].x = -1.0;
  table[20].y = 1.0;
  table[20].z = 0.0;
  table[20].w = 1.0;
  table[21].x = -1.0;
  table[21].y = 1.0;
  table[21].z = 0.0;
  table[21].w = -1.0;
  perlin_4d_table_end(table);
}

static void	perlin_4d_table_middle(t_vec4 *table)
{
  table[10].x = 1.0;
  table[10].y = 0.0;
  table[10].z = -1.0;
  table[10].w = 1.0;
  table[11].x = 1.0;
  table[11].y = 0.0;
  table[11].z = -1.0;
  table[11].w = -1.0;
  table[12].x = -1.0;
  table[12].y = 0.0;
  table[12].z = 1.0;
  table[12].w = 1.0;
  table[13].x = -1.0;
  table[13].y = 0.0;
  table[13].z = 1.0;
  table[13].w = -1.0;
  table[14].x = -1.0;
  table[14].y = 0.0;
  table[14].z = -1.0;
  table[14].w = 1.0;
  table[15].x = -1.0;
  table[15].y = 0.0;
  table[15].z = -1.0;
  table[15].w = -1.0;
  perlin_4d_table_middle_next(table);
}

static void	perlin_4d_table_next(t_vec4 *table)
{
  table[4].x = 0.0;
  table[4].y = -1.0;
  table[4].z = 1.0;
  table[4].w = 1.0;
  table[5].x = 0.0;
  table[5].y = -1.0;
  table[5].z = 1.0;
  table[5].w = -1.0;
  table[6].x = 0.0;
  table[6].y = -1.0;
  table[6].z = -1.0;
  table[6].w = 1.0;
  table[7].x = 0.0;
  table[7].y = -1.0;
  table[7].z = -1.0;
  table[7].w = -1.0;
  table[8].x = 1.0;
  table[8].y = 0.0;
  table[8].z = 1.0;
  table[8].w = 1.0;
  table[9].x = 1.0;
  table[9].y = 0.0;
  table[9].z = 1.0;
  table[9].w = -1.0;
  perlin_4d_table_middle(table);
}

t_vec4		*perlin_4d_table(void)
{
  t_vec4	*table;

  if (!(table = my_malloc(sizeof(t_vec4) * 32)))
    return (NULL);
  table[0].x = 0.0;
  table[0].y = 1.0;
  table[0].z = 1.0;
  table[0].w = 1.0;
  table[1].x = 0.0;
  table[1].y = 1.0;
  table[1].z = 1.0;
  table[1].w = -1.0;
  table[2].x = 0.0;
  table[2].y = 1.0;
  table[2].z = -1.0;
  table[2].w = 1.0;
  table[3].x = 0.0;
  table[3].y = 1.0;
  table[3].z = -1.0;
  table[3].w = -1.0;
  perlin_4d_table_next(table);
  perlin_4d_table_last(table);
  return (table);
}
