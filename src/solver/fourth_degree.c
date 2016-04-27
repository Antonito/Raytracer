/*
** fourth_degree.c for Raytracer2 in /gfx_raytracer2/src/solver
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:18:12 2016 Antoine Baché
** Last update Wed Apr 27 04:21:31 2016 Antoine Baché
*/

#include <stdarg.h>
#include "solver.h"

double		solver_fourth_degree(double a, double b, double c, ...)
{
  va_list	args;
  double	d;
  double	e;
  double	res;

  va_start(args, c);
  d = va_arg(args, double);
  e = va_arg(args, double);
  va_end(args);
  return (res);
}
