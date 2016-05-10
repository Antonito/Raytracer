/*
** free.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 10 09:31:47 2016 Antoine Baché
** Last update Tue May 10 09:33:23 2016 Antoine Baché
*/

#include "raytracer.h"
#include "tools/math.h"
#include "tools/memory.h"

#pragma message("Free data here !")
int	free_raytracer(t_data *data, int ret)
{
  (void)data;
  my_sin(0.0, FREE);
  my_cos(0.0, FREE);
  return (ret);
}
