/*
** free.c for Raytracer2 in /gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 10 09:31:47 2016 Antoine Baché
** Last update Sun May 22 18:34:39 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "tools/math.h"
#include "threadpool_raytracer.h"
#include "tools/memory.h"

#pragma message("Free data here !")
#pragma message("/!\\ Ply obj !!")

void	free_bsp(t_node *node)
{
  if (node->child[0])
    free_bsp(node->child[0]);
  if (node->child[1])
    free_bsp(node->child[1]);
  my_free(node);
}

void	free_scene(t_scene *scene)
{
  int	i;

  my_free(scene->zbuf);
  bunny_delete_clipable(&scene->cache->clipable);
  my_free(scene->mat);
  i = -1;
  while (++i < scene->nb_obj)
    {
      if (scene->objs[i].type == PLY)
	{
	  my_free(scene->objs[i].ply.objs);
	  free_bsp(scene->objs[i].ply.node);
	}
      if (scene->objs[i].tex)
	bunny_delete_clipable(&scene->objs[i].tex->clipable);
    }
  my_free(scene->objs);
  my_free(scene->lights);
  my_free(scene);
}

int		free_raytracer(t_data *data, int ret)
{
  t_scene	*cur;
  t_scene	*next;

  cur = data->scene;
  cur->prev->next = NULL;
  next = cur->next;
  printf("%p\n", cur);
  while (cur)
    {
      printf("FREE\n");
      next = cur->next;
      free_scene(cur);
      cur = next;
    }
  bunny_delete_clipable(&data->render->clipable);
  my_free(data);
  /* stop_threadpool(); */
  /* render_multithread(NULL, NULL, NB_FRAGMENT, FREE_T); */
  my_sin(0.0, FREE);
  my_cos(0.0, FREE);
  return (ret);
}
