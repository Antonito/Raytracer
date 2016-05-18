/*
** contrast.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 20:25:05 2016 Antoine Baché
** Last update Wed May 18 20:37:57 2016 Antoine Baché
*/

#include <lapin.h>

void		contrast_effect(t_color *pix, int height, int width)
{
  int		i;
  int		j;
  double	contrast;
  double       	new[3];
  int		cur;

  i = -1;
  contrast = (200.0 / 100.0) * (200.0 / 100.0);
  while (++i < height && (j = -1))
    while (++j < width)
      {
	cur = i * width + j;
	new[0] = (((((double)pix[cur].argb[0] / 255.0) - 0.5) * contrast)
		  + 0.5) * 255.0;
	new[1] = (((((double)pix[cur].argb[1] / 255.0) - 0.5) * contrast)
		  + 0.5) * 255.0;
	new[2] = (((((double)pix[cur].argb[2] / 255.0) - 0.5) * contrast)
		  + 0.5) * 255.0;
	new[0] = (new[0] > 255.0) ? 255.0 : (new[0] < 0.0) ? 0.0 : new[0];
	new[1] = (new[1] > 255.0) ? 255.0 : (new[1] < 0.0) ? 0.0 : new[1];
	new[2] = (new[2] > 255.0) ? 255.0 : (new[2] < 0.0) ? 0.0 : new[2];
	pix[cur].argb[0] = new[0];
	pix[cur].argb[1] = new[1];
	pix[cur].argb[2] = new[2];
      }
}
