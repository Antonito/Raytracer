/*
** n_degree_solve.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May  8 21:44:20 2016 Antoine Baché
** Last update Wed May 11 05:06:35 2016 Ludovic Petrenko
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

static double	*get_dcoef(double *coef, int deg)
{
  int		i;
  double	*dcoef;

  --deg;
  if (!(dcoef = my_malloc(deg * sizeof(double))))
    return (NULL);
  i = -1;
  while (++i < deg)
    dcoef[i] = coef[i] * (deg - i + 1);
  return (dcoef);
}

static int	reduce_coef(double **coef, int *deg)
{
  double	*new;
  int		i;

  while (IS_ZERO((*coef)[0]) && *deg)
    {
      if (!(new = my_malloc(*deg * sizeof(double))))
	return (1);
      i = -1;
      while (++i < *deg)
	new[i] = (*coef)[i + 1];
      --(*deg);
      my_free(*coef);
      *coef = new;
    }
  return (0);
}

double	*solve_n(double *coef, int deg)
{
  double	*sol;
  double	*dcoef;
  double	*dsol;
  int		i;
  int		j;
  double	tmp;

  if (coef == NULL)
    return (NULL);
  if (reduce_coef(&coef, &deg))
    return (NULL);
  if (deg == 1)
    return (solve_first(coef, deg));
  else if (deg == 2)
    return (solve_second(coef, deg));
  if (!(dcoef = get_dcoef(coef, deg)) || !(dsol = solve_n(dcoef, deg - 1))
      || !(sol = my_malloc((deg + 2) * sizeof(double))))
    return (NULL);
  sol[0] = -MAX_ROOT;
  i = (j = 0) - 1;
  while (++i < deg && dsol[i] != MAX_ROOT)
    if (fabs(tmp = calc_root(coef, deg, dsol[i], dsol[i + 1])) < MAX_ROOT)
      sol[++j] = tmp;
  sol[++j] = MAX_ROOT;
  my_free(coef);
  my_free(dsol);
  return (sol);
}

double		solver_n_degree(double *coef, int degree)
{
  double	sol;
  double	*sols;
  int		i;

  i = -1;
  if (!(sols = solve_n(coef, degree)))
    return (-1.0);
  while (++i < degree + 1)
    if (sols[i] > 0.0)
      {
	sol = sols[i];
	/* my_free(sol); */
	return (sol);
      }
  return (-1.0);
}
