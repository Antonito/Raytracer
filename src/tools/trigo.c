/*
** trigo.c for Raytracer2 in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 10 09:12:24 2016 Antoine Baché
** Last update Tue May 10 09:54:18 2016 Antoine Baché
*/

#include <stdlib.h>
#include <math.h>
#include "tools/math.h"
#include "tools/memory.h"

static double		*set_sinuses(void)
{
  int			i;
  double		angle;
  double		*sinuses;

  if (!(sinuses = my_malloc(sizeof(double) * NB_TRIGO)))
    return (NULL);
  i = 0;
  angle = 0;
  while (i < NB_TRIGO)
    {
      sinuses[i] = sin(angle);
      angle += M_PI / (NB_TRIGO / 2);
      ++i;
    }
  return (sinuses);
}

static double		*set_cosinuses(void)
{
  int			i;
  double		angle;
  double		*cosinuses;

  if (!(cosinuses = my_malloc(sizeof(double) * NB_TRIGO)))
    return (NULL);
  i = 0;
  angle = 0;
  while (i < NB_TRIGO)
    {
      cosinuses[i] = cos(angle);
      angle += M_PI / (NB_TRIGO / 2);
      ++i;
    }
  return (cosinuses);
}

static int		get_val(double nb)
{
  int			value;

  value = nb * (NB_TRIGO / 2);
  value %= NB_TRIGO;
  while (value < 0)
    value += NB_TRIGO;
  return (value);
}

double			my_sin(double nb, t_trigo_state mode)
{
  static double		*sinuses = NULL;

  if (!sinuses)
    {
      sinuses = set_sinuses();
    }
  else if (mode == FREE)
    {
      my_free(sinuses);
      sinuses = NULL;
    }
  else
    return (sinuses[get_val(nb)]);
  return (0.0);
}

double			my_cos(double nb, t_trigo_state mode)
{
  static double		*cosinuses = NULL;

  if (!cosinuses)
    {
      cosinuses = set_cosinuses();
    }
  else if (mode == FREE)
    {
      my_free(cosinuses);
      cosinuses = NULL;
    }
  else
    return (cosinuses[get_val(nb)]);
  return (0.0);
}
