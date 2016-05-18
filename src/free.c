/*
** free.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 10 09:31:47 2016 Antoine Baché
** Last update Wed May 18 12:29:44 2016 Antoine Baché
*/

#include "raytracer.h"
#include "tools/math.h"
#include "tools/memory.h"

#pragma message("Free data here !")
#pragma message("/!\\ Ply obj !!")
int		free_raytracer(t_data *data, int ret)
{
  t_scene	*tmp;
  t_scene	*prev;

  tmp = data->scene;
  while (tmp)
    {
      my_free(tmp->lights);
      my_free(tmp->mat);
      prev = tmp;
      tmp = tmp->next;
      my_free(prev);
    }
  my_free(data);
  my_sin(0.0, FREE);
  my_cos(0.0, FREE);
  return (ret);
}
