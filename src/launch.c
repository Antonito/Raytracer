/*
** launch.c for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 16 16:32:45 2016 Ludovic Petrenko
** Last update Sat May 21 15:33:54 2016 Ludovic Petrenko
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
  else if (keys[BKS_PAGEUP])
    ++data->config.minimum_fps;
  else if (keys[BKS_PAGEDOWN])
    --data->config.minimum_fps;
  data->config.minimum_fps = (data->config.minimum_fps > 0) ?
    data->config.minimum_fps : 0;
  return (GO_ON);
}

t_bunny_response	main_events(t_bunny_event_state s,
				    t_bunny_keysym k,
				    UNUSED t_data *data)
{
  if (s == GO_DOWN && k == BKS_ESCAPE)
    return (EXIT_ON_SUCCESS);
  if (s == GO_DOWN && k == BKS_HOME)
    data->config.minimum_fps = DEFAULT_FPS;
  if (s == GO_DOWN && k == BKS_END)
    data->config.minimum_fps = 0;
  if (s == GO_DOWN && k == BKS_PAGEUP)
    ++data->config.minimum_fps;
  if (s == GO_DOWN && k == BKS_PAGEDOWN)
    --data->config.minimum_fps;
  if (data->config.minimum_fps < 0)
    data->config.minimum_fps = 0;
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
  t_ray		ray;
  t_intersect	inter;
  t_ivec2	pix;

  if (sta == GO_DOWN && but == BMB_RIGHT)
    {
      pix = *(bunny_get_mouse_position());
      pix.x *= 1.0 * data->config.cur_width / data->config.width;
      pix.y *= 1.0 * data->config.cur_height / data->config.height;
      ray.pos = data->scene->cam.pos;
      ray.dir = add_vec3(data->scene->cam.origin,
			 mult_vec3(data->scene->cam.incr_x, pix.x));
      ray.dir = add_vec3(ray.dir, mult_vec3(data->scene->cam.incr_y, pix.y));
      ray.dir = vec3_normalize(sub_vec3(ray.dir, ray.pos));
      scene_intersect(data->scene, &ray, &inter);
      if (inter.dist > 0.0001 && inter.dist < INFINITY &&
	  data->scene->select != inter.obj)
	data->scene->select = inter.obj;
      else
	data->scene->select = NULL;
    }
  return (GO_ON);
}

t_bunny_response	main_loop(t_data *data)
{
  static int		t = 0;
  static int		fps = 1;

  if (t != time(NULL) && (fps || !data->config.minimum_fps))
    {
      t = time(NULL);
      refresh_size(data, fps);
      fflush(stdout);
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
  /* if (data->config.minimum_fps == 0) */
  /*   focale(data); */
  if (data->effect != NO_EFFECT)
    apply_effect(data->render, data->effect, data);
  bunny_blit(&data->win->buffer, &data->render->clipable, NULL);
  bunny_display(data->win);
  return (GO_ON);
}

void	print_ply(t_ply *ply)
{
  printf("=============================\n");
  printf("              PLY\n");
  printf("=============================\n");
  printf("Nb_vertex: %d\n", ply->nb_vertex);
  printf("Nb_face: %d\n", ply->nb_face);
  int	i = 0;
  while (i < ply->nb_vertex)
    {
      printf("Vertex %d : %f %f %f\n", i, ply->list_vertex[i].vec.x, ply->list_vertex[i].vec.y, ply->list_vertex[i].vec.z);
      ++i;
    }
  i = 0;
  int	j;
  while (i < ply->nb_face)
    {
      j = 0;
      while (j < ply->list_face[i].nb_face)
	{
	  printf("Face %d : %d\n", i, ply->list_face[i].face[j]);
	  ++j;
	}
      ++i;
    }
}

int	launch_raytracer(t_data *data)
{
  data->config.cur_width = data->config.width / 10;
  data->config.cur_height = data->config.height / 10;
  print_scenes(data->scene);
  /* printf("Objs[1]Type = %d\n", data->scene->objs[1].type); */
  /* print_ply(data->scene->objs[1].ply.ply); */
  if (init_server(data))
    return (free_raytracer(data, 1));
  printf("Starting to draw\n");
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
