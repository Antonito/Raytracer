/*
** perlin_calc_color.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Apr 19 10:21:35 2016 Antoine Baché
** Last update Tue Apr 19 12:01:32 2016 Antoine Baché
*/

#include <stdarg.h>
#include "noise.h"

static void	perlin_calc_color_2d(t_perlin_color2 *color, t_vec2 *pos,
				     t_ivec2 *origin, ...)
{
  va_list	args;
  t_vec2	*table;
  t_gradient2	*gradient;
  float		tmp_x;
  float		tmp_y;

  va_start(args, origin);
  gradient = va_arg(args, t_gradient2 *);
  table = va_arg(args, t_vec2 *);
  va_end(args);
  tmp_x = pos->x - origin->x;
  tmp_y = pos->y - origin->y;
  color->a = table[gradient->a].x * tmp_x + table[gradient->a].y * tmp_y;
  tmp_x = pos->x - (origin->x + 1);
  color->b = table[gradient->b].x * tmp_x + table[gradient->b].y * tmp_y;
  tmp_x = pos->x - origin->x;
  tmp_y = pos->y - (origin->y + 1);
  color->c = table[gradient->c].x * tmp_x + table[gradient->c].y * tmp_y;
  tmp_x = pos->x - (origin->x + 1);
  color->d = table[gradient->d].x * tmp_x + table[gradient->d].y * tmp_y;
}

static void	perlin_calc_color_3d(t_perlin_color3 *c, t_vec3 *pos,
				     t_ivec3 *origin, ...)
{
  va_list	args;
  t_vec3	*t;
  t_gradient3	*g;
  t_vec3	tmp;

  va_start(args, origin);
  g = va_arg(args, t_gradient3 *);
  t = va_arg(args, t_vec3 *);
  va_end(args);
  tmp.x = pos->x - origin->x;
  tmp.y = pos->y - origin->y;
  tmp.z = pos->z - origin->z;
  c->a[0] = t[g->a].x * tmp.x-- + t[g->a].y * tmp.y + t[g->a].z * tmp.z;
  c->b[0] = t[g->b].x * tmp.x + t[g->b].y * tmp.y-- + t[g->b].z * tmp.z;
  c->d[0] = t[g->d].x * tmp.x + t[g->d].y * tmp.y + t[g->d].z * tmp.z;
  tmp.x = pos->x - origin->x;
  c->c[0] = t[g->c].x * tmp.x + t[g->c].y * tmp.y + t[g->c].z * tmp.z--;
  tmp.y = pos->y - origin->y;
  c->a[1] = t[g->a].x * tmp.x-- + t[g->a].y * tmp.y + t[g->a].z * tmp.z;
  c->b[1] = t[g->b].x * tmp.x + t[g->b].y * tmp.y-- + t[g->b].z * tmp.z;
  c->d[0] = t[g->d].x * tmp.x + t[g->d].y * tmp.y + t[g->d].z * tmp.z;
  tmp.x = pos->x - origin->x;
  c->c[0] = t[g->c].x * tmp.x + t[g->c].y * tmp.y + t[g->c].z * tmp.z;
}

static void	perlin_calc_color_4d(t_perlin_color4 *color, t_vec4 *pos,
				     t_ivec4 *origin, ...)
{
  va_list	args;
  t_vec4	*table;
  t_gradient4	*gradient;

  va_start(args, origin);
  gradient = va_arg(args, t_gradient4 *);
  table = va_arg(args, t_vec4 *);
  va_end(args);
}

void		perlin_calc_color(void *color, void *pos,
				  void *origin, ...)
{
  va_list	args;
  void		*table;
  void		*gradient;
  int		dim;

  va_start(args, origin);
  table = va_arg(args, void *);
  gradient = va_arg(args, void *);
  dim = va_arg(args, int);
  va_end(args);
  if (dim == 2)
    perlin_calc_color_2d(color, pos, origin,
			 (t_gradient2 *)gradient, (t_vec2 *)table);
  else if (dim == 3)
    perlin_calc_color_3d(color, pos, origin,
			 (t_gradient3 *)gradient, (t_vec3 *)table);
  else if (dim == 4)
    perlin_calc_color_4d(color, pos, origin,
			 (t_gradient4 *)gradient, (t_vec4 *)table);
}
