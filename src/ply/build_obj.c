/*
** build_obj.c for Raytracer2 in /gfx_raytracer2/src/ply
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue May 17 17:56:10 2016 Antoine Baché
** Last update Sun May 22 04:58:52 2016 Ludovic Petrenko
*/

#include "engine/object.h"
#include "engine/bsp.h"
#include "tools/str.h"
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

static void	fill_obj_ply_3(t_obj *objs, int i, int j, t_ply *ply)
{
  int		k;

  objs[i].triangle.color.argb[3] = 0;
  if (ply->list_vertex[ply->list_face[j].face[0]].get_color &&
      ply->list_vertex[ply->list_face[j].face[1]].get_color &&
      ply->list_vertex[ply->list_face[j].face[2]].get_color)
    {
      k = -1;
      objs[i].triangle.color.argb[3] = 255;
      /* while (++k < 3) */
      /* 	objs[i].triangle.color.argb[k] = */
      /* 	  (ply->list_vertex[ply->list_face[j].face[0]].color.argb[k] + */
      /* 	   ply->list_vertex[ply->list_face[j].face[1]].color.argb[k] + */
      /* 	   ply->list_vertex[ply->list_face[j].face[2]].color.argb[k]) / 3; */
      objs[i].triangle.color.full = ply->list_vertex[ply->list_face[j].face[0]].color.full;
      if (objs[i].triangle.color.full != 0xFFFFFFFF)
	printf("%X\n", objs[i].triangle.color.full);
    }
  objs[i].triangle.pts[0] = ply->list_vertex[ply->list_face[j].face[0]].vec;
  objs[i].triangle.pts[1] = ply->list_vertex[ply->list_face[j].face[1]].vec;
  objs[i].triangle.pts[2] = ply->list_vertex[ply->list_face[j].face[2]].vec;
  objs[i].box[0] = vec3_min(objs[i].triangle.pts[0], objs[i].triangle.pts[1]);
  objs[i].box[1] = vec3_max(objs[i].triangle.pts[0], objs[i].triangle.pts[1]);
  objs[i].box[0] = vec3_min(objs[i].box[0], objs[i].triangle.pts[2]);
  objs[i].box[1] = vec3_max(objs[i].box[1], objs[i].triangle.pts[2]);
}

static void	fill_obj_ply_4(t_obj *objs, int i, int j, t_ply *ply)
{
  int		k;

  objs[i].triangle.color.argb[3] = 0;
  if (ply->list_vertex[ply->list_face[j].face[0]].get_color &&
      ply->list_vertex[ply->list_face[j].face[1]].get_color &&
      ply->list_vertex[ply->list_face[j].face[2]].get_color)
    {
      k = -1;
      objs[i].triangle.color.argb[3] = 255;
      while (++k < 3)
	objs[i].triangle.color.argb[k] =
	  (ply->list_vertex[ply->list_face[j].face[0]].color.argb[k] +
	   ply->list_vertex[ply->list_face[j].face[1]].color.argb[k] +
	   ply->list_vertex[ply->list_face[j].face[2]].color.argb[k]) / 3;
    }
  objs[i].triangle.pts[0] = ply->list_vertex[ply->list_face[j].face[0]].vec;
  objs[i].triangle.pts[1] = ply->list_vertex[ply->list_face[j].face[2]].vec;
  objs[i].triangle.pts[2] = ply->list_vertex[ply->list_face[j].face[3]].vec;
  objs[i].box[0] = vec3_min(objs[i].triangle.pts[0], objs[i].triangle.pts[1]);
  objs[i].box[1] = vec3_max(objs[i].triangle.pts[0], objs[i].triangle.pts[1]);
  objs[i].box[0] = vec3_min(objs[i].box[0], objs[i].triangle.pts[2]);
  objs[i].box[1] = vec3_max(objs[i].box[1], objs[i].triangle.pts[2]);
}

static void	fill_obj_ply(t_obj *obj, t_obj *objs, t_ply *ply, int nb_face)
{
  int		i;
  int		j;

  i = j = -1;
  while (++j < nb_face)
    {
      objs[++i].type = TRIANGLE;
      objs[i].get_intersect = &get_intersect_triangle;
      if (ply->list_face[j].nb_face == 3 ||
	  ply->list_face[j].nb_face == 4)
	fill_obj_ply_3(objs, i, j, ply);
      if (ply->list_face[j].nb_face == 4)
	{
	  objs[i].rot = objs[i].pos = vec3(0, 0, 0);
	  objs[i].mat = obj->mat;
	  objs[i].next = &objs[i + 1];
	  objs[++i].type = TRIANGLE;
	  objs[i].get_intersect = &get_intersect_triangle;
	  fill_obj_ply_4(objs, i, j, ply);
	}
      objs[i].rot = objs[i].pos = vec3(0, 0, 0);
      objs[i].mat = obj->mat;
      objs[i].next = (j + 1 == nb_face) ? NULL : &objs[i + 1];
    }
}

void		build_ply_obj(t_obj *obj)
{
  obj->ply.nb_obj = count_ply_obj(obj);
  obj->ply.node = NULL;
  if (!(obj->ply.objs = my_malloc(sizeof(t_obj) * obj->ply.nb_obj)) ||
      !(obj->ply.node = my_calloc(1, sizeof(t_node))))
    return ;
  ((t_node *)(obj->ply.node))->nb_obj = obj->ply.nb_obj;
  ((t_node *)(obj->ply.node))->obj_list.next = obj->ply.objs;
  my_bzero(obj->ply.objs, sizeof(t_obj) * obj->ply.nb_obj);
  fill_obj_ply(obj, obj->ply.objs, obj->ply.ply, obj->ply.ply->nb_face);
  set_box(obj);
  ((t_node *)(obj->ply.node))->box[0] = obj->box[0];
  ((t_node *)(obj->ply.node))->box[1] = obj->box[1];
  if (obj->ply.ply)
    build_bsp(obj->ply.node, 0);
}
