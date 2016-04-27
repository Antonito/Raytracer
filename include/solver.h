/*
** solver.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:02:18 2016 Antoine Baché
** Last update Wed Apr 27 04:17:54 2016 Antoine Baché
*/

#ifndef SOLVER_H_
# define SOLVER_H_

# define NOT_A_SOLUTION		0xFFFFFFFFFFFFFFFF

/*
** Solver
*/
double		solver_second_degree(double, double, double);
double		solver_third_degree(double, double, double, double);
double		solver_fourth_degree(double, double, double, ...);

#endif /* !SOLVER_H_ */
