/*
** get_dim.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed May  4 04:34:28 2016 Ludovic Petrenko
** Last update Sun May 22 19:57:57 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "engine/bsp.h"

void		light_dim(t_obj *obj, t_vec3 *dim)
{
  dim[0].x = obj->pos.x - obj->light.radius;
  dim[0].y = obj->pos.y - obj->light.radius;
  dim[0].z = obj->pos.z - obj->light.radius;
  dim[1].x = obj->pos.x + obj->light.radius;
  dim[1].y = obj->pos.y + obj->light.radius;
  dim[1].z = obj->pos.z + obj->light.radius;
}

void		sphere_dim(t_obj *obj, t_vec3 *dim)
{
  dim[0].x = obj->pos.x - obj->sphere.radius;
  dim[0].y = obj->pos.y - obj->sphere.radius;
  dim[0].z = obj->pos.z - obj->sphere.radius;
  dim[1].x = obj->pos.x + obj->sphere.radius;
  dim[1].y = obj->pos.y + obj->sphere.radius;
  dim[1].z = obj->pos.z + obj->sphere.radius;
}

void		cylinder_dim(t_obj *obj, t_vec3 *dim)
{
  double	radius;

  radius = sqrt(obj->cylinder.height * obj->cylinder.height + 4 *
		obj->cylinder.radius * obj->cylinder.radius) / 2.0;
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

  radius = sqrt(obj->cone.height * obj->cone.height + 4 *
		obj->cone.radius * obj->cone.radius) / 2.0;
  dim[0].x = obj->pos.x - radius;
  dim[0].y = obj->pos.y - radius;
  dim[0].z = obj->pos.z - radius;
  dim[1].x = obj->pos.x + radius;
  dim[1].y = obj->pos.y + radius;
  dim[1].z = obj->pos.z + radius;
}

void		torus_dim(t_obj *obj, t_vec3 *dim)
{
  double	radius;

  radius = obj->torus.radius_hole + obj->torus.radius_solid;
  dim[0].x = obj->pos.x - radius;
  dim[0].y = obj->pos.y - radius;
  dim[0].z = obj->pos.z - radius;
  dim[1].x = obj->pos.x + radius;
  dim[1].y = obj->pos.y + radius;
  dim[1].z = obj->pos.z + radius;
}
