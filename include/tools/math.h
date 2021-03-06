/*
** math.h for Raytracer2 in /gfx_raytracer2/include/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 05:16:20 2016 Antoine Baché
** Last update Sat May 21 11:48:11 2016 Luka Boulagnon
*/

#ifndef	MATH_H_
# define MATH_H_

# include <math.h>

# define ZERO_DP		(1e-4)
# define MAGIC_SQRT_NUMBER	0x5f3759df
# define NB_TRIGO		36000

# define IS_ZERO(X)		(fabs(X) < ZERO_DP ? 1 : 0)
# define POSITIVE(A)		(((A) > 0.0) ? (A) : 0.0)
# define CHECK_SOLUTION(A)	(((A) > 0.0) ? (A) : (-1.0))
# define SMALLER(A, B)		(((A) < (B)) ? (A) : (B))
# define MIN(A, B)		SMALLER(A, B)
# define MAX(A, B)		(((A) > (B)) ? (A) : (B))
# define CUBIC_ROOT(A)		(pow(A, 1.0 / 3.0))
# define CHECK_COEF(A)		((A < -ZERO_DP) ? (-1) : (A > ZERO_DP))
# define SIGNOF(A)		(((A) < -ZERO_DP) ? -1 : !(IS_ZERO(A)))
# define POW(A)			((A) * (A))

typedef enum	e_trigo_state
  {
    FREE,
    DRAW
  }		t_trigo_state;

typedef union	u_sqrt
{
  int		tmp;
  float		val;
}		t_sqrt;

float		fast_sqrt(float);
float		inv_fast_sqrt(float);
double		my_cos(double, t_trigo_state);
double		my_sin(double, t_trigo_state);

#endif /* !MATH_H_  */
