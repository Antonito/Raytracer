/*
** launch.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 16 16:32:45 2016 Ludovic Petrenko
** Last update Sun May 22 22:44:17 2016 Ludovic Petrenko
*/

#include <stdio.h>
#include <time.h>
#include "raytracer.h"
#include "network.h"
#include "tools/math.h"
#include "threadpool.h"

t_bunny_response	main_loop(t_data *data)
{
  static int		t = 0;
  static int		fps = 1;

  if (t != time(NULL) && (fps || !data->config.minimum_fps))
    {
      t = time(NULL);
      refresh_size(data, fps);
      fps = 0;
    }
  else
    ++fps;
  if (events(data) != GO_ON)
    return (EXIT_ON_SUCCESS);
  set_frame(data);
  joy_proceed_moves(data);
  data->scene->cache->clipable.clip_width = data->config.cur_width;
  data->scene->cache->clipable.clip_height = data->config.cur_height;
  blit_scaled(data->scene->cache, data->render);
  if (data->effect != NO_EFFECT && !data->config.minimum_fps)
    apply_effect(data->render, data->effect, data);
  if (!data->config.minimum_fps)
    antialiasing(data->render, 2);
  bunny_blit(&data->win->buffer, &data->render->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

int	launch_raytracer(t_data *data)
{
  data->config.cur_width = data->config.width / 10;
  data->config.cur_height = data->config.height / 10;
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_set_key_response((t_bunny_key)main_events);
  bunny_set_move_response((t_bunny_move)mouse_response);
  bunny_set_click_response((t_bunny_click)click_response);
  bunny_set_joy_axis_response((t_bunny_joy_axis)joystick_axises);
  bunny_set_joy_button_response((t_bunny_joy_button)joystick_buttons);
  bunny_set_joy_connect_response((t_bunny_joy_connect)joystick_connected);
  if (bunny_loop(data->win, 120, data) == EXIT_ON_ERROR)
    return (free_raytracer(data, 1));
  return (free_raytracer(data, 0));
}
