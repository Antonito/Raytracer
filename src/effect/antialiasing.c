/*
** antialiasing.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 05:06:37 2016 Antoine Baché
** Last update Sun May 22 18:56:49 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "effect.h"
#include "tools/memory.h"
#include "tools/types.h"

static void		antialiase_reduce(t_bunny_pixelarray *src,
					  t_color *new, int ratio,
					  t_ivec2 incr)
{
  int			cur;
  t_color		*big;
  int			i;
  int			j;
  int			tmp[3];

  big = src->pixels;
  i = tmp[0] = tmp[1] = tmp[2] = 0;
  cur = (incr.x / ratio) * src->clipable.clip_width + (incr.y / ratio);
  while (i < ratio && (j = 0))
    {
      while (j < ratio)
	{
	  tmp[0] += big[incr.y + i + (incr.x + j) *
			src->clipable.clip_width].argb[0];
	  tmp[1] += big[incr.y + i + (incr.x + j) *
			src->clipable.clip_width].argb[1];
	  tmp[2] += big[incr.y + i + (incr.x + j) *
			src->clipable.clip_width].argb[2];
	  ++j;
	}
      ++i;
    }
  new[cur].argb[0] = tmp[0] / ratio;
  new[cur].argb[1] = tmp[1] / ratio;
  new[cur].argb[2] = tmp[2] / ratio;
}

static void		antialiase_it(t_bunny_pixelarray *dest,
				      t_bunny_pixelarray *src, int ratio)
{
  int			tmp[3];
  int			cur;
  t_ivec2		incr;
  int			i;
  int			j;

  incr.y = 0;
  while (incr.y < src->clipable.clip_height)
    {
      incr.x = 0;
      while (incr.x < src->clipable.clip_width)
	{
	  antialiase_reduce(src, dest->pixels, ratio, incr);
	  incr.x += ratio;
	}
      incr.y += ratio;
    }
}

int			antialiasing(t_bunny_pixelarray *pix, int ratio)
{
  t_bunny_pixelarray	*new;

  if (!(new = bunny_new_pixelarray(pix->clipable.clip_width * ratio,
				   pix->clipable.clip_width * ratio)))
    return (1);
  return (0);
  blit_scaled(pix, new);
  bunny_delete_clipable(&new->clipable);
}
