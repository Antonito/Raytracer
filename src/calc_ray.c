/*
** calc_ray.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 30 23:30:01 2016 Ludovic Petrenko
** Last update Fri May  6 15:42:14 2016 Ludovic Petrenko
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


  color.full = (i->mat != NULL) ? i->mat->color : DEFAULT_MAT_COLOR;
  /* printf("DIST: %f\n", i->dist); */
  final.argb[0] = (unsigned char)(color.argb[0] / MAX(i->dist / 4.0, 1.0));
  final.argb[1] = (unsigned char)(color.argb[1] / MAX(i->dist / 4.0, 1.0));
  final.argb[2] = (unsigned char)(color.argb[2] / MAX(i->dist / 4.0, 1.0));
  (void)reflect;
  (void)transp;
  return (final.full);
}

unsigned int	calc_ray(t_scene *scene, t_ray ray, int i)
{
  t_color	reflect;
  t_color	transp;
  t_intersect	inter;

  if (i >= MAX_RECURSIVE)
    return (scene->spec.bg_color);
  inter = node_intersect(&scene->octree, ray);
  if (inter.dist <= 0.0 || inter.dist == INFINITY)
    return (scene->spec.bg_color);
  /* inter.mat = NULL; */
  reflect.full = 0;
  transp.full = 0;
  return (mix_colors(&inter, reflect, transp));
}
