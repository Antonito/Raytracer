/*
** second_degree.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:00:25 2016 Antoine Baché
** Last update Wed Apr 27 05:51:18 2016 Antoine Baché
*/

#include "solver.h"
#include "tools/math.h"

double		solver_second_degree(double a, double b, double c)
{
  double	res;
  double	det;
  double	tmp[4];

  det = b * b - 4 * a * c;
  if (det == 0)
    {
      res = -b / (2 * a);
    }
  else if (det > 0)
    {
      tmp[2] = fast_sqrt(det);
      tmp[3] = 2 * a;
      tmp[0] = (-b - tmp[2]) / tmp[3];
      tmp[1] = (-b + tmp[2]) / tmp[3];
      res = (tmp[0] < tmp[1]) ? tmp[0] : tmp[1];
    }
  else
    {
      res = NOT_A_SOLUTION;
    }
  return (res);
}
