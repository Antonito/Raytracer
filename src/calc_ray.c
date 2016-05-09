/*
** calc_ray.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 30 23:30:01 2016 Ludovic Petrenko
** Last update Mon May  9 10:49:28 2016 Ludovic Petrenko
*/

#pragma GCC warning "\e[31m\e[1mCommentaires + Norme + Boucle opti!\e[0m"

#define _ISOC99_SOURCE

#include <math.h>
#include "raytracer.h"
#include "engine/scene.h"
#include "tools/math.h"

unsigned int	mix_colors(t_intersect *i, t_intersect *r,
			   t_intersect *t)
{
  t_color	final;
  t_color	color;
  t_color	reflect;
  t_color	refract;
  double	coef;
  double	coef2;
  double	refl;
  double	refr;
  int		j;

  refl = (i->mat) ? i->mat->reflectivity : DEFAULT_MAT_REFLECTIVITY;
  reflect.full = 0;
  if (r->dist >= 0.0 && r->dist != INFINITY)
    reflect = r->color;
  refr = (i->mat) ? i->mat->opacity : DEFAULT_MAT_OPACITY;
  if (t->dist >= 0.0 && t->dist != INFINITY)
    refr = MAX(MIN(refr * t->dist, 1.0), 0.0);
  refract.full = 0;
  if (t->dist >= 0.0 && t->dist != INFINITY)
    refract = t->color;
  coef = MIN(1.0, MAX(dot_vec3(vec3_normalize(i->norm),
			       vec3_normalize(vec3(0,1,1))), 0.1));
  coef2 = MIN(1.0, MAX(dot_vec3(vec3_normalize(t->norm),
  				vec3_normalize(vec3(0,1,1))), 0.1));
  color.full = (i->mat) ? i->mat->color : DEFAULT_MAT_COLOR;
  j = -1;
  while (++j < 4)
    final.argb[j] = (unsigned char)(reflect.argb[j] * refl + (1 - refl) *
				    (color.argb[j] * coef * refr +
				     refract.argb[j] * coef2 * (1 - refr)));
  return (final.full);
}



unsigned int	calc_ray(t_scene *scene, t_ray *ray, int i)
{
  t_intersect	inter;
  t_intersect	refl;
  t_intersect	refr;
  t_ray		tmp;

  if (i >= MAX_RECURSIVE)
    return (scene->spec.bg_color);
  node_intersect(&scene->octree, ray, &inter);
  if (inter.dist <= 0.0 || inter.dist == INFINITY)
    return (scene->spec.bg_color);
  /* inter.mat = NULL; */
  /* inter.norm = mult_vec3(inter.norm, -1.0); */
  /* if (fabs(dot_vec3(vec3_normalize(ray->dir), vec3_normalize(inter.norm))) < 0.3) */
  /*   return (0x00000000); */
  tmp.dir = add_vec3(ray->dir, mult_vec3(inter.norm,
					 -2.0 * dot_vec3(inter.norm, ray->dir)));
  tmp.dir = vec3_normalize(tmp.dir);
  tmp.pos = inter.pos;
  tmp.src = inter.obj;
  refl.mat = NULL;
  node_intersect(&scene->octree, &tmp, &refl);
  tmp.dir = add_vec3(ray->dir,
		     mult_vec3(inter.norm, 1 / ((ray->src) ?
					    (((t_obj*)ray->src)->mat) ?
					    ((t_obj*)ray->src)->mat->fresnel : 1.0 : 1.0) *
			       ((inter.mat) ?
				inter.mat->fresnel : 1.0)));
  node_intersect(&scene->octree, &tmp, &refr);
  if (ray->src == refr.obj)
    refr.mat = NULL;
  return (mix_colors(&inter, &refl, &refr));
}
