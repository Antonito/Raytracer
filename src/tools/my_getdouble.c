/*
** my_getdouble.c for Raytracer2 in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:13:21 2016 Antoine Baché
** Last update Mon Apr 18 11:18:21 2016 Antoine Baché
*/

#include "tools/memory.h"
#include "tools/str.h"

int		my_power(int nb, const int exp)
{
  int		i;

  i = 0;
  while (++i < exp)
    nb *= nb;
  return (nb);
}

static void	remove_comma(const char *str, char *tmp)
{
  int		i;

  i = -1;
  while (str[++i] != '\0')
    tmp[i] = str[i];
  tmp[i] = '\0';
  i = -1;
  while (tmp[++i] != '.');
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
  while (str[++i] != '.' && str[i] != '\0');
  if (str[i] == '\0')
    return (0);
  while (str[i] != '\0' && ++i && ++k);
  if (!(tmp = my_malloc(my_strlen(str) + 1)))
    return (1);
  remove_comma(str, tmp);
  k -= 1;
  res = ((k) ? (double)my_getnbr(tmp) / my_power(10, k) : my_getnbr(tmp));
  my_free(tmp);
  return (res);
}
