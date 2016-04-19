/*
** scene.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:53:20 2016 Ludovic Petrenko
** Last update Mon Apr 18 01:48:46 2016 Ludovic Petrenko
*/

#ifndef SCENE_H_
# define SCENE_H_

# include <lapin.h>
# include "camera.h"
# include "object.h"

# define DEFAULT_BG_COLOR	0x000000

typedef struct		s_scene
{
  t_camera		cam;
  t_obj			**objs;
  int			nb_light;
  t_light		**lights;
  t_bunny_pixelarray	*cache;
  struct s_scene	*prev;
  struct s_scene	*next;
}			t_scene;

#endif /* !SCENE_H_ */
