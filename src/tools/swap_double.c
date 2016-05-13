/*
** swap_double.c for Raytracer2 in /semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue May 10 18:18:51 2016 Ludovic Petrenko
** Last update Tue May 10 18:22:31 2016 Ludovic Petrenko
*/

__attribute__((inline)) void	swap_double(double *a, double *b)
{
  double	tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}
