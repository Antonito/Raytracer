/*
** blit_scaled.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun May  8 01:17:03 2016 Ludovic Petrenko
** Last update Sun May  8 04:23:08 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include "engine/vector.h"

static char	mix(t_color **pix, t_ivec2 incr, double scale, int t,
		    t_bunny_pixelarray *src)
{
  int		full;
  int		total;
  t_ivec2	i;
  t_ivec2	s;
  t_vec3	c;

  i.y = incr.y - 1;
  s.y = 1;
  full = 0;
  total = 0;
  return (pix[0][(int)(incr.x / scale) + (int)(incr.y / scale)
		 * src->clipable.clip_width].argb[t]);

  if (scale > 1.0)
    {
      c.x = incr.x / scale + 0.5;
      c.x = c.x - (int)c.x;
      c.y = incr.y / scale + 0.5;
      c.y = c.y - (int)c.y;
      full =
	pix[0][(int)(incr.x / scale - 0.5) + (int)(incr.y / scale - 0.5)
	       * src->clipable.clip_width].argb[t] * (1 - c.x) * (1 - c.y) +
	pix[0][(int)(incr.x / scale + 0.5) + (int)(incr.y / scale - 0.5)
	       * src->clipable.clip_width].argb[t] * c.x * (1 - c.y) +
	pix[0][(int)(incr.x / scale - 0.5) + (int)(incr.y / scale + 0.5)
	       * src->clipable.clip_width].argb[t] * (1 - c.x) * c.y +
	pix[0][(int)(incr.x / scale + 0.5) + (int)(incr.y / scale + 0.5)
	       * src->clipable.clip_width].argb[t] * c.x * c.y;
      return (full);
    }
}

void		blit_scaled(t_bunny_pixelarray *src, t_bunny_pixelarray *dest)
{
  double	scale;
  t_ivec2	incr;
  unsigned int	*pix[2];
  int		i;

  scale = dest->clipable.clip_width / (double)src->clipable.clip_width;
  incr.y = -1;
  pix[0] = src->pixels;
  pix[1] = dest->pixels;
  while (++incr.y < dest->clipable.clip_height)
    {
      incr.x = -1;
      while (++incr.x < dest->clipable.clip_width)
	pix[1][incr.x + incr.y * dest->clipable.clip_width] =
	  pix[0][(int)(incr.x / scale) + (int)(incr.y / scale) *
		 src->clipable.clip_width];
    }
}
