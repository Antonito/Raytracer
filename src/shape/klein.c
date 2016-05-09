/*
** klein.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 01:15:33 2016 Antoine Baché
** Last update Mon May  9 05:25:39 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

inline static double	calc_c_klein_more(t_ray *ray)
{
  return ((15 * ray->pos.z * ray->pos.z + 3 * ray->pos.y * ray->pos.y - 2 *
	   ray->pos.y + 3 * ray->pos.x * ray->pos.x - 11) * ray->dir.z *
	  ray->dir.z * ray->dir.z * ray->dir.z +
	  ((24 * ray->pos.y - 8) * ray->pos.z * ray->dir.y +
	   (24 * ray->pos.x * ray->pos.z + 16) * ray->dir.x) * ray->dir.z *
	  ray->dir.z * ray->dir.z +
    	  ((18 * ray->pos.z * ray->pos.z + 18 * ray->pos.y * ray->pos.y - 12 *
	    ray->pos.y + 6 * ray->pos.x * ray->pos.x - 18) * ray->dir.y *
	   ray->dir.y + (24 * ray->pos.x * ray->pos.y - 8 * ray->pos.x) *
	   ray->dir.x * ray->dir.y +
	   (18 * ray->pos.z * ray->pos.z + 6 * ray->pos.y * ray->pos.y - 4 *
	    ray->pos.y + 18 * ray->pos.x * ray->pos.x - 14) * ray->dir.x *
	   ray->dir.x) * ray->dir.z * ray->dir.z);
}

inline static double	calc_c_klein(t_ray *ray)
{
  return (calc_c_klein_more(ray) +
	  ((24 * ray->pos.y - 8) *ray->pos.z * ray->dir.y * ray->dir.y *
	   ray->dir.y + (24 * ray->pos.x * ray->pos.z + 16) * ray->dir.x *
	   ray->dir.y * ray->dir.y + (24 * ray->pos.y - 8) * ray->pos.z *
	   ray->dir.x * ray->dir.x * ray->dir.y + (24 * ray->pos.x * ray->pos.z
						   + 16) * ray->dir.x *
	   ray->dir.x * ray->dir.x) * ray->dir.z +
	  (3 * ray->pos.z * ray->pos.z+ 14 * ray->pos.y * ray->pos.y - 10 *
	   ray->pos.y + 3 * ray->pos.x * ray->pos.x - 7) * ray->dir.y *
	  ray->dir.y * ray->dir.y * ray->dir.y +
	  (24 * ray->pos.x * ray->pos.y - 8 * ray->pos.x) * ray->dir.x *
	  ray->dir.y * ray->dir.y * ray->dir.y + (6 * ray->pos.z * ray->pos.z +
						  18 * ray->pos.y * ray->pos.y -
						  12 * ray->pos.y + 18 *
						  ray->pos.x * ray->pos.x - 10)
	  * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y +
	  (24 * ray->pos.x * ray->pos.y - 8 * ray->pos.x) * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.y +
	  (3 * ray->pos.z * ray->pos.z *  + 3 * ray->pos.y * ray->pos.y - 2 *
	   ray->pos.y + 15 * ray->pos.x * ray->pos.x - 3) * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.x);
}

inline static double	calc_b_klein(t_ray *ray)
{
  double		dirzsquare;
  double		dirysquare;
  double		dirxsquare;

  dirzsquare = ray->dir.z * ray->dir.z;
  dirysquare = ray->dir.y * ray->dir.y;
  dirxsquare = ray->dir.x * ray->dir.x;
  return (6 * ray->pos.z * dirzsquare * dirzsquare * ray->dir.z +
	  ((6 * ray->pos.y - 2) * ray->dir.y + 6 * ray->pos.x * ray->dir.x) *
	  dirzsquare *  dirzsquare +
	  (12 * ray->pos.z * dirysquare + 12 * ray->pos.z * dirxsquare) *
	  dirzsquare * ray->dir.z +
	  ((12 * ray->pos.y - 4) * dirysquare * ray->dir.y + 12 *
	   ray->pos.x * ray->dir.x * dirysquare +
	   (12 * ray->pos.y - 4 * dirxsquare * ray->dir.y + 12 *
	    ray->pos.x * dirxsquare * ray->dir.x) * dirzsquare +
	   (6 * ray->pos.z * dirysquare * dirysquare + 12 *
	    ray->pos.z * dirxsquare * dirysquare + 6 * ray->pos.z
	    * dirxsquare * dirxsquare) * ray->dir.z + (6 * ray->pos.y - 2) *
	   dirysquare * dirysquare * ray->dir.y + 6 * ray->pos.x *
	   ray->dir.x * dirysquare * dirysquare + (12 * ray->pos.y - 4) *
	   dirxsquare * ray->dir.y * dirysquare + 12 * ray->pos.x * dirxsquare *
	   ray->dir.x * dirysquare + (6 * ray->pos.y - 2) * dirxsquare *
	   dirxsquare * ray->dir.y + 6 * ray->pos.x * dirxsquare * dirxsquare *
	   ray->dir.x));
}

inline static double	calc_a_klein(t_ray *ray)
{
  double		dirzsquare;
  double		dirysquare;
  double		dirxsquare;

  dirzsquare = ray->dir.z * ray->dir.z;
  dirysquare = ray->dir.y * ray->dir.y;
  dirxsquare = ray->dir.x * ray->dir.x;
  return (ray ->dir.z * dirzsquare * dirzsquare * ray->dir.z  +
	  (3 * dirysquare + 3 * dirzsquare) * dirzsquare * dirzsquare +
	  (3 * dirysquare * dirysquare +
	   6 * dirxsquare * dirysquare +
	   3 * dirxsquare * dirxsquare) * dirzsquare + dirysquare * ray->dir.y *
	  dirysquare * ray->dir.y + 3 * dirxsquare * dirysquare * dirysquare +
	  3 * ray->dir.x * dirxsquare * ray->dir.x * dirysquare +
	  dirxsquare * dirxsquare * dirxsquare);
}

t_intersect		get_intersect_klein(t_obj *obj, t_ray *ray)
{
  t_intersect		inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  if ((inter.dist = solver_n_degree((double [6]){
	  calc_a_klein(ray), calc_b_klein(ray), calc_c_klein(ray),
	    calc_d_klein(ray), calc_e_klein(ray), calc_f_klein(ray),
	    calc_g_klein(ray)}, 6)) <= 0.0 ||
    inter.dist == NOT_A_SOLUTION)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(ray->pos, mult_vec3(ray->dir, inter.dist));
  return (inter);
}
