/*
** camera.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri May  6 16:20:03 2016 Ludovic Petrenko
** Last update Fri May  6 16:39:02 2016 Ludovic Petrenko
*/

#include <math.h>
#include "engine/camera.h"

void	refresh_forward(t_camera *cam)
{
  cam->dir.x = -sin(cam->rot_x * M_PI / 180.0);
  cam->dir.y = cos(cam->rot_x * M_PI / 180.0) *
    cos(cam->rot_y * M_PI / 180.0);
  cam->dir.z = sin(cam->rot_y * M_PI / 180.0);
}
