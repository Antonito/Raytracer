/*
** launch.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 16 16:32:45 2016 Ludovic Petrenko
** Last update Sat May  7 00:32:51 2016 Antoine Baché
*/

#include <stdio.h>
#include <time.h>
#include "raytracer.h"

t_bunny_response	main_events(UNUSED t_bunny_event_state s,
				    UNUSED t_bunny_keysym k,
				    t_data *data)
{
  static const bool	*keys = NULL;

  if (!keys)
    keys = bunny_get_keyboard();
  (void)data;
  if (keys[BKS_ESCAPE])
    return (EXIT_ON_SUCCESS);
  if (keys[BKS_Z])
    data->scene->cam.pos = add_vec3(data->scene->cam.pos,
				    data->scene->cam.dir);
  if (keys[BKS_S])
    data->scene->cam.pos = sub_vec3(data->scene->cam.pos,
				    data->scene->cam.dir);
  if (keys[BKS_A])
    data->scene->cam.dir.z += 1.0;
  if (keys[BKS_E])
    data->scene->cam.dir.z -= 1.0;
  /* printf("%f %f %f\n", data->scene->cam.pos.x, data->scene->cam.pos.y, data->scene->cam.pos.z); */
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
  if (bunny_loop(data->win, 60, data) == EXIT_ON_ERROR)
    return (1);
  return (0);
}
