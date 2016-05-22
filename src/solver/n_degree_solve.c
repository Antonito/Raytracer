/*
** n_degree_solve.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May  8 21:44:20 2016 Antoine Baché
** Last update Sun May 22 14:14:27 2016 Antoine Baché
*/

#include "solver.h"
#include "tools/math.h"
#include "tools/memory.h"

#pragma message("\e[31mFREE SOL\e[0m")

double	calc_poly(double *coef, int degree, double a)
{
  double	res;
  double	x;
  int		i;

  res = 0;
  x = 1.0;
  i = -1;
  while (++i < degree + 1)
    {
      res += coef[degree - i] * x;
      x *= a;
    }
  return (res);
}

static double	*get_dcoef(double *dcoef, double *coef, int deg)
{
  int		i;

  i = -1;
  while (++i < deg)
    dcoef[i] = coef[i] * (deg - i);
  return (dcoef);
}

static void	reduce_coef(double *coef, int *deg)
{
  int		i;

  while (IS_ZERO(coef[0]) && *deg > 1)
    {
      i = -1;
      while (++i < *deg)
	coef[i] = coef[i + 1];
      --(*deg);
    }
}

void		solve_n(double *coef, double *sol, int deg)
{
  double	dcoef[10];
  double	dsol[10];
  int		i;
  int		j;
  double	tmp;

  reduce_coef(coef, &deg);
  if (deg == 1)
    solve_first(coef, sol);
  else if (deg == 2)
    solve_second(coef, sol);
  if (deg < 3)
    return ;
  get_dcoef(dcoef, coef, deg);
  solve_n(dcoef, dsol, deg - 1);
  sol[0] = -MAX_ROOT;
  i = -(j = 1);
  while (++i < deg && dsol[i] != MAX_ROOT)
    if (fabs(tmp = calc_root(coef, deg, dsol[i], dsol[i + 1])) < MAX_ROOT)
      sol[j++] = tmp;
  sol[j] = MAX_ROOT;
}

double		solver_n_degree(double *coef, int degree)
{
  double	sols[10];
  int		i;

  if (degree < 1)
    return (-1.0);
  i = -1;
  solve_n(coef, sols, degree);
  while (++i < 10)
    if (sols[i] > 0.0001)
      return ((sols[i] < MAX_ROOT) ? sols[i] : -1.0);
  return (-1.0);
}
