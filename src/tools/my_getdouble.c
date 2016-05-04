/*
** my_getdouble.c for Raytracer2 in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:13:21 2016 Antoine Baché
** Last update Wed May  4 07:13:03 2016 Ludovic Petrenko
*/

#include "tools/memory.h"
#include "tools/str.h"

int		my_power(int nb, const int exp)
{
  int		i;
  int		res;

  i = 0;
  res = 1;
  while (++i < exp)
    res *= nb;
  return (res);
}

static void	remove_comma(const char *str, char *tmp)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    tmp[i] = str[i];
  tmp[i] = '\0';
  i = -1;
  while (tmp[++i] != '.' && tmp[i]);
  while (tmp[i] != '\0')
    {
      tmp[i] = tmp[i + 1];
      i++;
    }
}

double		my_getdouble(const char *str)
{
  int		i;
  int		k;
  double	res;
  char		*tmp;

  if (!str)
    return (0);
  i = -1;
  k = 0;
  while (str[i] != '\0' && ++i && ++k);
  if (!(tmp = my_malloc(my_strlen(str) + 1)))
    return (1);
  remove_comma(str, tmp);
  k -= 1;
  res = ((k) ? (double)my_getnbr(tmp) / my_power(10, k) : my_getnbr(tmp));
  my_free(tmp);
  return (res);
}
