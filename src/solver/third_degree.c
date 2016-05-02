/*
** third_degree.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:15:39 2016 Antoine Baché
** Last update Mon May  2 02:59:47 2016 Antoine Baché
*/

#define _ISOC99_SOURCE

#include <math.h>
#include "solver.h"
#include "tools/math.h"

static void	solver_third_degree_calc_trigo(double *val, double *trigo)
{
  double	k;

  trigo[0] = sqrt(((val[1] * val[1]) / 4.0) - val[2]);
  k = (trigo[0] < 0) ? -1 : 1;
  trigo[1] = pow(trigo[0] * k, (1.0 / 3.0)) * k;
  trigo[2] = (acos((-val[1]) / (2.0 * (trigo[0])))) / 3.0;
}

static void	solver_third_degree_calc_tmp(double *tmp, double rc,
					     double theta, double val)
{
  tmp[0] = rc;
  tmp[1] = cos(theta);
  tmp[2] = sqrt(3.0) * sin(theta);
  tmp[3] = val * -1.0;
}

static void	solver_third_degree_round(double *x, double *tmp, double val)
{
  x[1] = (tmp[0] * (tmp[1] + tmp[2])) - val;
  x[2] = (tmp[0] * (tmp[1] - tmp[2])) - val;
  x[0] = CHECK_SOLUTION(round(x[0] * 100000000000000.0) / 100000000000000.0);
  x[1] = CHECK_SOLUTION(round(x[1] * 100000000000000.0) / 100000000000000.0);
  x[2] = CHECK_SOLUTION(round(x[2] * 100000000000000.0) / 100000000000000.0);
  x[1] = check_solution_equation(x[1], x[2]);
}

static double	solver_third_degree_neg(double g, double h, double val)
{
  double	m[2];
  double	n[2];
  double	k;

  m[0] = (-g / 2.0) + sqrt(h);
  k = (m[0] < 0) ? -1 : 1;
  m[1] = pow(m[0] * k, val) * k;
  n[0] = (-g / 2.0) - sqrt(h);
  k = (n[0] < 0) ? -1 : 1;
  n[1] = pow(n[0] * k, val) * k;
  return (n[1] + m[1]);
}

double		solver_third_degree(double a, double b, double c, double d)
{
  double	x[3];
  double	val[3];
  double	trigo[3];
  double	tmp[4];

  val[0] = (((3.0 * c) / a) - (((b * b) / (a * a)))) / 3.0;
  val[1] = ((2.0 * ((b * b * b) / (a * a * a))) - ((9.0 * b * c) / (a * a)) +
	    ((27.0 * (d / a)))) / 27.0;
  val[2] = ((val[1] * val[1]) / 4.0) + ((val[0] * val[0] * val[0]) / 27.0);
  if (val[2] > 0)
    x[0] = x[1] = x[2] =
      (solver_third_degree_neg(val[1], val[2], (1.0 / 3.0))) - (b / (3.0 * a));
  else
    {
      solver_third_degree_calc_trigo(val, trigo);
      x[0] = (2.0 * (trigo[1] * cos(trigo[2]))) - (b / (3.0 * a));
      solver_third_degree_calc_tmp(tmp, -1 * trigo[1], trigo[2],
				   (b / (3.0 * a)));
      solver_third_degree_round(x, tmp, (b / (3.0 * a)));
    }
  if (!(val[0] + val[1] + val[2]))
    x[0] = x[1] = x[2] = (d < 0) ? pow(d / a, (1.0 / 3.0)) * -1 :
      pow((-d) / a, (1.0 / 3.0));
  return (check_solution_equation(CHECK_SOLUTION(x[0]), CHECK_SOLUTION(x[1])));
}
