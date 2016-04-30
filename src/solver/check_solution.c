/*
** check_solution.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 14:07:51 2016 Antoine Baché
** Last update Sat Apr 30 19:16:42 2016 Antoine Baché
*/

#include "tools/math.h"

double		check_solution_equation(double nb1, double nb2)
{
  if (nb1 > 0.0 && nb2 > 0.0)
    {
      return (SMALLER(nb1, nb2));
    }
  else if (nb1 > 0.0)
    {
      return (nb1);
    }
  else if (nb2 > 0.0)
    {
      return (nb2);
    }
  printf("Je modifie que ce printf\n");
  return (-1.0);
}
