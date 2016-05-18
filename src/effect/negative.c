/*
** negative.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 13:19:26 2016 Antoine Baché
** Last update Wed May 18 13:21:41 2016 Antoine Baché
*/

#include <lapin.h>

void		negative_effect(t_color *pix, int height, int width)
{
  int		i;
  int		j;
  int		cur;

  i = 0;
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
