/*
** n_degree_solve.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May  8 21:44:20 2016 Antoine Baché
** Last update Sun May  8 22:09:20 2016 Antoine Baché
*/

#include "solver.h"
#include "tools/math.h"

#pragma message("Solveur non fini")
double		solver_n_degree(double *coef, int degree)
{
  while (degree > 1 && !CHECK_COEF(coef[degree]))
    degree -= 1;
  if (degree == 1)
    {
      if (!CHECK_COEF(coef[1]))
	return (CHECK_SOLUTION(-coef[0] / coef[1])) ;
      return (-1.0);
    }
  if (degree == 2)
    return (solver_second_degree(coef[2], coef[1], coef[0]));

  return (-1.0);
}
