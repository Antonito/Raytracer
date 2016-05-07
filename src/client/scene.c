/*
** scene.c for Raytracer2 in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 20:23:15 2016 Antoine Baché
** Last update Sat May  7 21:02:17 2016 Antoine Baché
*/

#include "client.h"
#include "network.h"
#include "tools/memory.h"

static t_scene	*add_scene(t_scene *scene)
{
  t_scene	*new;

  if (!(new = my_calloc(1, sizeof(t_scene))))
    return (NULL);
  if (scene)
    {
      scene->next = new;
      new->prev = scene;
    }
  return (new);
}

t_scene		*get_scene(int fd)
{
  int		nb_scene;
  int		i;
  t_scene	*scene;

  if ((nb_scene = read_number(fd)) <= 0 ||
      send_ok(fd))
    return (NULL);
  scene = NULL;
  i = 0;
  while (i < nb_scene)
    {
      if (!(scene = add_scene(scene)) || get_camera(fd, scene) ||
	  get_objs(fd, scene) || get_lights(fd, scene) || get_mats(fd, scene) ||
	  get_specs(fd, scene))
	return (NULL);
      ++i;
    }
  return (scene);
}
