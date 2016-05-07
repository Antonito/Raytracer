/*
** debug.c for Raytracer2 in /gfx_raytracer2/src/client
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 18:08:38 2016 Antoine Baché
** Last update Sat May  7 18:49:31 2016 Antoine Baché
*/

#include <stdio.h>
#include "raytracer.h"

void		print_camera(t_camera *cam)
{
  printf("POS : %f %f %f\n", cam->pos.x, cam->pos.y, cam->pos.z);
  printf("DIR : %f %f %f\n", cam->dir.x, cam->dir.y, cam->dir.z);
  printf("Focale : %f\n", cam->focale);
  printf("FOV : %f\n", cam->fov);
  printf("ORIGIN : %f %f %f\n", cam->origin.x, cam->origin.y, cam->origin.z);
  printf("INCR_X : %f %f %f\n", cam->incr_x.x, cam->incr_x.y, cam->incr_x.z);
  printf("INCR_Y : %f %f %f\n", cam->incr_y.x, cam->incr_y.y, cam->incr_y.z);
  printf("Rot : %f %f\n", cam->rot_x, cam->rot_y);
}

void		print_objs(t_obj *objs, int nb)
{
  static char	*name[9] = {"light", "sphere", "plane", "cylinder", "cone",
			   "triangle", "torus", "mobius", "void_cube"};
  int		i;
  t_obj		*obj;

  i = 0;
  while ((obj = objs->next))
    {
      printf("----> Object %d\n", i);
      printf("Type = %s\n", name[obj->type]);
      printf("POS : %f %f %f\n", obj->pos.x, obj->pos.y, obj->pos.z);
      printf("ROT : %f %f %f\n", obj->rot.x, obj->rot.y, obj->rot.z);
      printf("Material : ???\n");
      ++i;
    }
}

void		print_lights(t_light *lights, int nb)
{
  static char	*name[3] = {"Point", "Directionnal", "spot"};
  int		i;

  i = 0;
  while (i < nb)
    {
      printf("----> Light %d\n", i);
      printf("Type = %s\n", name[lights[i].type]);
      printf("Color : %X\n", lights[i].color);
      printf("Radius : %f\n", lights[i].radius);
      printf("Power : %f\n", lights[i].power);
      printf("DIR : %f %f %f\n", lights[i].dir.x, lights[i].dir.y,
	     lights[i].dir.z);
      printf("Angle : %f\n", lights[i].angle);
      ++i;
    }
}

void		print_materials(t_material *mats, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      printf("----> Material %d\n", i);
      printf("Name : \"%s\"\n", mats[i].name);
      printf("Color : %X\n", mats[i].color);
      printf("Opacity : %f\n", mats[i].opacity);
      printf("Reflectivity : %f\n", mats[i].reflectivity);
      printf("Fresnel : %f\n", mats[i].fresnel);
      ++i;
    }
}

void		print_specs(t_scene_spec *spec)
{
  printf("Bg_color: %X\n", spec->bg_color);
  printf("Ambiant: %f\n\n\n", spec->ambiant);
}

void		print_scenes(t_scene *scenes)
{
  int		i;
  t_scene	*scene;

  i = 0;
  scene = scenes;
  while (scene)
    {
      printf("=========================\n");
      printf("Scene %d\n", i);
      printf("=========================\n");
      printf("-----\n");
      printf("Camera\n");
      printf("-----\n");
      print_camera(&scene->cam);
      printf("-----\n");
      printf("Obj : %d\n", scene->nb_obj);
      printf("-----\n");
      print_objs(scene->objs, scene->nb_obj);
      printf("-----\n");
      printf("Light : %d\n", scene->nb_light);
      printf("-----\n");
      print_lights(scene->lights, scene->nb_light);
      printf("-----\n");
      printf("Material : %d\n", scene[i].nb_mat);
      printf("-----\n");
      print_materials(scene->mat, scene->nb_mat);
      printf("-----\n");
      printf("Spec\n");
      printf("-----\n");
      print_specs(&scene->spec);
      scene = scene->next;
      ++i;
    }
}
