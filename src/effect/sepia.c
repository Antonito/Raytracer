/*
** sepia.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 13:36:40 2016 Antoine Baché
** Last update Wed May 18 23:39:29 2016 Antoine Baché
*/

#include "raytracer.h"

void		sepia_effect(t_color *pix, int height, int width,
			     t_config *conf)
{
  int		i;
  int		j;
  int		cur;
  int		tmp;

  i = -1;
  (void)conf;
  while (++i < height && (j = -1))
    {
      while (++j < width && (cur = i * width + j) >= 0)
	{
	  tmp = ((double)pix[cur].argb[0] * 0.393) +
	    ((double)pix[cur].argb[1] * 0.769) +
	    ((double)pix[cur].argb[2] * 0.189);
	  pix[cur].argb[0] = (tmp > 255) ? 255 : tmp;
	  tmp = ((double)pix[cur].argb[0] * 0.349) +
	    ((double)pix[cur].argb[1] * 0.686) +
	    ((double)pix[cur].argb[2] * 0.168);
	  pix[cur].argb[1] = (tmp > 255) ? 255 : tmp;
	  tmp  = ((double)pix[cur].argb[0] * 0.272) +
	    ((double)pix[cur].argb[1] * 0.534) +
	    ((double)pix[cur].argb[2] * 0.131);
	  pix[cur].argb[2] = (tmp > 255) ? 255 : tmp;
	}
    }
}
