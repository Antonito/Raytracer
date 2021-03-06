/*
** noise.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:54:08 2016 Antoine Baché
** Last update Wed Apr 20 20:01:50 2016 Antoine Baché
*/

#ifndef NOISE_H_
# define NOISE_H_

# include "tools/types.h"
# include "engine/vector.h"

typedef enum	e_perlin_state
  {
    DRAW,
    FREE
  }		t_perlin_state;

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

/*
** Noises
**
** You should always use these functions
** and never the "... specific" or "Common" ones.
**
** Fist parameter is the current position of your pixel
** It should either be a t_vec2 or t_vec3 or t_vec4.
**
** Second parameter is designed to modulate the shape of the noise.
**
** Third parameter should eiter be 2, 3 or 4.
** Other dimensions are not supported.
**
** Fourth parameter should either be DRAW or FREE.
** Use DRAW for normal usage, and FREE at the end of your program.
*/
double		perlin_noise(void *, float, int, t_perlin_state);
double		simplex_noise(void *, float, int, t_perlin_state);

/*
** Common, should not be called.
*/
unsigned char	*permutation_table(void);

/*
** Perlin Specific, should not be called.
*/
t_vec2		*perlin_2d_table(void);
t_vec3		*perlin_3d_table(void);
t_vec4		*perlin_4d_table(void);
void		perlin_4d_table_last(t_vec4 *);
void		perlin_calc_init(void *, void *, void *, ...);
void		calc_perlin_gradient(void *, void *, unsigned char *, int);
void		perlin_calc_smooth_values(void *, void *, void *, int);
void		perlin_calc_smooth(void *, void *, int);
void		perlin_calc_color(void *, void *, void *, ...);
double		perlin_calc_pixel_2d(t_perlin_color2 *, t_vec2 *);
double		perlin_calc_pixel_3d(t_perlin_color3 *, t_vec3 *);
double		perlin_calc_pixel_4d(t_perlin_color4 *, t_vec4 *);

/*
** Simplex Specific, should not be called.
*/
void		simplex_mask(void *, void *, int);
void		simplex_calc_det(void *, void *, void *, int);
void		simplex_calc_init(void *, void *, void *, ...);
void		simplex_calc_offset(void *, void *, int, t_perlin_state);
void		simplex_calc_offset_3d_sup(t_vec3 *, t_vec3 *);
void		simplex_calc_offset_3d_inf(t_vec3 *, t_vec3 *);
void		simplex_calc_offset_4d_table(int, t_ivec4 *, t_vec4 *);
int		simplex_calc_index_4d(t_vec4 *);
void		simplex_calc_grad(int *, void *, void *, ...);
double		simplex_calc_pixel(void *, void *, void *, int);
t_ivec4		*simplex_calc_table_4d(void);

#endif /* !NOISE_H_ */
