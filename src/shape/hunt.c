/*
** hunt.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 15 03:24:57 2016 Antoine Baché
** Last update Sun May 22 20:40:02 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	get_dist_hunt(t_ray *ray, t_intersect *inter, t_vec3 tmp)
{
  double	s[7];

#include "shape/hunt.txt"
  if ((inter->dist = solver_n_degree(s, 6)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_hunt(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_hunt(ray, &inter, ray->pos);
  if (inter.dist <= 0.0)
    return (inter);
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  calc_normale_hunt(&inter);
  return (inter);
}
