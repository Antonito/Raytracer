/*
** antialiasing.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 05:06:37 2016 Antoine Baché
** Last update Sun May 22 22:43:02 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "effect.h"
#include "tools/memory.h"
#include "tools/types.h"
#include "tools/math.h"

static t_color	avg_color(t_color *p, t_ivec2 pos, int ratio, t_ivec2 size)
{
  int		total;
  t_ivec2	i;
  unsigned int	full[3];
  t_color	tmp;

  ratio /= 2;
  full[0] = full[1] = full[2] = total = 0;
  i.y = MAX(pos.y - ratio - 1, 0);
  while (++i.y < pos.y + ratio && i.y < size.y)
    {
      i.x = MAX(pos.x - ratio - 1, 0);
      while (++i.x < pos.x + ratio && i.x < size.x)
	{
	  tmp = p[i.x + i.y * size.x];
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

static void	blur_it(t_bunny_pixelarray *sharp,
			t_bunny_pixelarray *blur, int ratio)
{
  t_ivec2	i;
  t_color	*s;
  t_color	*b;
  t_ivec2	size;

  s = sharp->pixels;
  b = blur->pixels;
  i.y = -1;
  size.x = blur->clipable.clip_width;
  size.y = blur->clipable.clip_height;
  while (++i.y < size.y)
    {
      i.x = -1;
      while (++i.x < size.x)
	b[i.x + i.y * size.x] =
	  avg_color(s, i, 2 * ratio, size);
    }
}



void			antialiasing(t_bunny_pixelarray *pix, int ratio)
{
  t_bunny_pixelarray	*new;
  t_bunny_pixelarray	*blur;

  if (!(new = bunny_new_pixelarray(pix->clipable.clip_width * ratio,
				   pix->clipable.clip_width * ratio)) ||
      !(blur = bunny_new_pixelarray(pix->clipable.clip_width * ratio,
				   pix->clipable.clip_width * ratio)))
    return ;
  blit_scaled(pix, new);
  blur_it(new, blur, ratio);
  blit_scaled_blur(blur, pix, ratio);
  bunny_delete_clipable(&new->clipable);
  bunny_delete_clipable(&blur->clipable);
}
