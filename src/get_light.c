/*
** get_light.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed May 18 05:37:31 2016 Ludovic Petrenko
** Last update Thu May 19 06:23:56 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "tools/math.h"

static void	get_lum(double *col, t_scene *s, t_intersect *inter, int m)
{
  t_vec3	l;
  t_vec3	r;
  double	ln;
  int		i;
  double	is;
  double	id;
  double	dist;
  double	rv;
  double	tmp;
  t_ray		ray;
  t_intersect	shadow;

  l = sub_vec3(s->lights[m].pos, inter->pos);
  dist = vec3_len(l);
  l = div_vec3(l, dist);
  dist -= s->lights[m].light.radius;
  ln = dot_vec3(l, inter->norm);
  ln = MAX(ln, 0.0);
  r = vec3_normalize(sub_vec3(mult_vec3(inter->norm, 2 * ln), l));
  is = s->lights[m].light.power / dist;
  id = s->lights[m].light.radius * is;
  rv = -dot_vec3(r, inter->dir);
  rv = MAX(rv, 0.0);
  ray.pos = add_vec3(inter->pos, mult_vec3(inter->norm, 0.00001));
  ray.dir = l;
  ray.env = NULL;
  node_intersect(&s->octree, &ray, &shadow);
  if (shadow.dist < dist - 0.0001)
    return ;
  i = -1;
  while (++i < 3)
    {
      tmp = inter->mat->diffuse * MAX(ln, 0) * id *
      	s->lights[m].light.color.argb[i] / 255.0;
      col[i] += MAX(tmp, 0);
      tmp = inter->mat->specular * pow(rv, inter->mat->shininess)
	* is * s->lights[m].light.color.argb[i] / 255.0;
      col[i] += MAX(tmp, 0);
    }
}

void		get_light(t_scene *s, t_intersect *inter, double *col)
{
  int		i;
  int		m;
  double	max;
  double	total;

  i = m = -1;
  while (++i < 3)
    col[i] = s->spec.bg_color.argb[i] / 255.0 * s->spec.ambiant;
  max = total = 0;
  while (++m < s->nb_light)
    {
      get_lum(col, s, inter, m);
      max = MAX(s->lights[m].light.power, max);
      total += s->lights[m].light.power;
    }
  i = -1;
  while (++i < 3)
    col[i] /= total / max;
}
