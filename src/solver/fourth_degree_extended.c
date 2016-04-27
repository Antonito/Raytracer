/*
** fourth_degree_extended.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 16:52:24 2016 Antoine Baché
** Last update Wed Apr 27 22:35:31 2016 Antoine Baché
*/

#include <stdarg.h>
#include "tools/math.h"

void		quadratic_solution_det(double **det, double a, double b, ...)
{
  va_list	args;
  double	c;
  double	d;
  double	e;

  va_start(args, b);
  c = va_arg(args, double);
  d = va_arg(args, double);
  e = va_arg(args, double);
  va_end(args);
  *(det[0]) = c * c - 3 * b * d + 12 * a * e;
  *(det[1]) = 2 * c * c * c - 9 * b * c * d + 27 * b * b * e + 27 * a * d * d -
    72 * a * c * e;
  *(det[2]) = ((*(det[1])) * (*(det[1])) -
	       4 * (*(det[0])) * (*(det[0])) * (*(det[0]))) / (-27);
}

double		quadratic_solution_calc(double tmp[], double s)
{
  double	x[4];

  x[0] = tmp[0] - s + tmp[1];
  x[1] = tmp[0] - s - tmp[1];
  x[2] = tmp[0] + s + tmp[2];
  x[3] = tmp[0] + s - tmp[2];
  x[0] = CHECK_SOLUTION(x[0]);
  x[1] = CHECK_SOLUTION(x[1]);
  x[0] = check_solution_equation(x[0], x[1]);
  x[2] = CHECK_SOLUTION(x[2]);
  x[3] = CHECK_SOLUTION(x[3]);
  x[2] = check_solution_equation(x[2], x[3]);
  return (check_solution_equation(x[0], x[2]));
}
