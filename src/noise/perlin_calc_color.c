/*
** perlin_calc_color.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Apr 19 10:21:35 2016 Antoine Baché
** Last update Tue Apr 19 12:40:26 2016 Antoine Baché
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
  c->a[1] = t[g->e].x * tmp.x-- + t[g->e].y * tmp.y + t[g->e].z * tmp.z;
  c->b[1] = t[g->f].x * tmp.x + t[g->f].y * tmp.y-- + t[g->f].z * tmp.z;
  c->d[0] = t[g->h].x * tmp.x + t[g->h].y * tmp.y + t[g->h].z * tmp.z;
  tmp.x = pos->x - origin->x;
  c->c[0] = t[g->g].x * tmp.x + t[g->g].y * tmp.y + t[g->g].z * tmp.z;
}

static void	perlin_calc_color_4d_next(t_perlin_color4 *c,
					  t_vec4 *tmp, t_gradient4 *g,
					  t_vec4 *t)
{
  c->a[1] = t[g->e].x * tmp->x-- + t[g->e].y * tmp->y + t[g->e].z * tmp->z +
    t[g->e].w + tmp->w;
  c->b[1] = t[g->f].x * tmp->x + t[g->f].y * tmp->y-- + t[g->f].z * tmp->z +
    t[g->f].w + tmp->w;
  c->d[1] = t[g->h].x * tmp->x++ + t[g->h].y * tmp->y + t[g->h].z * tmp->z +
    t[g->h].w + tmp->w;
  c->c[1] = t[g->g].x * tmp->x + t[g->g].y * tmp->y++ + t[g->g].z * tmp->z++ +
    t[g->g].w + tmp->w--;
  c->a[2] = t[g->i].x * tmp->x-- + t[g->i].y * tmp->y + t[g->i].z * tmp->z +
    t[g->i].w + tmp->w;
  c->b[2] = t[g->j].x * tmp->x + t[g->j].y * tmp->y-- + t[g->j].z * tmp->z +
    t[g->j].w + tmp->w;
  c->d[2] = t[g->l].x * tmp->x++ + t[g->l].y * tmp->y + t[g->l].z * tmp->z +
    t[g->l].w + tmp->w;
  c->c[2] = t[g->k].x * tmp->x + t[g->k].y * tmp->y++ + t[g->k].z * tmp->z-- +
    t[g->k].w + tmp->w;
  c->a[3] = t[g->m].x * tmp->x-- + t[g->m].y * tmp->y + t[g->m].z * tmp->z +
    t[g->m].w + tmp->w;
  c->b[3] = t[g->n].x * tmp->x + t[g->n].y * tmp->y-- + t[g->n].z * tmp->z +
    t[g->n].w + tmp->w;
  c->d[3] = t[g->p].x * tmp->x++ + t[g->p].y * tmp->y + t[g->p].z * tmp->z +
    t[g->p].w + tmp->w;
  c->c[3] = t[g->o].x * tmp->x + t[g->o].y * tmp->y + t[g->o].z * tmp->z +
    t[g->o].w + tmp->w;
}

static void	perlin_calc_color_4d(t_perlin_color4 *c, t_vec4 *pos,
				     t_ivec4 *origin, ...)
{
  va_list	args;
  t_vec4	*t;
  t_gradient4	*g;
  t_vec4	tmp;

  va_start(args, origin);
  g = va_arg(args, t_gradient4 *);
  t = va_arg(args, t_vec4 *);
  va_end(args);
  tmp.x = pos->x - origin->x;
  tmp.y = pos->y - origin->y;
  tmp.z = pos->z - origin->z;
  tmp.w = pos->w - origin->w;
  c->a[0] = t[g->a].x * tmp.x-- + t[g->a].y * tmp.y + t[g->a].z * tmp.z +
    t[g->a].w * tmp.w;
  c->b[0] = t[g->b].x * tmp.x + t[g->b].y * tmp.y-- + t[g->b].z * tmp.z +
    t[g->b].w * tmp.w;
  c->d[0] = t[g->d].x * tmp.x++ + t[g->d].y * tmp.y + t[g->d].z * tmp.z +
    t[g->d].w * tmp.w;
  c->c[0] = t[g->c].x * tmp.x + t[g->c].y * tmp.y++ + t[g->c].z * tmp.z-- +
    t[g->c].w * tmp.w;
  perlin_calc_color_4d_next(c, &tmp, g, t);
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
