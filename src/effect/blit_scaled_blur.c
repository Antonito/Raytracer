/*
** blit_scaled_blur.c for Raytracer2 in /semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun May 22 20:01:03 2016 Ludovic Petrenko
** Last update Sun May 22 22:57:32 2016 Antoine Baché
*/

#include "raytracer.h"
#include "tools/math.h"

static t_color	avg_color(t_bunny_pixelarray *pix, t_ivec2 pos, int ratio)
{
  t_ivec2	i;
  unsigned int	full[3];
  t_color	tmp;
  t_color	*p;
  int		total;

  p = pix->pixels;
  full[0] = full[1] = full[2] = total = 0;
  i.y = -1;
  while (++i.y < ratio)
    {
      i.x = -1;
      while (++i.x < ratio)
	{
	  tmp = p[pos.x + i.x + (pos.y + i.y) * pix->clipable.clip_width];
	  full[0] += tmp.argb[0];
	  full[1] += tmp.argb[1];
	  full[2] += tmp.argb[2];
	  ++total;
	}
    }
  tmp.argb[0] = full[0] / MAX(total, 1);
  tmp.argb[1] = full[1] / MAX(total, 1);
  tmp.argb[2] = full[2] / MAX(total, 1);
  return (tmp);
}

int		blit_scaled_blur(t_bunny_pixelarray *src,
				 t_bunny_pixelarray *dest,
				 int ratio)
{
  t_ivec2	i;
  t_color	*d;

  d = dest->pixels;
  i.y = -1;
  while (++i.y < dest->clipable.clip_height)
    {
      i.x = -1;
      while (++i.x < dest->clipable.clip_width)
	d[i.x + i.y * dest->clipable.clip_width] =
	  avg_color(src, (t_ivec2){i.x * ratio, i.y * ratio}, ratio);
    }
  return (0);
}
