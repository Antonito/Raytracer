/*
** mobius.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May  4 07:24:31 2016 Antoine Baché
** Last update Sun May 15 02:16:06 2016 Antoine Baché
*/

#include <math.h>
#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

static void	get_dist_mobius(t_obj *obj, t_ray *ray, t_intersect *inter,
				t_vec3 tmp)
{
  double	*s;

  if (!(s = my_malloc(sizeof(double) * 4)))
    return ;
  s[0] = ray->dir.y * ray->dir.z * ray->dir.z + ray->dir.y * ray->dir.y *
    ray->dir.y + ray->dir.x * ray->dir.x * ray->dir.y - 2.0 * ray->dir.x *
    ray->dir.x * ray->dir.z - 2.0 * ray->dir.y * ray->dir.y * ray->dir.z;
  s[1] = tmp.y * ray->dir.x * ray->dir.x - 2.0 * tmp.z * ray->dir.x * ray->dir.x + 3.0 * tmp.y * ray->dir.y * ray->dir.y - 2.0 * tmp.z * ray->dir.y * ray->dir.y + tmp.y * ray->dir.z * ray->dir.z + 2.0 * tmp.x * ray->dir.x * ray->dir.y - 4.0 * tmp.x * ray->dir.x * ray->dir.z - 2.0 * obj->mobius.radius * ray->dir.x * ray->dir.z - 4.0 * tmp.y * ray->dir.y * ray->dir.z + 2.0 * tmp.z * ray->dir.y * ray->dir.z;
  s[2] = 2.0 * tmp.x * tmp.y * ray->dir.x - 4.0 * tmp.x * tmp.z * ray->dir.x - 2.0 * obj->mobius.radius * tmp.z * ray->dir.x + tmp.x * tmp.x * ray->dir.y + 3.0 * tmp.y * tmp.y * ray->dir.y + tmp.z * tmp.z * ray->dir.y - obj->mobius.radius * obj->mobius.radius * ray->dir.y - 4.0 * tmp.y * tmp.z * ray->dir.y - 2.0 * tmp.x * tmp.x * ray->dir.z - 2.0 * tmp.y * tmp.y * ray->dir.z - 2.0 * obj->mobius.radius * tmp.x * ray->dir.z + 2.0 * tmp.y * tmp.z * ray->dir.z;
  s[3] = tmp.y * tmp.z * tmp.z + tmp.y * tmp.y * tmp.y + tmp.x * tmp.x * tmp.y - obj->mobius.radius * obj->mobius.radius * tmp.y - 2.0 * tmp.x * tmp.x * tmp.z - 2.0 * tmp.y * tmp.y * tmp.z - 2.0 * obj->mobius.radius * tmp.x * tmp.z;
  if ((inter->dist = solver_n_degree(s, 3)) == NOT_A_SOLUTION)
      inter->dist = -1.0;
}

t_intersect	get_intersect_mobius(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  double	v;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_mobius(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist == -1.0)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  v = atan(inter.pos.y / inter.pos.x);
  inter.norm = vec3_normalize(vec3(-1.0 * cos(v) * cos(v / 2.0),
				   -1.0 * sin(v) * cos(v / 2.0),
				   -1.0 * sin(v / 2.0)));
  if (vec3_len(add_vec3(mult_vec3(ray->dir, inter.dist), inter.norm)) <
      inter.dist)
    inter.norm = mult_vec3(inter.norm, -1.00);
  return (inter);
}
