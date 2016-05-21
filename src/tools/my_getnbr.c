/*
** my_getnbr.c for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 10:35:03 2016 Antoine Baché
** Last update Sat May 21 22:35:33 2016 Arthur ARNAUD
*/

int	my_getnbr(const char *str)
{
  int	i;
  int	s;
  long	r;

  if (!str)
    return (0);
  s = 1;
  r = 0;
  i = -1;
  while (str[++i] == '-' || str[i] == '+')
    if (str[i] == '-')
      s = -s;
  str += i;
  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      r = r * 10;
      r = r + str[i] - 48;
      ++i;
    }
  return (s * r);
}
