/*
** math.h for Raytracer2 in /gfx_raytracer2/include/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 05:16:20 2016 Antoine Baché
** Last update Sat May  7 01:16:46 2016 Antoine Baché
*/

#ifndef	MATH_H_
# define MATH_H_

# include <math.h>

# define ZERO_DP		(0.0000000001)
# define ZERO_DN		(-0.0000000001)
# define MAGIC_SQRT_NUMBER	0x5f3759df

# define IS_ZERO(X)		(((X) < ZERO_DP && (X) > ZERO_DN) ? 1 : 0)
# define POSITIVE(A)		(((A) > 0.0) ? (A) : 0.0)
# define CHECK_SOLUTION(A)	(((A) > 0.0) ? (A) : (-1.0))
# define SMALLER(A, B)		(((A) < (B)) ? (A) : (B))
# define MIN(A, B)		SMALLER(A, B)
# define MAX(A, B)		(((A) > (B)) ? (A) : (B))
# define CUBIC_ROOT(A)		(pow(A, 1.0 / 3.0))

typedef union	u_sqrt
{
  int		tmp;
  float		val;
}		t_sqrt;

float		fast_sqrt(float);
float		inv_fast_sqrt(float);

#endif /* !MATH_H_  */
