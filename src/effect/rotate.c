/*
** rotate.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 18:36:22 2016 Antoine Baché
** Last update Wed May 18 20:02:50 2016 Antoine Baché
*/

#include <math.h>
#include <lapin.h>
#include "raytracer.h"
#include "tools/memory.h"
#include "tools/str.h"
#include "tools/types.h"
#include "tools/math.h"

static int	rotate_effect_new_pos(t_ivec2 pos, int height, int width,
				      double rot)
{
  int		x;
  int		y;

  x = (int)round(((double)pos.x - ((double)width)) * my_cos(rot, DRAW) -
		 ((double)pos.y - ((double)height)) * my_sin(rot, DRAW) +
		 ((double)width));
  y = (int)round(((double)pos.x - ((double)width)) * my_sin(rot, DRAW) +
		 ((double)pos.y - ((double)height)) * my_cos(rot, DRAW) +
		 ((double)height));
  return (x + y * (width * 2));
}

static void	rotate_fill_effect(t_color *pix, t_color *new, int h, int w)
{
  int		i;
  int		j;
  int		cur;

  i = 0;
  while (i < h)
    {
      j = 0;
      while (j < w)
	{
	  cur = i * w + j;
	  pix[cur].argb[0] = new[cur].argb[0];
	  pix[cur].argb[1] = new[cur].argb[1];
	  pix[cur].argb[2] = new[cur].argb[2];
	  ++j;
	}
      ++i;
    }
  my_free(new);
}

void		rotate_effect(t_color *pix, int height, int width)
{
  int		i;
  int		j;
  int		max;
  t_color	*new_color;
  int		new[3];
  int		cur;

  i = -1;
  max = width * height;
  if (!(new_color = my_calloc(max, sizeof(t_color))))
    return ;
  while ((j = -1) && ++i < height)
    while (++j < width && (cur = i * width + j) >= 0)
      {
	new[0] = rotate_effect_new_pos((t_ivec2){j, i}, height / 2, width / 2,
				       1.0 * M_PI / 180.0);
	new[1] = rotate_effect_new_pos((t_ivec2){j, i}, height / 2, width / 2,
				       1.3 * M_PI / 180.0);
	new[2] = rotate_effect_new_pos((t_ivec2){j, i}, height / 2, width / 2,
				       1.5 * M_PI / 180.0);
	new_color[cur].argb[0] = pix[(new[0] > 0) ? new[0] % max : cur].argb[0];
	new_color[cur].argb[1] = pix[(new[1] > 0) ? new[1] % max : cur].argb[1];
	new_color[cur].argb[2] = pix[(new[2] > 0) ? new[2] % max : cur].argb[2];
      }
  rotate_fill_effect(pix, new_color, height, width);
}
