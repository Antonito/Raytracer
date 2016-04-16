/*
** launch.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 16 16:32:45 2016 Ludovic Petrenko
** Last update Sat Apr 16 18:14:06 2016 Ludovic Petrenko
*/

#include "raytracer.h"

t_bunny_response	main_events(t_bunny_event_state s,
				    t_bunny_keysym k,
				    t_data *data)
{
  return (GO_ON);
}

t_bunny_response	main_loop(t_data *data)
{
  /*  set_frame(data);*/
  return (GO_ON);
}

int	launch_raytracer(t_data *data)
{
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_set_key_response((t_bunny_key)main_events);
  if (bunny_loop(data->win, 60, data) == EXIT_ON_ERROR)
    return (1);
  return (0);
}
