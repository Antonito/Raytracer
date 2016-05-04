/*
** second_degree.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:00:25 2016 Antoine Baché
** Last update Tue May  3 15:31:05 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "tools/math.h"

double		solver_second_degree(double a, double b, double c)
{
  double	res;
  double	det;
  double	tmp[4];

  det = b * b - 4.0 * a * c;
  if (det == 0.0)
    {
      res = -b / (2.0 * a);
      res = CHECK_SOLUTION(res);
    }
  else if (det > 0.0)
    {
      tmp[2] = sqrt(det);
      tmp[3] = 2.0 * a;
      tmp[0] = (-b - tmp[2]) / tmp[3];
      tmp[1] = (-b + tmp[2]) / tmp[3];
      tmp[0] = CHECK_SOLUTION(tmp[0]);
      tmp[1] = CHECK_SOLUTION(tmp[1]);
      res = check_solution_equation(tmp[0], tmp[1]);
    }
  else
    {
      res = NOT_A_SOLUTION;
    }
  return (res);
}
