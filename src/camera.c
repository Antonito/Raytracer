/*
** camera.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri May  6 16:20:03 2016 Ludovic Petrenko
** Last update Tue May 10 09:38:38 2016 Antoine Baché
*/

#include <math.h>
#include "engine/camera.h"
#include "tools/math.h"

void	refresh_forward(t_camera *cam)
{
  cam->dir.x = -my_sin(cam->rot_x * M_PI / 180.0, DRAW);
  cam->dir.y = my_cos(cam->rot_x * M_PI / 180.0, DRAW) *
    my_cos(cam->rot_y * M_PI / 180.0, DRAW);
  cam->dir.z = my_sin(cam->rot_y * M_PI / 180.0, DRAW);
}
