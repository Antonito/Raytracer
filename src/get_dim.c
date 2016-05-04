/*
** get_dim.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed May  4 04:34:28 2016 Ludovic Petrenko
** Last update Wed May  4 04:58:32 2016 Ludovic Petrenko
*/

#include <math.h>
#include "raytracer.h"
#include "engine/octree.h"

void	light_dim(t_obj *obj, t_vec3 *dim)
{
  dim[0].x = obj->pos.x - obj->spec.light.radius;
  dim[0].y = obj->pos.y - obj->spec.light.radius;
  dim[0].z = obj->pos.z - obj->spec.light.radius;
  dim[1].x = obj->pos.x + obj->spec.light.radius;
  dim[1].y = obj->pos.y + obj->spec.light.radius;
  dim[1].z = obj->pos.z + obj->spec.light.radius;
}

void    sphere_dim(t_obj *obj, t_vec3 *dim)
{
  dim[0].x = obj->pos.x - obj->spec.sphere.radius;
  dim[0].y = obj->pos.y - obj->spec.sphere.radius;
  dim[0].z = obj->pos.z - obj->spec.sphere.radius;
  dim[1].x = obj->pos.x + obj->spec.sphere.radius;
  dim[1].y = obj->pos.y + obj->spec.sphere.radius;
  dim[1].z = obj->pos.z + obj->spec.sphere.radius;
}

/* bool		plane_node(t_node *node, t_obj *obj) */
/* { */
/*   double	d; */
/*   int		i; */
/*   double	a; */
/*   double	b; */
/*   t_vec3	corner; */

/*   d = -(obj->spec.plane.normale.x * obj->pos.x + obj->spec.plane.normale.y */
/* 	* obj->pos.y + obj->spec.plane.normale.z * obj->pos.z); */
/*   i = -1; */
/*   while (++i < 8) */
/*     { */
/*       corner.x = (i & HALF_X) ? node->max.x : node->min.x; */
/*       corner.y = (i & HALF_Y) ? node->max.y : node->min.y; */
/*       corner.z = (i & HALF_Z) ? node->max.z : node->min.z; */
/*       a = obj->spec.plane.normale.x * corner.x + obj->spec.plane.normale.y */
/* 	* corner.y + obj->spec.plane.normale.z * corner.z + d; */
/*       if (i && a * b <= 0.0) */
/* 	return (true); */
/*       b = a; */
/*     } */
/*   return (false); */
/* } */

void		cylinder_dim(t_obj *obj, t_vec3 *dim)
{
  double	radius;

  radius = sqrt(obj->spec.cylinder.height * obj->spec.cylinder.height + 4 *
		obj->spec.cylinder.radius * obj->spec.cylinder.radius) / 2.0;
  dim[0].x = obj->pos.x - radius;
  dim[0].y = obj->pos.y - radius;
  dim[0].z = obj->pos.z - radius;
  dim[1].x = obj->pos.x + radius;
  dim[1].y = obj->pos.y + radius;
  dim[1].z = obj->pos.z + radius;
}

void		cone_dim(t_obj *obj, t_vec3 *dim)
{
  double	radius;

  radius = sqrt(obj->spec.cone.height * obj->spec.cone.height + 4 *
		obj->spec.cone.radius * obj->spec.cone.radius) / 2.0;
  dim[0].x = obj->pos.x - radius;
  dim[0].y = obj->pos.y - radius;
  dim[0].z = obj->pos.z - radius;
  dim[1].x = obj->pos.x + radius;
  dim[1].y = obj->pos.y + radius;
  dim[1].z = obj->pos.z + radius;
}
