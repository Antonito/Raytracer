/*
** build_obj.c for Raytracer2 in /gfx_raytracer2/src/ply
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 17 17:56:10 2016 Antoine Baché
** Last update Tue May 17 18:23:32 2016 Antoine Baché
*/

#include "engine/object.h"
#include "tools/memory.h"

static int	count_ply_obj(t_obj *obj)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (i < obj->ply.ply->nb_face)
    {
      if (obj->ply.ply->list_face[i].nb_face == 4)
	++count;
      ++i;
    }
  return (i + count);
}

static void	fill_obj_ply_3(t_obj *objs, int i, t_ply *ply)
{
  objs[i].triangle.pts[0] = ply->list_vertex[ply->list_face[i].face[0]].vec;
  objs[i].triangle.pts[1] = ply->list_vertex[ply->list_face[i].face[1]].vec;
  objs[i].triangle.pts[2] = ply->list_vertex[ply->list_face[i].face[2]].vec;
}

static void	fill_obj_ply_4(t_obj *objs, int i, t_ply *ply)
{
  objs[i].triangle.pts[0] = ply->list_vertex[ply->list_face[i].face[0]].vec;
  objs[i].triangle.pts[1] = ply->list_vertex[ply->list_face[i].face[3]].vec;
  objs[i].triangle.pts[2] = ply->list_vertex[ply->list_face[i].face[2]].vec;
}

static void	fill_obj_ply(t_obj *objs, t_ply *ply, int nb_face)
{
  int		i;

  i = 0;
  while (i < nb_face)
    {
      objs[i].type = TRIANGLE;
      objs[i].get_intersect = &get_intersect_triangle;
      if (ply->list_face[i].nb_face == 3 ||
	  ply->list_face[i].nb_face == 4)
	{
	  fill_obj_ply_3(objs, i, ply);
	}
      if (ply->list_face[i].nb_face == 4)
	{
	  ++i;
	  fill_obj_ply_4(objs, i, ply);
	}
      ++i;
    }
}

void		build_ply_obj(t_obj *obj)
{
  obj->ply.nb_obj = count_ply_obj(obj);
  if (!(obj->ply.objs = my_malloc(sizeof(t_obj) * obj->ply.nb_obj)))
    return ;
  my_bzero(obj->ply.objs, sizeof(t_obj) * obj->ply.nb_obj);
  fill_obj_ply(obj->ply.objs, obj->ply.ply, obj->ply.ply->nb_face);
}
