/*
** math.h for Raytracer2 in /gfx_raytracer2/include/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 27 05:16:20 2016 Antoine Baché
** Last update Wed Apr 27 15:02:59 2016 Antoine Baché
*/

#ifndef	MATH_H_
# define MATH_H_

# include <math.h>

# define MAGIC_SQRT_NUMBER	0x5f3759df

# define POSITIVE(A)		(((A) > 0.0) ? (A) : 0.0)
# define CHECK_SOLUTION(A)	(((A) > 0.0) ? (A) : (-1.0))
# define SMALLER(A, B)		(((A) < (B)) ? (A) : (B))
# define CUBIC_ROOT(A)		(pow(A, 1.0 / 3.0))

typedef union	u_sqrt
{
  int		tmp;
  float		val;
}		t_sqrt;

float		fast_sqrt(float);
float		inv_fast_sqrt(float);

#endif /* !MATH_H_  */
