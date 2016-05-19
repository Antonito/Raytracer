/*
** pastel.c for Raytracer2 in /gfx_raytracer2/src/effect
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 13:16:08 2016 Antoine Baché
** Last update Thu May 19 06:29:19 2016 Antoine Baché
*/

#include "raytracer.h"
#include "tools/memory.h"

static bool	pastel_is_in_radius(t_ivec2 pos, t_ivec2 cur, int radius)
{
  return ((((cur.x - pos.x) * (cur.x - pos.x) + (cur.y - pos.y) *
	    (cur.y - pos.y)) < radius * radius) ? true : false);
}

static void	pastel_calc_intensity()
{

}

static void	pastel_get_current_max(int *current_max, int *max_id, int *count)
{
  int		i;

  i = 0;
  *current_max = 0;
  *max_id = 0;
  while (i < 256)
    {
      if (count[i] > (*current_max))
	{
	  (*current_max) = count[i];
	  (*max_id) = i;
	}
      ++i;
    }
}

void		pastel_effect(t_color *pix, int height, int width,
			      t_config *conf)
{

  int		i;
  int		j;
  int		cur;
  int		cur_max;
  t_color	*sum;
  int		intensity[256];
  int		max_index;

  conf->pastel.radius = 5;
  conf->pastel.level = 20;
  if (conf->pastel.radius >= height * width || !(i = -1) ||
      !(sum = my_calloc(height * width, sizeof(t_color))))
    return ;
  while (++i < height && (j = -1))
    while (++j < width && (cur = i * width + j) >= 0)
      {
	/* pastel_calc_intensity((t_color *[2]){sum, pix}, conf, (t_ivec2){j, i}, */
	/* 		      intensity); */
	pastel_get_current_max(&cur_max, &max_index, intensity);
	pix[cur].argb[0] = sum[max_index].argb[0] / ((!cur_max) ? 1 : cur_max);
	pix[cur].argb[1] = sum[max_index].argb[1] / ((!cur_max) ? 1 : cur_max);
	pix[cur].argb[2] = sum[max_index].argb[2] / ((!cur_max) ? 1 : cur_max);
      }
  my_free(sum);
}
