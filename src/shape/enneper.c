/*
** enneper.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 15 04:31:13 2016 Antoine Baché
** Last update Sun May 15 04:33:51 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

#pragma message("Not used .....")
static void	get_dist_enneper(t_obj *obj, t_ray *ray, t_intersect *inter,
			       t_vec3 tmp)
{
  double	s[5];

  if ((inter->dist = solver_fourth_degree(s[0], s[1], s[2], s[3], s[4]))
      == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_enneper(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_enneper(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  return (inter);
}
