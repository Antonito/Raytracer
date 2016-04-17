/*
** camera.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:23:28 2016 Ludovic Petrenko
** Last update Sun Apr 17 16:38:51 2016 Ludovic Petrenko
*/

#ifndef CAMERA_H_
# define CAMERA_H_

# include "vector.h"

typedef struct	s_camera
{
  t_vec3	pos;
  t_vec3	dir;
  double        focale;
  double	fov;
}		t_camera;

#endif /* !CAMERA_H_ */
