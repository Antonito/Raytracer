/*
** kummer.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 15 04:08:12 2016 Antoine Baché
** Last update Sun May 15 04:08:37 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

#pragma message("Not used now")
static void	get_dist_kummer(t_obj *obj, t_ray *ray, t_intersect *inter,
			       t_vec3 tmp)
{
  return ;
}

t_intersect	get_intersect_kummer(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_kummer(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
