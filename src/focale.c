/*
** focale.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu May 19 06:35:26 2016 Antoine Baché
** Last update Fri May 20 23:57:12 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "tools/memory.h"

static void		new_gaussian_kernel(float kernel[7][7], int x, int y,
					    double sigma)
{
  int			i;
  int			j;
  double		middle;
  double		sum;

  i = -1;
  sum = 0;
  middle = x / 2.0;
  while (++i < y && (j = -1))
    while (++j < x)
      {
	kernel[i][j] = exp(-0.5 * ((i - middle) * (i - middle) +
				   (j - middle) * (j - middle)))
	  / (2.0 * M_PI * sigma * sigma);
	sum += kernel[i][j];
      }
  i = -1;
  while (++i < y && (j = -1))
    while (++j < x)
      kernel[i][j] /= sum;
}

static void		calc_gaussian_blur(t_data *data,
					   t_bunny_pixelarray *work, int cur)
{
  int			i;
  int			j;
  t_color		*rend;
  t_color		*tmp;
  float			kernel[7][7];

  new_gaussian_kernel(kernel, 7, 7, data->scene->zbuf[cur]);
  rend = data->render->pixels;
  tmp = work->pixels;
  i = 0;
  rend[cur].full = 0;
  while (i < 7)
    {
      j = 0;
      while (j < 7)
	{
	  rend[cur].full += tmp[cur].full * kernel[i][j];
	  ++j;
	}
      ++i;
    }
}

void				focale(t_data *data)
{
  int				cur;
  int				i;
  int				j;
  t_bunny_pixelarray		*tmp;

  return ;
  if (!(tmp = bunny_new_pixelarray(data->config.width, data->config.height)))
    return ;
  cpy_pixelarray(tmp, data->render, data->config.width, data->config.height);
  i = 0;
  while (i < data->config.height)
    {
      j = 0;
      while (j < data->config.width)
	{
	  cur = i * data->config.width + j;
	  if ((float)data->scene->cam.focale != data->scene->zbuf[cur])
	    calc_gaussian_blur(data, tmp, cur);
	  ++j;
	}
      ++i;
    }
  my_free(tmp);
}
