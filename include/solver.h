/*
** solver.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:02:18 2016 Antoine Baché
** Last update Sat Apr 30 19:36:47 2016 Antoine Baché
*/

#ifndef SOLVER_H_
# define SOLVER_H_

# define NOT_A_SOLUTION		0xFFFFFFFFFFFFFFFF

/*
** Solver
**
**  2nd -> a * (x ^ 2) + b * x + c = 0
**  3rd -> a * (x ^ 3) + b * (x ^ 2) + c * x + d = 0
**  4th -> a * (x ^ 4) + b * (x ^ 3) + c * (x ^ 2) + d * x + e = 0
**
** Function parameters are a, b, c, d, e
*/
double		solver_second_degree(double, double, double);
double		solver_third_degree(double, double, double, double);
double		solver_fourth_degree(double, double, double, ...);

/*
** Those functions should never be
** called.
*/
double		check_solution_equation(double, double);
double		quadratic_solution_calc(double *, double);
void		quadratic_solution_det(double *, double, double, ...);

#endif /* !SOLVER_H_ */
