/*
** delete_object.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun May 22 01:04:43 2016 Ludovic Petrenko
** Last update Sun May 22 01:09:26 2016 Ludovic Petrenko
*/

#include "engine/scene.h"

void	delete_object(t_scene *scene)
{
  t_obj	*obj;

  if (!(obj = scene->select))
    return ;
  obj->type = NONE;
}
