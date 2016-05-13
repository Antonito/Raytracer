/*
** klein.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 01:15:33 2016 Antoine Baché
** Last update Fri May 13 02:54:03 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

inline static double	calc_c_klein(t_ray *ray, t_vec3 *tmp, t_vec3 dir)
{
  return ((15 * tmp->z * tmp->z + 3 * tmp->y * tmp->y - 2 * tmp->y + 3 * tmp->x
	   * tmp->x - 11) * dir.z * dir.z +
	  ((24 * tmp->y - 8) * tmp->z *ray->dir.y + (24 * tmp->x * tmp->z + 16)
	   * ray->dir.x) * dir.z * ray->dir.z +
	  ((18 * tmp->z * tmp->z + 18 * tmp->y * tmp->y - 12 * tmp->y + 6 *
	    tmp->x * tmp->x - 18) * dir.y + (24 * tmp->x * tmp->y - 8 * tmp->x)
	   * ray->dir.x * ray->dir.y +
	   (18 * tmp->z * tmp->z + 6 * tmp->y * tmp->y - 4 * tmp->y + 18 *
	    tmp->x * tmp->x - 14) * dir.x) * dir.z +
	  ((24 * tmp->y - 8) * tmp->z * dir.y * ray->dir.y +
	   (24 * tmp->x * tmp->z + 16) * ray->dir.x * dir.y + (24 * tmp->y - 8)
	   * tmp->z * dir.x * ray->dir.y + (24 * tmp->x * tmp->z + 16) * dir.x *
	   ray->dir.x) * ray->dir.z +
	  (3 * tmp->z * tmp->z + 15 * tmp->y * tmp->y - 10 * tmp->y + 3 *
	   tmp->x * tmp->x - 7) * dir.y * dir.y +
	  (24 * tmp->x * tmp->y - 8 * tmp->x) * ray->dir.x * dir.y * ray->dir.y
	  + (6 * tmp->z * tmp->z + 18 * tmp->y * tmp->y - 12 * tmp->y + 18 *
	     tmp->x * tmp->x - 10) * dir.x * dir.y +
	  (24 * tmp->x * tmp->y - 8 * tmp->x) * dir.x * ray->dir.x * ray->dir.y
	  + (3 * tmp->z * tmp->z + 3 * tmp->y * tmp->y - 2 * tmp->y + 15 *
	     tmp->x * tmp->x - 3) * dir.x * dir.x);
}

inline static double	calc_b_klein(t_ray *ray, t_vec3 *tmp, t_vec3 dir)
{
  return (6 * tmp->z * dir.z * dir.z * ray->dir.z +
	  ((6 * tmp->y - 2) * ray->dir.y + 6 * tmp->x * ray->dir.x) * dir.z *
	  dir.z + (12 * tmp->z * dir.y + 12 * tmp->z * dir.x) * dir.z *
	  ray->dir.z + ((12 * tmp->y - 4) * dir.y * ray->dir.y + 12 * tmp->x *
			ray->dir.x * dir.y + (12 * tmp->y - 4) * dir.x *
			ray->dir.y + 12 * tmp->x * dir.x * ray->dir.x) * dir.z +
	  (6 * tmp->z * dir.y * dir.y + 12 * tmp->z * dir.x * dir.y + 6 *
	   tmp->z * dir.x * dir.x) * ray->dir.z + (6 * tmp->y - 2) * dir.y *
	  dir.y * ray->dir.y + 6 * tmp->x * ray->dir.x * dir.y * dir.y +
	  (12 * tmp->y - 4) * dir.x * dir.y * ray->dir.y + 12 * tmp->x *
	  dir.x * ray->dir.x * dir.y + (6 * tmp->y - 2) * dir.x * dir.x *
	  ray->dir.y + 6 * tmp->x * dir.x * dir.x * ray->dir.x);
}

inline static double	calc_a_klein(t_ray *ray, t_vec3 *tmp, t_vec3 dir)
{
  return (dir.z * dir.z * dir.z + (3 * dir.y + 3 * dir.x) * dir.z * dir.z +
	  (3 * dir.y * dir.y + 6 * dir.x * dir.y + 3 * dir.x * dir.x) * dir.z +
	  dir.y * dir.y * dir.y + 3 * dir.x * dir.y * dir.y + 3 * dir.x *
	  dir.x * dir.y + dir.x * dir.x * dir.x);
}

t_intersect		get_intersect_klein(t_obj *obj, t_ray *ray)
{
  t_intersect		inter;
  double		*coef;
  t_vec3		tmp;

  tmp = sub_vec3(ray->pos, obj->pos);
  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  if (!(coef = my_malloc(7 * sizeof(double))))
    return (inter);
  coef[0] = calc_a_klein(ray, &tmp, square_vec3(ray->dir));
  coef[1] = calc_b_klein(ray, &tmp, square_vec3(ray->dir));
  coef[2] = calc_c_klein(ray, &tmp, square_vec3(ray->dir));
  coef[3] = calc_d_klein(ray, &tmp, square_vec3(ray->dir), square_vec3(tmp));
  coef[4] = calc_e_klein(ray, &tmp, square_vec3(ray->dir), square_vec3(tmp));
  coef[5] = calc_f_klein(ray, &tmp, square_vec3(tmp));
  coef[6] = calc_g_klein(ray, &tmp, square_vec3(tmp));
  if ((inter.dist = solver_n_degree(coef, 6)) <= 0.0 ||
      inter.dist == NOT_A_SOLUTION)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(ray->pos, mult_vec3(ray->dir, inter.dist));
  calc_normale_klein(&inter);
  return (inter);
}
