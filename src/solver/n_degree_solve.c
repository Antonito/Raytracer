/*
** n_degree_solve.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May  8 21:44:20 2016 Antoine Baché
** Last update Mon May  9 14:30:46 2016 Antoine Baché
*/

#include "solver.h"
#include "tools/math.h"

#pragma message("Solveur non fini")

static double	*calc_root(double *coef, int degree)
{
  /* double	ret; */
  /* double	*new_coef; */
  /* int		i; */

  /* while (degree > 1 && !CHECK_COEF(coef[degree])) */
  /*   degree -= 1; */
  /* if (degree == 1) */
  /*   { */
  /*     if (!CHECK_COEF(coef[1])) */
  /* 	return (CHECK_SOLUTION(-coef[0] / coef[1])) ; */
  /*     return (NULL); */
  /*   } */
  /* if (degree == 2) */
  /*   return (); //Solve 2nd degree */
  /* i = -1; */
  /* if (!(new_coef = my_calloc(degree + 1, sizeof(double)))) */
  /*   return (NULL); */
  /* while (++i < degree) */
  /*   new_coef[i] = coef[i + 1] * (i + 1); */
  /* i = -1; */
  /* while (++i < degree + 1) */
  /*   { */
  /*     ret = ; */
  /*     if (fabs(ret) < 10e10) */
  /* 	; */
  /*   } */
  /* my_free(new_coef); */
  /* return (NULL); */
}

double		solver_n_degree(double *coef, int degree)
{
  double	*root;
  double	ret;
  int		i;

  if (!(root = calc_root(coef, degree)))
    return (-1.0);
  i = 0;
  while (i < degree)
    {
      if (root[i] > 0.0)
	{
	  ret = root[i];
	  my_free(root);
	  return (ret);
	}
      ++i;
    }
  my_free(root);
  return (-1.0);
}
