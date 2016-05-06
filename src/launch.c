/*
** launch.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 16 16:32:45 2016 Ludovic Petrenko
** Last update Sat May  7 01:13:17 2016 Antoine Baché
*/

#include <stdio.h>
#include <time.h>
#include "raytracer.h"
#include "tools/math.h"

t_bunny_response	main_events(UNUSED t_bunny_event_state s,
				    UNUSED t_bunny_keysym k,
				    t_data *data)
{
  static const bool	*keys = NULL;

  if (!keys)
    keys = bunny_get_keyboard();
  if (keys[BKS_ESCAPE])
    return (EXIT_ON_SUCCESS);
  if (keys[BKS_Z])
    data->scene->cam.pos = add_vec3(data->scene->cam.pos,
				    data->scene->cam.dir);
  if (keys[BKS_S])
    data->scene->cam.pos = sub_vec3(data->scene->cam.pos,
				    data->scene->cam.dir);
  /* printf("%f %f %f\n", data->scene->cam.pos.x, data->scene->cam.pos.y, data->scene->cam.pos.z); */
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

t_bunny_response	click_response(t_bunny_event_state sta,
				       t_bunny_mouse_button but,
				       t_data *data)
{
  return (GO_ON);
}

t_bunny_response	main_loop(t_data *data)
{
  static int		t = 0;
  static int		fps = 0;

  if (t != time(NULL))
    {
      t = time(NULL);
      /* printf("\r%d    ", fps); */
      /* fflush(stdout); */
      fps = 0;
    }
  else
    fps++;
  set_frame(data);
  return (GO_ON);
}

int	launch_raytracer(t_data *data)
{
  bunny_set_loop_main_function((t_bunny_loop)main_loop);
  bunny_set_key_response((t_bunny_key)main_events);
  bunny_set_move_response((t_bunny_move)mouse_response);
  bunny_set_click_response((t_bunny_click)click_response);
  if (bunny_loop(data->win, 60, data) == EXIT_ON_ERROR)
    return (1);
  return (0);
}
