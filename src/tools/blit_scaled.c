/*
** blit_scaled.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun May  8 01:17:03 2016 Ludovic Petrenko
** Last update Sun May 22 19:03:09 2016 Ludovic Petrenko
*/

#include <lapin.h>
#include "engine/vector.h"

void		blit_scaled(t_bunny_pixelarray *src, t_bunny_pixelarray *dest)
{
  double	scale;
  t_ivec2	incr;
  unsigned int	*pix[2];

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
