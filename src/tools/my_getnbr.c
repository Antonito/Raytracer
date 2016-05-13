/*
** my_getnbr.c for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 10:35:03 2016 Antoine Baché
** Last update Fri May 13 15:57:39 2016 Luka Boulagnon
*/

int	my_getnbr(const char *str)
{
  int	i;
  int	s;
  long	r;

  i = 0;
  s = 1;
  r = 0;
  while (str[i] == 43 || str[i] == 45)
    {
      if (str[i] == 45)
	s = -s;
      ++i;
    }
  str += i;
  i = 0;
  while (str[i] > 47 && str[i] < 58)
    {
      r = r * 10;
      r = r + str[i] - 48;
      ++i;
    }
  return (r > 2147483647 || r < -2147483648 ? 0 : s * r);
}
