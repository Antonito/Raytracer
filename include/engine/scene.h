/*
** scene.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:53:20 2016 Ludovic Petrenko
** Last update Thu May 19 07:35:57 2016 Antoine Baché
*/

#ifndef SCENE_H_
# define SCENE_H_

# include <lapin.h>
# include "engine/camera.h"
# include "object.h"
# include "engine/octree.h"

# define DEFAULT_BG_COLOR	0x000000

typedef struct		s_scene_spec
{
  unsigned int		bg_color;
  double		ambiant;
}			t_scene_spec;

typedef struct		s_scene
{
  t_camera		cam;
  int			nb_obj;
  t_obj			*objs;
  int			nb_light;
  t_light		*lights;
  int			nb_mat;
  t_material		*mat;
  t_scene_spec		spec;
  t_bunny_pixelarray	*cache;
  float			*zbuf;
  t_node		octree;
  struct s_scene	*prev;
  struct s_scene	*next;
}			t_scene;

#endif /* !SCENE_H_ */
