/*
** n_degree_solvers.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon May  9 23:20:33 2016 Ludovic Petrenko
** Last update Fri May 20 22:09:51 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "tools/math.h"
#include "tools/memory.h"

#pragma message("Solveur non fini")

void	solve_first(double *coef, double *sol)
{
  sol[0] = -MAX_ROOT;
  sol[1] = -coef[1] / coef[0];
  sol[2] = MAX_ROOT;
}

void	solve_second(double *coef, double *sol)
{
  double	det;
  double	opti;

  sol[0] = -MAX_ROOT;
  /* opti = -2.0 * coef[0]; */
  det = coef[1] * coef[1] - 4.0 * coef[0] * coef[2];
  if (det == 0.0)
    {
      sol[1] = -coef[1] / (2.0 * coef[0]);
      sol[2] = MAX_ROOT;
    }
  else if (det >= 0.0)
    {
      det = sqrt(det);
      sol[1] = (-coef[1] - det) / (2.0 * coef[0]);
      sol[2] = (-coef[1] + det) / (2.0 * coef[0]);
      if (sol[1] > sol[2])
	swap_double(sol + 1, sol + 2);
      sol[3] = MAX_ROOT;
    }
  else
    sol[1] = MAX_ROOT;
}

static double	loop_dicho(double *coeff, int deg, t_dicho *d)
{
  int		i;
  double	tmp;

  i = -1;
  while (++i < 1000000)
    {
      if (d->sl == 0)
	return (d->l);
      if (d->sr == 0)
	return (d->r);
      d->mid = d->l / 2.0 + d->r / 2.0;
      tmp = calc_poly(coeff, deg, d->mid);
      d->smid = SIGNOF(tmp);
      if (fabs(d->l - d->r) < 0.0001 || !d->smid)
	return (d->mid);
      else if (d->sl * d->smid > 0)
	{
	  d->l = d->mid;
	  d->sl = d->smid;
	}
      else
	{
	  d->r = d->mid;
	  d->sr = d->smid;
	}
    }
  return ((d->l + d->r) / 2.0);
}

double		calc_root(double *coeff, int deg, double l, double r)
{
  t_dicho	d;
  double	tmp;

  d.l = l;
  d.r = r;
  tmp = calc_poly(coeff, deg, l);
  d.sl = SIGNOF(tmp);
  tmp = calc_poly(coeff, deg, r);
  d.sr = SIGNOF(tmp);
  if (d.sl * d.sr > 0)
    return (MAX_ROOT + 1);
  return (loop_dicho(coeff, deg, &d));
}
