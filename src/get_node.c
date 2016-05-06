/*
** get_node.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Wed Apr 20 20:28:51 2016 Ludovic Petrenko
** Last update Fri May  6 18:04:56 2016 Antoine Baché
*/

#include <math.h>
#include "raytracer.h"
#include "engine/octree.h"

bool	light_node(t_node *node, t_obj *obj)
{
  if (obj->pos.x >= node->min.x - obj->spec.light.radius &&
      obj->pos.x <= node->max.x + obj->spec.light.radius &&
      obj->pos.y >= node->min.y - obj->spec.light.radius &&
      obj->pos.y <= node->max.y + obj->spec.light.radius &&
      obj->pos.z >= node->min.z - obj->spec.light.radius &&
      obj->pos.z <= node->max.z + obj->spec.light.radius)
    return (true);
  return (false);
}

bool    sphere_node(t_node *node, t_obj *obj)
{
  if (obj->pos.x >= node->min.x - obj->spec.sphere.radius &&
      obj->pos.x <= node->max.x + obj->spec.sphere.radius &&
      obj->pos.y >= node->min.y - obj->spec.sphere.radius &&
      obj->pos.y <= node->max.y + obj->spec.sphere.radius &&
      obj->pos.z >= node->min.z - obj->spec.sphere.radius &&
      obj->pos.z <= node->max.z + obj->spec.sphere.radius)
    return (true);
  return (false);
}

bool		plane_node(UNUSED t_node *node, UNUSED t_obj *obj)
{
  return (true);
}

bool		cylinder_node(t_node *node, t_obj *obj)
{
  double	radius;

  radius = sqrt(obj->spec.cylinder.height * obj->spec.cylinder.height + 4 *
		obj->spec.cylinder.radius * obj->spec.cylinder.radius) / 2.0;
  if (obj->pos.x >= node->min.x - radius &&
      obj->pos.x <= node->max.x + radius &&
      obj->pos.y >= node->min.y - radius &&
      obj->pos.y <= node->max.y + radius &&
      obj->pos.z >= node->min.z - radius &&
      obj->pos.z <= node->max.z + radius)
    return (true);
  return (false);
}

bool		cone_node(t_node *node, t_obj *obj)
{
  double	radius;

  radius = sqrt(obj->spec.cone.height * obj->spec.cone.height + 4 *
		obj->spec.cone.radius * obj->spec.cone.radius) / 2.0;
  if (obj->pos.x >= node->min.x - radius &&
      obj->pos.x <= node->max.x + radius &&
      obj->pos.y >= node->min.y - radius &&
      obj->pos.y <= node->max.y + radius &&
      obj->pos.z >= node->min.z - radius &&
      obj->pos.z <= node->max.z + radius)
    return (true);
  return (false);
}
