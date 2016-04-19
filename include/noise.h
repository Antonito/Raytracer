/*
** noise.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:54:08 2016 Antoine Baché
** Last update Tue Apr 19 12:05:00 2016 Antoine Baché
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

typedef struct	s_perlin_color2
{
  float		a;
  float		b;
  float		c;
  float		d;
}		t_perlin_color2;

typedef struct	s_perlin_color3
{
  float		a[2];
  float		b[2];
  float		c[2];
  float		d[2];
}		t_perlin_color3;

typedef struct	s_perlin_color4
{
  float		a[4];
  float		b[4];
  float		c[4];
  float		d[4];
}		t_perlin_color4;

double		perlin_noise(void *, float, int);

unsigned char	*permutation_table(void);
t_vec2		*perlin_2d_table(void);
t_vec3		*perlin_3d_table(void);
t_vec4		*perlin_4d_table(void);
void		perlin_4d_table_last(t_vec4 *);
void		perlin_calc_init(void *, void *, void *, ...);
void		calc_perlin_gradient(void *, void *, unsigned char *, int);
void		perlin_calc_smooth_values(void *, void *, void *, int);
void		perlin_calc_smooth(void *, void *, int);
void		perlin_calc_color(void *, void *, void *, ...);
double		perlin_calc_pixel_3d(t_perlin_color3 *, t_vec3 *);
double		perlin_calc_pixel_4d(t_perlin_color4 *, t_vec4 *);

#endif /* !NOISE_H_ */
