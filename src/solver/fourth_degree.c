/*
** fourth_degree.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:18:12 2016 Antoine Baché
** Last update Sat Apr 30 19:38:58 2016 Antoine Baché
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
  (*p) = (8.0 * a * c - 3.0 * b * b) / (8.0 * a * a);
  (*q) = ((b * b * b) - (4.0 * a * b * c) + (8.0 * a * a * d)) /
    (8.0 * a * a * a);
}

static double	quadratic_solution_det_neg(double p, double det0, double det1,
					   double a)
{
  return ((1.0 / 2.0) * fast_sqrt((-(2.0 / 3.0) * p) +
				  ((2.0 / (3.0 * a)) * fast_sqrt(det0) *
				   cos((acos(det1 /
					     (2.0 * fast_sqrt(det0 * det0 *
							      det0)))) / 3.0))));
}

static double	solver_fourth_solve(double val, double s, double p, double q)
{
  double	tmp[3];

  tmp[0] = val;
  tmp[1] = (1.0 / 2.0) * fast_sqrt(-4.0 * s * s - 2.0 * p + (q / s));
  tmp[2] = (1.0 / 2.0) * fast_sqrt(-4.0 * s * s - 2.0 * p - (q / s));
  return (quadratic_solution_calc(tmp, s));
}

static double	solver_fourth_calc_s(double *values)
{
  double	Q;
  double	s;

  printf("Det[0] = %f Det[1] = %f Det[2] = %f A = %f p = %f\n", values[0], values[1], values[2], values[3], values[4]);
  if (values[2] && !values[0])
    values[1] = fast_sqrt(values[1] * values[1]);
  Q = CUBIC_ROOT((values[1] + fast_sqrt((values[1] * values[1]) -
					4.0 * (values[0] * values[0] *
					     values[0]))) / 2.0);
  s = (1.0 / 2.0) * fast_sqrt((-(2.0 / 3.0) * values[4]) +
			      (1.0 / (3.0 * values[3])) *
			      (Q + (values[0] / Q)));
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
  if (det[2] < 0.0)
    s = quadratic_solution_det_neg(p, det[0], det[1], a);
  else
    s = solver_fourth_calc_s((double []){det[0], det[1], det[2], a, p});
  return (solver_fourth_solve(-(b / (4.0 * a)), s, p, q));
}
