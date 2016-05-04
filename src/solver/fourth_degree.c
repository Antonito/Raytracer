/*
** fourth_degree.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:18:12 2016 Antoine Baché
** Last update Mon May  2 01:58:19 2016 Antoine Baché
*/

#include <stdarg.h>
#include "solver.h"
#include "tools/math.h"

static void	quadratic_solution_pq(double *p, double *q, double a, ...)
{
  va_list	args;
  double	b;
  double	c;
  double	d;

  va_start(args, a);
  b = va_arg(args, double);
  c = va_arg(args, double);
  d = va_arg(args, double);
  va_end(args);
  (*p) = ((8.0 * a * c) - (3.0 * b * b)) / (8.0 * a * a);
  (*q) = ((b * b * b) - (4.0 * a * b * c) + (8.0 * a * a * d)) /
    (8.0 * a * a * a);
}

static double	quadratic_solution_det_pos(double p, double det0, double det1,
					   double a)
{
  return ((1.0 / 2.0) * sqrt((-(2.0 / 3.0) * p) +
			     ((2.0 / (3.0 * a)) * sqrt(det0) *
			      cos((acos(det1 /
					(2.0 * sqrt(det0 * det0 *
						    det0))))) /
			      3.0)));
}

static double	solver_fourth_solve(double val, double s, double p, double q)
{
  double	tmp[3];

  tmp[0] = val;
  tmp[1] = (1.0 / 2.0) * sqrt(-4.0 * s * s - 2.0 * p + (q / s));
  tmp[2] = (1.0 / 2.0) * sqrt(-4.0 * s * s - 2.0 * p - (q / s));
  return (quadratic_solution_calc(tmp, s));
}

static double	solver_fourth_calc_s(double *values)
{
  double	Q;
  double	s;

  if (values[2] != 0.0 && values[0] == 0.0)
    values[1] = sqrt(values[1] * values[1]);
  Q = CUBIC_ROOT((values[1] + sqrt((values[1] * values[1]) -
				   4.0 * (values[0] * values[0] *
					  values[0]))) / 2.0);
  s = (1.0 / 2.0) * sqrt(((-2.0 / 3.0) * values[4]) +
			 ((1.0 / (3.0 * values[3])) *
			  (Q + (values[0] / Q))));
  return (s);
}

double		solver_fourth_degree(double a, double b, double c, ...)
{
  va_list	args;
  double	d;
  double	e;
  double	s;
  double	p;
  double	q;
  double	det[3];

  va_start(args, c);
  d = va_arg(args, double);
  e = va_arg(args, double);
  va_end(args);
  quadratic_solution_det(det, a, b, c, d, e);
  quadratic_solution_pq(&p, &q, a, b, c, d);
  if (det[2] > 0.0)
    s = quadratic_solution_det_pos(p, det[0], det[1], a);
  else
    s = solver_fourth_calc_s((double []){det[0], det[1], det[2], a, p});
  return (solver_fourth_solve(-(b / (4.0 * a)), s, p, q));
}
