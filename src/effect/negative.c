/*
** negative.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 13:19:26 2016 Antoine Baché
** Last update Wed May 18 23:37:59 2016 Antoine Baché
*/

#include "raytracer.h"

void		negative_effect(t_color *pix, int height, int width,
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
	  pix[cur].full ^= 0x00FFFFFF;
	  ++j;
	}
      ++i;
    }
}
