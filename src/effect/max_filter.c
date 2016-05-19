/*
** max_filter.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 17:22:59 2016 Antoine Baché
** Last update Thu May 19 01:22:28 2016 Antoine Baché
*/

#include "raytracer.h"

void		calc_neighbourhood(t_ivec2 pos, t_ivec2 size, int *nb_neighbours)
{
  unsigned int	neighbour[8];

  if (!pos.x)
    ;
  if (!pos.y)
    ;
  if (pos.x == size.x - 1)
    ;
  if (pos.y == size.y - 1)
    ;
}

void		calc_det_minmax(t_ivec2 size, unsigned int *minmax,
				int neighbours)
{
  int		i;

  i = -1;
  while (++i < neighbours)
    {

    }
}

void		max_filter_effect(t_color *pix, int height, int width,
				  t_config *conf)
{
  int		i;
  int		j;
  int		cur;
  int		nb_neighbours;
  unsigned int	minmax[2];

  i = 0;
  (void)conf;
  while (i < height)
    {
      j = 0;
      while (j < width)
	{
	  cur = i * width + j;
	  calc_neighbourhood((t_ivec2){j, i}, (t_ivec2){width, height},
			     &nb_neighbours);
	  calc_det_minmax((t_ivec2){width, height}, minmax, nb_neighbours);
	  pix[cur].full = minmax[1] - minmax[0];
	  ++j;
	}
      ++i;
    }
}
