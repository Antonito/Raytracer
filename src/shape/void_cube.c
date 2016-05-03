/*
** void_cube.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May  3 16:58:16 2016 Antoine Baché
** Last update Tue May  3 17:24:57 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"

static void	get_dist_void_cube(t_obj *obj, t_ray *ray, t_intersect *inter)
{
  double	sol[5];

  sol[0] = (ray->dist.x * ray->dist.x * ray->dist.x * ray->dist.x) +
    (ray->dist.y * ray->dist.y * ray->dist.y * ray->dist.y) +
    (ray->dist.z * ray->dist.z * ray->dist.z * ray->dist.z);
  sol[1] = 4 * ((ray->dist.x * ray->dist.x * ray->dist.x * ray->pos.x)
		+ (ray->dist.y * ray->dist.y * ray->dist.y * ray->pos.y)
		+ (ray->dist.z * ray->dist.z * ray->dist.z * ray->pos.z));
  sol[2] = 6.0 * ((ray->dist.x * ray->dist.x * ray->pos.x * ray->pos.x) +
		  (ray->dist.y * ray->dist.y * ray->pos.y * ray->pos.y) +
		  (ray->dist.z * ray->dist.z * ray->pos.z * ray->pos.z)) -
    5.0 * (ray->dist.x * ray->dist.x + ray->dist.y * ray->dist.y *
	   ray->dist.z * ray->dist.z);
  sol[3] = 4 * (ray->pos.x * ray->pos.x * ray->pos.x * ray->dist.x +
		ray->pos.y * ray->pos.y * ray->pos.y * ray->dist.y +
		ray->pos.z * ray->pos.z * ray->pos.z * ray->dist.z) -
    10.0 * (ray->dist.x * ray->pos.x + ray->dist.y * ray->pos.y +
	    ray->dist.z * ray->pos.z);
  sol[4] = (ray->pos.x * ray->pos.x * ray->pos.x * ray->pos.x) +
    (ray->pos.y * ray->pos.y * ray->pos.y * ray->pos.y) +
    (ray->pos.z * ray->pos.z * ray->pos.z * ray->pos.z) -
    5.0 * (ray->pos.x * ray->pos.x + ray->pos.y * ray->pos.y +
	   ray->pos.z * ray->pos.z);
  inter->dist = solver_fourth_degree(sol[0], sol[1], sol[2], sol[3], sol[4]);
}

t_intersect	get_intersect_void_cube(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;
  double	tmp[2];

  inter.dir = ray->dir;
  inter.material = obj->mat;
  get_dist_void_cube(obj, ray, &inter);
  if (inter.dist == -1.0 || inter.dist == NOT_A_SOLUTION)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.sol = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  inter.norm.x = 4 * inter.sol.x * inter.sol.x * inter.sol.x -
    10.0 * inter.sol.x;
  inter.norm.x = 4 * inter.sol.y * inter.sol.y * inter.sol.y -
    10.0 * inter.sol.y;
  inter.norm.x = 4 * inter.sol.z * inter.sol.z * inter.sol.z -
    10.0 * inter.sol.z;
  return (inter);
}
