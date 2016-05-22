/*
** cushion.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 15 02:24:37 2016 Antoine Baché
** Last update Sun May 22 20:09:53 2016 Arthur ARNAUD
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_cushion(t_obj *obj, t_ray *ray, t_intersect *inter,
				 t_vec3 tmp)
{
  double	t[5];

#include "shape/cushion.txt"
  if ((inter->dist = solver_n_degree(t, 4)) ==
      NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_cushion(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_cushion(obj, ray, &inter, ray->pos);
  if (inter.dist <= 0.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  calc_normale_cushion(&inter);
  return (inter);
}
