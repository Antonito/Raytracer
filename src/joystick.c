/*
** joystick.c for Raytracer2 in /home/asphahyre/rendu/gfx_raytracer2/src
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Mon May 16 16:16:01 2016 Luka Boulagnon
** Last update Mon May 16 19:56:22 2016 Luka Boulagnon
*/

#include <sys/time.h>
#include "raytracer.h"
#include "tools/math.h"

t_bunny_response	joystick_connected(t_bunny_event_state state,
					   int joyid,
					   const t_bunny_joystick joy,
					   void *data)
{
  (void)state;
  (void)joyid;
  (void)joy;
  (void)data;
  return (GO_ON);
}

t_bunny_response	joystick_axises(int UNUSED joyid, t_bunny_axis axis,
					float value, t_data UNUSED *data)
{
  data->joy.needed_fps = value / 10;
  if (axis == 0)
    data->joy.lat = value / -20000000.0;
  else if (axis == 1)
    data->joy.lon = -value / -20000000.0;
  else if (axis == 2)
    data->joy.hor = value / -3200000.0;
  else if (axis == 3)
    data->joy.ver = value / -3200000.0;
  return (GO_ON);
}

t_bunny_response	joystick_buttons(t_bunny_event_state state,
					 int joyid, int button, t_data *data)
{
  (void)state;
  (void)joyid;
  (void)button;
  (void)data;
  return (GO_ON);
}

void			joy_proceed_moves(t_data *data)
{
  t_vec3		lateral;
  t_vec3		cam;
  double		lost_time;
  static struct timeval	lastcall = {0, 0};
  struct timeval	new;

  cam = data->scene->cam.dir;
  lateral = (t_vec3){cam.y, -cam.x, 0};
  new = lastcall;
  gettimeofday(&lastcall, NULL);
  lost_time = new.tv_sec * 1000000 + new.tv_usec
    - lastcall.tv_sec * 1000000 - lastcall.tv_usec;
  data->scene->cam.pos = add_vec3(data->scene->cam.pos,
				  mult_vec3(cam, data->joy.lon * lost_time));
  data->scene->cam.pos = add_vec3(data->scene->cam.pos,
				  mult_vec3(lateral,
					    data->joy.lat * lost_time));
  data->scene->cam.rot_x += data->joy.hor * lost_time;
  data->scene->cam.rot_y += data->joy.ver * lost_time;
  data->scene->cam.rot_y = MAX(data->scene->cam.rot_y, -90.0);
  data->scene->cam.rot_y = MIN(data->scene->cam.rot_y, 90.0);
  refresh_forward(&data->scene->cam);
}
