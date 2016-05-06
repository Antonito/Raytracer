/*
** void_cube.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May  3 16:58:16 2016 Antoine Baché
** Last update Wed May  4 19:37:50 2016 Ludovic Petrenko
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

static void	get_dist_void_cube(t_ray *ray, t_intersect *inter)
{
  double	sol[5];

  sol[0] = (ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x) +
    (ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y) +
    (ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z);
  sol[1] = 4.0 * ((ray->dir.x * ray->dir.x * ray->dir.x * ray->pos.x)
		  + (ray->dir.y * ray->dir.y * ray->dir.y * ray->pos.y)
		  + (ray->dir.z * ray->dir.z * ray->dir.z * ray->pos.z));
  sol[2] = 6.0 * ((ray->dir.x * ray->dir.x * ray->pos.x * ray->pos.x) +
		  (ray->dir.y * ray->dir.y * ray->pos.y * ray->pos.y) +
		  (ray->dir.z * ray->dir.z * ray->pos.z * ray->pos.z)) -
    5.0 * (ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y *
	   ray->dir.z * ray->dir.z);
  sol[3] = 4 * (ray->pos.x * ray->pos.x * ray->pos.x * ray->dir.x +
		ray->pos.y * ray->pos.y * ray->pos.y * ray->dir.y +
		ray->pos.z * ray->pos.z * ray->pos.z * ray->dir.z) -
    10.0 * (ray->dir.x * ray->pos.x + ray->dir.y * ray->pos.y +
	    ray->dir.z * ray->pos.z);
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

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  get_dist_void_cube(ray, &inter);
  if (inter.dist == -1.0 || inter.dist == NOT_A_SOLUTION)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(mult_vec3(ray->dir, inter.dist), ray->pos);
  inter.norm.x = 4 * inter.pos.x * inter.pos.x * inter.pos.x -
    10.0 * inter.pos.x;
  inter.norm.x = 4 * inter.pos.y * inter.pos.y * inter.pos.y -
    10.0 * inter.pos.y;
  inter.norm.x = 4 * inter.pos.z * inter.pos.z * inter.pos.z -
    10.0 * inter.pos.z;
  return (inter);
}
