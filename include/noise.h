/*
** noise.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:54:08 2016 Antoine Baché
** Last update Tue Apr 19 09:30:43 2016 Antoine Baché
*/

#ifndef NOISE_H_
# define NOISE_H_

# include "tools/types.h"
# include "engine/vector.h"

typedef struct	s_mask2
{
  int		x;
  int		y;
}		t_mask2;

typedef struct	s_mask3
{
  int		x;
  int		y;
  int		z;
}		t_mask3;

typedef struct	s_mask4
{
  int		x;
  int		y;
  int		z;
  int		w;
}		t_mask4;

typedef struct	s_gradient2
{
  int		a;
  int		b;
  int		c;
  int		d;
}		t_gradient2;

typedef struct	s_gradient3
{
  int		a;
  int		b;
  int		c;
  int		d;
  int		e;
  int		f;
  int		g;
  int		h;
}		t_gradient3;

typedef struct	s_gradient4
{
  int		a;
  int		b;
  int		c;
  int		d;
  int		e;
  int		f;
  int		g;
  int		h;
  int		i;
  int		j;
  int		k;
  int		l;
  int		m;
  int		n;
  int		o;
  int		p;
}		t_gradient4;

double		perlin_noise(void *, float, int);

t_vec2		*perlin_2d_table(void);
t_vec3		*perlin_3d_table(void);
t_vec4		*perlin_4d_table(void);
void		perlin_4d_table_last(t_vec4 *);
void		perlin_calc_init(void *, void *, void *, ...);
void		calc_perlin_gradient(void *, void *, unsigned char *, int);

#endif /* !NOISE_H_ */
