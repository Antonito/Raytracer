/*
** camera.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:23:28 2016 Ludovic Petrenko
** Last update Mon Apr 18 01:50:34 2016 Ludovic Petrenko
*/

#ifndef CAMERA_H_
# define CAMERA_H_

# include "vector.h"

# define DEFAULT_CAM_POS	vec3(0.0, -10.0, 0.0)
# define DEFAULT_CAM_DIR	vec3(0.0, 1.0, 1.0)
# define DEFAULT_CAM_FOCALE	10.0
# define DEFAULT_CAM_FOV	90.0

typedef struct	s_camera
{
  t_vec3	pos;
  t_vec3	dir;
  double        focale;
  double	fov;
}		t_camera;

#endif /* !CAMERA_H_ */
