/*
** permutation_table.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 12:43:11 2016 Antoine Baché
** Last update Mon Apr 18 15:19:43 2016 Antoine Baché
*/

#include "tools/memory.h"

void		fill_permutation_table(unsigned char *table,
				       int loop)
{
  static unsigned char	*ref = NULL;

  if (!ref && !(ref = my_malloc(sizeof(unsigned char) * 16)))
    return ;
  generate_ref(ref, loop);
  table[0 + (loop * 16)] = ref[0];
  table[1 + (loop * 16)] = ref[1];
  table[2 + (loop * 16)] = ref[2];
  table[3 + (loop * 16)] = ref[3];
  table[4 + (loop * 16)] = ref[4];
  table[5 + (loop * 16)] = ref[5];
  table[6 + (loop * 16)] = ref[6];
  table[7 + (loop * 16)] = ref[7];
  table[8 + (loop * 16)] = ref[8];
  table[9 + (loop * 16)] = ref[9];
  table[10 + (loop * 16)] = ref[10];
  table[11 + (loop * 16)] = ref[11];
  table[12 + (loop * 16)] = ref[12];
  table[13 + (loop * 16)] = ref[13];
  table[14 + (loop * 16)] = ref[14];
  table[15 + (loop * 16)] = ref[15];
  if (loop < 15)
    fill_permutation_table(table, loop + 1);
  else
    my_free(ref);
}

/* void		fill_permutation_table(unsigned char *table) */
/* { */
/*   table[0]= 151; */
/*   table[1]= 160; */
/*   table[2]= 137; */
/*   table[3]= 91; */
/*   table[4]= 90; */
/*   table[5]= 15; */
/*   table[6]= 131; */
/*   table[7]= 13; */
/*   table[8]= 201; */
/*   table[9]= 95; */
/*   table[10]= 96; */
/*   table[11]= 53; */
/*   table[12]= 194; */
/*   table[13]= 233; */
/*   table[14]= 7; */
/*   table[15]= 225; */
/*   table[16]= 140; */
/*   table[17]= 36; */
/*   table[18]= 103; */
/*   table[19]= 30; */
/*   table[20]= 69; */
/*   table[21]= 142; */
/*   table[22]= 8; */
/*   table[23]= 99; */
/*   fill_permutation_table_more(); */
/* } */

unsigned char	*permutation_table(void)
{
  unsigned char	*table;
  unsigned char	*tmp;
  int		i;

  if (!(table = my_malloc(sizeof(unsigned char) * 512)) ||
      !(tmp = my_malloc(sizeof(unsigned char) * 256)))
    return (NULL);
  i = 0;
  fill_permutation_table(tmp);
  while (i < 256)
    table[i++] = tmp & 255;
  return (table);
}
