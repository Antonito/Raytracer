/*
** calc_ray.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 30 23:30:01 2016 Ludovic Petrenko
** Last update Sun May  8 17:52:42 2016 Antoine Baché
*/

#define _ISOC99_SOURCE

#include <math.h>
#include "raytracer.h"
#include "engine/scene.h"
#include "tools/math.h"

unsigned int	mix_colors(t_intersect *i, t_color reflect,
			   t_color transp)
{
  t_color	final;
  t_color	color;
  double	coeff;
  double	refl;

  refl = ((i->mat != NULL) ? i->mat->reflectivity : DEFAULT_MAT_REFLECTIVITY);
  coeff = (1.0 - refl) * MIN(1.0, MAX(dot_vec3(vec3_normalize(i->norm),
					       vec3_normalize(vec3(0,1,1))),
				      0.1));
  color.full = (i->mat != NULL) ? i->mat->color : DEFAULT_MAT_COLOR;
  final.argb[0] = (unsigned char)(color.argb[0] * coeff +
				  reflect.argb[0] * refl);
  final.argb[1] = (unsigned char)(color.argb[1] * coeff +
				  reflect.argb[1] * refl);
  final.argb[2] = (unsigned char)(color.argb[2] * coeff +
				  reflect.argb[2] * refl);
  (void)transp;
  return (final.full);
}

unsigned int	calc_ray(t_scene *scene, t_ray *ray, int i)
{
  t_color	reflect;
  t_color	transp;
  t_intersect	inter;
  t_ray		refl;
  t_ray		refr;

  if (i >= MAX_RECURSIVE)
    return (scene->spec.bg_color);
  node_intersect(&scene->octree, ray, &inter);
  if (inter.dist <= 0.0 || inter.dist == INFINITY)
    return (scene->spec.bg_color);
  /* inter.mat = NULL; */
  refl.dir = add_vec3(ray->dir, mult_vec3(inter.norm,
					  -2.0 * dot_vec3(inter.norm, ray->dir)));
  refl.dir = vec3_normalize(refl.dir);
  refl.pos = inter.pos;
  refl.src = inter.obj;
  reflect.full = calc_ray(scene, &refl, i + 1);
  transp.full = 0;
  return (mix_colors(&inter, reflect, transp));
}
