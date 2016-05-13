/*
** launch.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 16 16:32:45 2016 Ludovic Petrenko
** Last update Fri May 13 15:10:16 2016 Antoine Baché
*/

#include <stdio.h>
#include <time.h>
#include "raytracer.h"
#include "network.h"
#include "tools/math.h"

t_bunny_response	events(t_data *data)
{
  static const bool	*keys = NULL;

  if (!keys)
    keys = bunny_get_keyboard();
  if (keys[BKS_ESCAPE])
    return (EXIT_ON_SUCCESS);
  if (keys[BKS_Z])
    data->scene->cam.pos = add_vec3(data->scene->cam.pos,
				    mult_vec3(data->scene->cam.dir, 0.2));
  if (keys[BKS_S])
    data->scene->cam.pos = sub_vec3(data->scene->cam.pos,
				    mult_vec3(data->scene->cam.dir, 0.2));
  return (GO_ON);
}

t_bunny_response	main_events(t_bunny_event_state s,
				    t_bunny_keysym k,
				    UNUSED t_data *data)
{
  if (s == GO_DOWN && k == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  return (GO_ON);
}

t_bunny_response	mouse_response(const t_bunny_position *rel,
				       t_data *data)
{
  const bool		*button;

  button = bunny_get_mouse_button();
  if (button[BMB_LEFT])
    {
      data->scene->cam.rot_x += rel->x / 5.0;
      data->scene->cam.rot_y += rel->y / 5.0;
      data->scene->cam.rot_y = MAX(data->scene->cam.rot_y, -90.0);
      data->scene->cam.rot_y = MIN(data->scene->cam.rot_y, 90.0);
      refresh_forward(&data->scene->cam);
    }
  return (GO_ON);
}

t_bunny_response	click_response(UNUSED t_bunny_event_state sta,
				       UNUSED t_bunny_mouse_button but,
				       UNUSED t_data *data)
{
  return (GO_ON);
}

t_bunny_response	main_loop(t_data *data)
{
  static int		t = 0;
  static int		fps = MINIMUM_FPS / 4;

  if (t != time(NULL))
    {
      t = time(NULL);
      refresh_size(data, fps);
      printf("\r%d    ", fps);
      fflush(stdout);
      fps = 0;
    }
  else
    fps++;
  if (events(data) != GO_ON)
    return (EXIT_ON_SUCCESS);
  set_frame(data);
  data->scene->cache->clipable.clip_width = data->cur_width;
  data->scene->cache->clipable.clip_height = data->cur_height;
  blit_scaled(data->scene->cache, data->render);
  bunny_blit(&data->win->buffer, &data->render->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

int	launch_raytracer(t_data *data)
{
  data->cur_width = data->width / 2;
  data->cur_height = data->height / 2;
  print_scenes(data->scene);
  if (init_server(data))
    return (free_raytracer(data, 1));
  printf("Starting to draw\n");
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_set_key_response((t_bunny_key)main_events);
  bunny_set_move_response((t_bunny_move)mouse_response);
  bunny_set_click_response((t_bunny_click)click_response);
  if (bunny_loop(data->win, 120, data) == EXIT_ON_ERROR)
    return (free_raytracer(data, 1));
  return (free_raytracer(data, 0));
}
