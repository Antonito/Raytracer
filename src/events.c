/*
** events.c for Raytracer2 in /home/bache_a/work/Infographie/gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May 22 19:59:54 2016 Antoine Baché
** Last update Sun May 22 23:41:02 2016 Antoine Baché
*/

#include "raytracer.h"
#include "tools/math.h"

t_bunny_response	events(t_data *data)
{
  static const bool	*keys = NULL;

  if (!keys)
    keys = bunny_get_keyboard();
  if (keys[BKS_ESCAPE] && !data->rendering)
    return (EXIT_ON_SUCCESS);
  if (keys[BKS_E] && !data->config.minimum_fps && !data->rendering)
    save_bmp(data->render, "./raytracer.bmp");
  if (keys[BKS_Z] && data->config.minimum_fps)
    data->scene->cam.pos = add_vec3(data->scene->cam.pos,
				    mult_vec3(data->scene->cam.dir, 0.2));
  if (keys[BKS_S] && data->config.minimum_fps)
    data->scene->cam.pos = sub_vec3(data->scene->cam.pos,
				    mult_vec3(data->scene->cam.dir, 0.2));
  else if (keys[BKS_PAGEUP])
    ++data->config.minimum_fps;
  else if (keys[BKS_PAGEDOWN] && data->config.minimum_fps > 1)
    --data->config.minimum_fps;
  data->config.minimum_fps = (data->config.minimum_fps > 0) ?
    data->config.minimum_fps : 0;
  return (GO_ON);
}

t_bunny_response	main_events(t_bunny_event_state s,
				    t_bunny_keysym k,
				    t_data *data)
{
  static const bool	*keys = NULL;

  if (!keys)
    keys = bunny_get_keyboard();
  if (s == GO_DOWN && k == BKS_ESCAPE && !data->rendering)
    return (EXIT_ON_SUCCESS);
  if (s == GO_DOWN && k == BKS_HOME && !data->rendering)
    data->config.minimum_fps = DEFAULT_FPS;
  if (s == GO_DOWN && k == BKS_END)
    data->config.minimum_fps = 0;
  if (s == GO_DOWN && k == BKS_PAGEUP)
    ++data->config.minimum_fps;
  if (s == GO_DOWN && k == BKS_PAGEDOWN)
    --data->config.minimum_fps;
  if (data->config.minimum_fps < 0)
    data->config.minimum_fps = 0;
  if (s == GO_DOWN && keys[BKS_SPACE] &&
      k == BKS_LEFT && data->config.minimum_fps)
    data->scene = data->scene->prev;
  if (s == GO_DOWN && keys[BKS_SPACE] &&
      k == BKS_RIGHT && data->config.minimum_fps)
    data->scene = data->scene->next;
  if (s == GO_DOWN && k == BKS_DELETE && data->config.minimum_fps)
    delete_object(data->scene);
  return (GO_ON);
}

t_bunny_response	mouse_response(const t_bunny_position *rel,
				       t_data *data)
{
  const bool		*button;

  button = bunny_get_mouse_button();
  if (button[BMB_LEFT] && data->config.minimum_fps)
    {
      data->scene->cam.rot_x += rel->x / 5.0;
      data->scene->cam.rot_y += rel->y / 5.0;
      data->scene->cam.rot_y = MAX(data->scene->cam.rot_y, -89.99);
      data->scene->cam.rot_y = MIN(data->scene->cam.rot_y, 89.99);
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

  if (sta == GO_DOWN && but == BMB_RIGHT && data->config.minimum_fps)
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
