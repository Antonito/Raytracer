/*
** klein.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon May  9 01:15:33 2016 Antoine Baché
** Last update Mon May 16 15:26:37 2016 Antoine Baché
*/

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"
#include "tools/memory.h"

inline static double	calc_c_more_klein(t_ray *ray, t_vec3 tmp, t_vec3 dir)
{
  return (-2.0 * dir.x * dir.y + 18.0 * tmp.x * tmp.x * dir.x * dir.y + 18.0 *
	  tmp.y * tmp.y * dir.x * dir.y + 6.0 * tmp.z * tmp.z * dir.x * dir.y +
	  12.0 * tmp.y * dir.x * dir.y - 10.0 * dir.x * dir.z + 18.0 * tmp.x *
	  tmp.x * dir.x * dir.z + 6.0 * tmp.y * tmp.y * dir.x * dir.z + 18.0 *
	  tmp.z * tmp.z * dir.x * dir.z + 4.0 * tmp.y * dir.x * dir.z - 10.0 *
	  dir.y * dir.z + 6.0 * tmp.x * tmp.x * dir.y * dir.z + 18.0 * tmp.y *
	  tmp.y * dir.y * dir.z + 18.0 * tmp.z * tmp.z * dir.y * dir.z + 12.0 *
	  tmp.y * dir.y * dir.z + 8.0 * tmp.x * ray->dir.x * ray->dir.y * dir.z
	  + 24.0 * tmp.x * tmp.y * ray->dir.x * ray->dir.y * dir.z + 8.0 *
	  tmp.x * ray->dir.x * dir.y * ray->dir.y + 24.0 * tmp.x * tmp.y *
	  ray->dir.x * dir.y * ray->dir.y + 16.0 * ray->dir.x * dir.z *
	  ray->dir.z);
}

inline static double	calc_c_klein(t_ray *ray, t_vec3 tmp, t_vec3 dir)
{
  return (calc_c_more_klein(ray, tmp, dir)
	  + 24.0 * tmp.x * tmp.z * ray->dir.x * dir.z * ray->dir.z +
	  8.0 * tmp.z * ray->dir.y * dir.z * ray->dir.z + 24.0 * tmp.y * tmp.z
	  * ray->dir.y * dir.z * ray->dir.z - dir.x * dir.x + 15.0 * tmp.x *
	  tmp.x * dir.x * dir.x + 3.0 * tmp.y * tmp.y * dir.x * dir.x + 3.0 *
	  tmp.z * tmp.z * dir.x * dir.x + 2.0 * tmp.y * dir.x * dir.x - dir.y *
	  dir.y + 3.0 * tmp.x * tmp.x * dir.y * dir.y + 15.0 * tmp.y * tmp.y *
	  dir.y * dir.y + 3.0 * tmp.z * tmp.z * dir.y * dir.y + 10.0 * tmp.y *
	  dir.y * dir.y + 3.0 * tmp.x * tmp.x * dir.z * dir.z + 3.0 * tmp.y *
	  tmp.y * dir.z * dir.z + 15.0 * tmp.z * tmp.z * dir.z * dir.z - 9.0 *
	  dir.z * dir.z + 2.0 * tmp.y * dir.z * dir.z + 8.0 * tmp.x * dir.x *
	  ray->dir.x * ray->dir.y + 24.0 * tmp.x * tmp.y * dir.x * ray->dir.x *
	  ray->dir.y + 16.0 * ray->dir.x * dir.y * ray->dir.z + 24.0 * tmp.x *
	  tmp.z * ray->dir.x * dir.y * ray->dir.z + 16.0 * dir.x * ray->dir.x *
	  ray->dir.z + 24.0 * tmp.x * tmp.z * dir.x * ray->dir.x * ray->dir.z +
	  8.0 * tmp.z * dir.y * ray->dir.y * ray->dir.z + 24.0 * tmp.y * tmp.z
	  * dir.y * ray->dir.y * ray->dir.z + 8.0 * tmp.z * dir.x * ray->dir.y
	  * ray->dir.z + 24.0 * tmp.y * tmp.z * dir.x * ray->dir.y * ray->dir.z);
}

inline static double	calc_b_klein(t_ray *ray, t_vec3 tmp, t_vec3 dir)
{
  return (12.0 * tmp.x * dir.x * ray->dir.x * dir.y + 12.0 * tmp.x * ray->dir.x
	  * dir.y * dir.z + 12.0 * tmp.x * dir.x * ray->dir.x * dir.z + 4.0 *
	  dir.y * ray->dir.y * dir.z + 12.0 * tmp.y * dir.y * ray->dir.y *
	  dir.z + 4.0 * dir.x * ray->dir.y * dir.z + 12.0 * tmp.y * dir.x *
	  ray->dir.y * dir.z + 4.0 * dir.x * dir.y * ray->dir.y + 12.0 * tmp.y
	  * dir.x * dir.y * ray->dir.y + 12.0 * tmp.z * dir.x * dir.z *
	  ray->dir.z + 12.0 * tmp.z * dir.y * dir.z * ray->dir.z + 6.0 * tmp.x
	  * ray->dir.x * dir.y * dir.y + 6.0 * tmp.x * ray->dir.x * dir.z *
	  dir.z + 2.0 * ray->dir.y * dir.z * dir.z + 6.0 * tmp.y * ray->dir.y *
	  dir.z * dir.z + 6.0 * tmp.x * dir.x * dir.x * ray->dir.x + 2.0 *
	  dir.y * dir.y * ray->dir.y + 6.0 * tmp.y * dir.y * dir.y * ray->dir.y
	  + 6.0 * tmp.z * dir.z * dir.z * ray->dir.z + 2.0 * dir.x * dir.x *
	  ray->dir.y +
	  6.0 * tmp.y * dir.x * dir.x * ray->dir.y + 12.0 * tmp.z * dir.x *
	  dir.y * ray->dir.z + 6.0 * tmp.z * dir.x * dir.x * ray->dir.z + 6.0 *
	  tmp.z * dir.y * dir.y * ray->dir.z);
}

inline static double	calc_a_klein(t_ray *ray)
{
  return (3.0 * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.x * ray->dir.y
	  * ray->dir.y + 6.0 * ray->dir.x * ray->dir.x * ray->dir.y * ray->dir.y
	  * ray->dir.z * ray->dir.z + 3.0 * ray->dir.x * ray->dir.x * ray->dir.x
	  * ray->dir.x * ray->dir.z * ray->dir.z + 3.0 * ray->dir.y * ray->dir.y
	  * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z + 3.0 * ray->dir.x
	  * ray->dir.x * ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + 3.0
	  * ray->dir.x * ray->dir.x * ray->dir.z * ray->dir.z * ray->dir.z *
	  ray->dir.z + 3.0 * ray->dir.y * ray->dir.y * ray->dir.z * ray->dir.z
	  * ray->dir.z * ray->dir.z + ray->dir.x * ray->dir.x * ray->dir.x *
	  ray->dir.x * ray->dir.x * ray->dir.x + ray->dir.y * ray->dir.y *
	  ray->dir.y * ray->dir.y * ray->dir.y * ray->dir.y + ray->dir.z *
	  ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z * ray->dir.z);
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
  coef[0] = calc_a_klein(ray);
  coef[1] = calc_b_klein(ray, tmp, square_vec3(ray->dir));
  coef[2] = calc_c_klein(ray, tmp, square_vec3(ray->dir));
  coef[3] = calc_d_klein(ray, tmp, square_vec3(ray->dir), square_vec3(tmp));
  coef[4] = calc_e_klein(ray, tmp, square_vec3(ray->dir), square_vec3(tmp));
  coef[5] = calc_f_klein(ray, tmp, square_vec3(tmp));
  coef[6] = calc_g_klein(ray, tmp, square_vec3(tmp));
  if ((inter.dist = solver_n_degree(coef, 6)) < 0.0)
    {
      inter.dist = -1.0;
      return (inter);
    }
  inter.pos = add_vec3(ray->pos, mult_vec3(ray->dir, inter.dist));
  calc_normale_klein(&inter);
  return (inter);
}
