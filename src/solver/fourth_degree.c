/*
** fourth_degree.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:18:12 2016 Antoine Baché
** Last update Wed Apr 27 22:34:37 2016 Antoine Baché
*/

#include <stdarg.h>
#include "solver.h"
#include "tools/math.h"

/*
** Here, z == z0 == root of this 3rd degree equation
** (z ^ 3) + p * (z ^ 2) + z * (((p  ^ 2) - 4 * r) / 4) - ((q ^ 2) / 8) = 0
**
** z0 should always be positive
**
*/
/* static double	solver_fourth_degree_case_not_0(double p, double q, double r) */
/* { */
/*   double	res[4]; */
/*   double	tmp[2]; */
/*   double	z; */

/*   z = 0; */

/*   tmp[0] = fast_sqrt(2 * z); */
/*   tmp[1] = fast_sqrt((2 * z) - 4 * ((p / 2) + z + (q / (2 * tmp[0])))); */
/*   res[0] = (tmp[0] - tmp[1]) / 2; */
/*   res[1] = (tmp[0] + tmp[1]) / 2; */
/*   res[2] = (-tmp[0] - tmp[1]) / 2; */
/*   res[3] = (-tmp[0] + tmp[1]) / 2; */
/*   res[0] = CHECK_SOLUTION(res[0]); */
/*   res[1] = CHECK_SOLUTION(res[1]); */
/*   res[0] = check_solution_equation(res[0], res[1]); */
/*   res[2] = CHECK_SOLUTION(res[2]); */
/*   res[3] = CHECK_SOLUTION(res[3]); */
/*   res[2] = check_solution_equation(res[2], res[3]); */
/*   return (check_solution_equation(res[0], res[2])); */
/* } */

/* static double	solver_fourth_degree_case_0(double p, double r) */
/* { */
/*   double	tmp[2]; */
/*   double	res[4]; */

/*   tmp[0] = fast_sqrt(p * p - 4 * r); */
/*   tmp[1] = fast_sqrt((-p - tmp[0]) / 2); */
/*   res[0] = tmp[1]; */
/*   res[1] = -tmp[1]; */
/*   tmp[1] = fast_sqrt((-p + tmp[0]) / 2); */
/*   res[2] = tmp[1]; */
/*   res[3] = -tmp[1]; */
/*   res[0] = CHECK_SOLUTION(res[0]); */
/*   res[1] = CHECK_SOLUTION(res[1]); */
/*   res[0] = check_solution_equation(res[0], res[1]); */
/*   res[2] = CHECK_SOLUTION(res[2]); */
/*   res[3] = CHECK_SOLUTION(res[3]); */
/*   res[2] = check_solution_equation(res[2], res[3]); */
/*   return (check_solution_equation(res[0], res[2])); */
/* } */

/* double		solver_fourth_degree(double a, double b, double c, ...) */
/* { */
/*   va_list	args; */
/*   double	d; */
/*   double	e; */
/*   double	res; */
/*   double	p; */
/*   double	q; */
/*   double	r; */

/*   va_start(args, c); */
/*   d = va_arg(args, double); */
/*   e = va_arg(args, double); */
/*   va_end(args); */
/*   p = ((8 * a * c) - (3 * b * b)) / (8 * a * a); */
/*   q = ((8 * a * a * d) + (b * b * b) - (4 * a * b * c)) / (8 * a * a * a); */
/*   r = ((16 * a * b * b * c) - (64 * a * a * b * d) - (3 * b * b * b * b) + */
/*        (256 * a * a * a * e)) / (256 * a * a * a * a); */
/*   if (!q) */
/*     res = solver_fourth_degree_case_0(p, r); */
/*   else */
/*     res = solver_fourth_degree_case_not_0(p, q, r); */
/*   return (res); */
/* } */

/*
** Other method
*/
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
  (*p) = (8 * a * c - 3 * b * b) / (8 * a * a);
  (*q) = ((b * b * b) - (4 * a * b * c) + (8 * a * a * d)) / (8 * a * a * a);
}

static double	quadratic_solution_det_neg(double p, double det0, double det1,
					   double a)
{
  return ((1 / 2) * fast_sqrt((-(2 / 3) * p) +
			      ((2 / (3 * a)) * fast_sqrt(det0) *
			       cos((acos(det1 /
					 (2 * fast_sqrt(det0 * det0 *
							det0)))) / 3))));
}

double		solver_fourth_degree(double a, double b, double c, ...)
{
  va_list	args;
  double	d;
  double	e;
  double	s;
  double	Q;
  double	p;
  double	q;
  double	det[3];
  double	tmp[3];

  va_start(args, c);
  d = va_arg(args, double);
  e = va_arg(args, double);
  va_end(args);
  quadratic_solution_det((double **)&det, a, b, c, d, e);
  quadratic_solution_pq(&p, &q, a, b, c, d);
  if (det[2] > 0)
    s = quadratic_solution_det_neg(p, det[0], det[1], a);
  else
    {
      if (det[2] && !det[0])
	det[1] = fast_sqrt(det[1] * det[1]);
      Q = CUBIC_ROOT((det[1] + fast_sqrt((det[1] * det[1]) -
					 4 * (det[0] * det[0] * det[0]))) / 2);
      s = (1 / 2) * fast_sqrt((-(2 / 3) * p) + (1 / (3 * a)) *
			      (Q + (det[0] / Q)));
    }
  tmp[0] = -(b / (4 * a));
  tmp[1] = (1 / 2) * fast_sqrt(-4 * s * s - 2 * p + (q / s));
  tmp[2] = (1 / 2) * fast_sqrt(-4 * s * s - 2 * p - (q / s));
  return (quadratic_solution_calc(tmp, s));
}
