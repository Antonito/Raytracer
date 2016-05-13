/*
** solver.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 04:02:18 2016 Antoine Baché
** Last update Fri May 13 06:15:07 2016 Antoine Baché
*/

#ifndef SOLVER_H_
# define SOLVER_H_

# define NOT_A_SOLUTION		0xFFFFFFFFFFFFFFFF
# define MAX_ROOT		(1e10)

typedef struct	s_dicho
{
  double	l;
  double	r;
  double	mid;
  int		sl;
  int		sr;
  int		smid;
}		t_dicho;

/*
** Solver
**
**  2nd -> a * (x ^ 2) + b * x + c = 0
**  3rd -> a * (x ^ 3) + b * (x ^ 2) + c * x + d = 0
**  4th -> a * (x ^ 4) + b * (x ^ 3) + c * (x ^ 2) + d * x + e = 0
**
** Function parameters are a, b, c, d, e
**
** Use the n degree solver if degree > 4
** Example of use for a 5 degree equation :
**
** solver_n_degree((double [5]{a, b, c, d, e, f}), 5);
*/
double		solver_second_degree(double, double, double);
double		solver_third_degree(double, double, double, double);
double		solver_fourth_degree(double, double, double, ...);
double		solver_n_degree(double *coef, int degree);

/*
** Those functions should never be
** called.
*/
double		check_solution_equation(double, double);
double		quadratic_solution_calc(double *, double);
void		quadratic_solution_det(double *, double, double, ...);
double		calc_root(double *coeff, int deg, double l, double r);
double		*solve_first(double *coef);
double		*solve_second(double *coef);
double		calc_poly(double *coef, int degree, double a);

#endif /* !SOLVER_H_ */
