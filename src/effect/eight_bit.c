/*
** eight_bit.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 14:23:04 2016 Antoine Baché
** Last update Wed May 18 23:37:51 2016 Antoine Baché
*/

#include "raytracer.h"

#pragma message("Not implemented")
void		eight_bit_effect(t_color *pix, int height, int width,
				 t_config *conf)
{
  int		i;
  int		j;
  int		cur;

  i = 0;
  (void)conf;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  cur = i * width + j;
	  ++j;
	}
      ++i;
    }
}
