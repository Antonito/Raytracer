/*
** pastel.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 13:16:08 2016 Antoine Baché
** Last update Sun May 22 23:56:30 2016 Luka Boulagnon
*/

#include <stdio.h>
#include "raytracer.h"
#include "tools/memory.h"
#include "tools/math.h"

static void			reinit_avg(int averages[][4], t_config *conf)
{
  int				i;
  int				j;

  i = conf->pastel.level;
  while (j = 4, i--)
    while (j--)
      averages[i][j] = 0;
}

static void			each_in_radius(t_config *conf,
					       t_bunny_position pix[2],
					       t_color *from,
					       int averages[][4])
{
  int				lvl;
  int				i;
  int				j;

  reinit_avg(averages, conf);
  i = -conf->pastel.radius - 1;
  while (j = -conf->pastel.radius - 1, ++i < conf->pastel.radius)
    while (++j < conf->pastel.radius)
      if ((i + pix->x) >= 0 && (i + pix->x) < pix[1].x
	  && (j + pix->y) >= 0 && (j + pix->y) < pix[1].y)
	{
	  lvl = (((double)(from[(j + pix->y) * pix[1].x + i + pix->x].argb[0]
			   + from[(j + pix->y) * pix[1].x + i + pix->x].argb[1]
			   + from[(j + pix->y) * pix[1].x + i + pix->x].argb[2])
		  / 3.0)) * (double)conf->pastel.level / 256.0;
	  averages[lvl][3]++;
	  averages[lvl][0] += from[(j + pix->y) * pix[1].x
	    + i + pix->x].argb[0];
	  averages[lvl][1] += from[(j + pix->y) * pix[1].x
	    + i + pix->x].argb[1];
	  averages[lvl][2] += from[(j + pix->y) * pix[1].x
	    + i + pix->x].argb[2];
	}
}

static void			filler(t_config *conf, t_bunny_position pix[2],
				       t_color *to, int averages[][4])
{
  double			max;
  double			max_index;
  int				i;

  i = conf->pastel.level;
  max = 1;
  max_index = 0;
  while (i--)
    if (max < averages[i][3])
      {
	max = averages[i][3];
	max_index = i;
      }
  to[pix->y * pix[1].x + pix->x].argb[0] = averages[(int)max_index][0] / max;
  to[pix->y * pix[1].x + pix->x].argb[1] = averages[(int)max_index][1] / max;
  to[pix->y * pix[1].x + pix->x].argb[2] = averages[(int)max_index][2] / max;
}

void		pastel_effect(t_color *pix, int height, int width,
			      t_config *conf)
{
  int		averages[conf->pastel.level][4];
  int		x;
  int		y;
  t_color	*sum;

  if (conf->pastel.radius >= height * width || !(x = -1) ||
      !(sum = my_calloc(height * width, sizeof(t_color))))
    return ;
  while (y = -1, ++x < width)
    while (++y < height)
      {
	each_in_radius(conf, (t_bunny_position []){{x, y}, {width, height}},
		       pix, averages);
	filler(conf, (t_bunny_position []){{x, y}, {width, height}},
	       sum, averages);
      }
  y = width * height;
  while (y--)
    pix[y].full = sum[y].full;
  my_free(sum);
}
