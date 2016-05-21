/*
** normale_generic.c for Raytracer2 in /gfx_raytracer2/src/shape
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May 21 13:38:07 2016 Antoine Baché
** Last update Sat May 21 14:47:37 2016 Antoine Baché
*/

#include "engine/intersect.h"

inline static void	calc_tmp_normal(t_vec3 *tmp, t_intersect *inter)
{
  tmp->x = inter->pos.x * inter->pos.x;
  tmp->y = inter->pos.y * inter->pos.y;
  tmp->z = inter->pos.z * inter->pos.z;
}

inline static void	update_inter_normal(t_intersect *inter, t_vec3 *ori,
					    double a, double b)
{
  inter->pos.x = ori->x + a;
  inter->pos.y = ori->y + b;
}

inline static void	calc_new_pts_normal(double (*calc_x)(),
					    double (*calc_y)(),
					    double (*calc_z)(),
					    t_vec3 **arg)
{
  t_vec3		*d;
  t_vec3		*ori;
  t_vec3		tmp;
  t_intersect		inter;

  d = arg[0];
  ori = arg[1];
  update_inter_normal(&inter, ori, 0.000000001, 0.000000001);
  inter.pos.z = -(d[0].x * (inter.pos.x - ori->x) + d[0].y *
  		  (inter.pos.y - ori->y)) / d[0].z + ori->z;
  calc_tmp_normal(&tmp, &inter);
  d[1].x = calc_x(&inter, tmp);
  d[1].y = calc_y(&inter, tmp);
  d[1].z = calc_z(&inter, tmp);
  update_inter_normal(&inter, ori, -0.000000001, -0.000000002);
  inter.pos.z = -(d[0].x * (inter.pos.x - ori->x) + d[0].y *
  		  (inter.pos.y - ori->y)) / d[0].z + ori->z;
  calc_tmp_normal(&tmp, &inter);
  d[2].x = calc_x(&inter, tmp);
  d[2].y = calc_y(&inter, tmp);
  d[2].z = calc_z(&inter, tmp);
}

void			calc_normale(double (*calc_x)(), double (*calc_y)(),
				     double (*calc_z)(), t_intersect *inter)
{
  t_vec3		d[3];
  t_vec3		v[2];
  t_vec3		tmp;

  calc_tmp_normal(&tmp, inter);
  d[0].x = calc_x(inter, tmp);
  d[0].y = calc_y(inter, tmp);
  d[0].z = calc_z(inter, tmp);
  calc_new_pts_normal(calc_x, calc_y, calc_z, (t_vec3*[2]){d, &inter->pos});
  v[0] = sub_vec3(d[1], d[0]);
  v[1] = sub_vec3(d[2], d[0]);
  inter->norm = vec3_normalize(cross_vec3(v[0], v[1]));
}
