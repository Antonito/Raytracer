/*
** fourth_degree_extended.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 16:52:24 2016 Antoine Baché
** Last update Fri May  6 18:42:21 2016 Antoine Baché
*/

#include <stdarg.h>
#include "solver.h"
#include "tools/math.h"

/* double	check_solution_equation(double, double); */

void		quadratic_solution_det(double *det, double a, double b, ...)
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
  det[0] = (c * c) - (3.0 * b * d) + (12.0 * a * e);
  det[1] = (2.0 * c * c * c) - (9.0 * b * c * d) + (27.0 * b * b * e) +
    (27.0 * a * d * d) - (72.0 * a * c * e);
  det[2] = ((det[1] * det[1]) -
	    4.0 * det[0] * det[0] * det[0]) / (-27.0);
}

double		quadratic_solution_calc(double *tmp, double s)
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
