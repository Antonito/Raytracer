/*
** loader.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 19:09:07 2016 Ludovic Petrenko
** Last update Tue Apr 19 23:39:24 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "engine/material.h"
#include "engine/scene.h"
#include "engine/light.h"

t_material	*get_material(t_material *mat, int nb, const char *name);
int		load_config(t_data *data, const char *file);
int		ini_count_prefix(const t_bunny_ini *ini, const char *prefix);
void		load_camera(t_camera *c, const t_bunny_ini *ini);
void		load_cone(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_cylinder(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_directionnal(t_obj *obj, const t_bunny_ini_scope *scope);
void	        load_light_spec(t_obj *obj, const t_bunny_ini_scope *scope);
int		load_mat(t_material *mat, const t_bunny_ini *ini);
void		load_mat_data(t_material *mat, const t_bunny_ini *ini);
int		load_materials(t_scene *s, const t_bunny_ini *ini);
int		load_network(t_data *data, const t_bunny_ini *ini);
void		load_obj_basics(t_obj *obj, const t_bunny_ini_scope *s);
void		load_obj_data(t_scene *scene, t_obj *o,
			      const t_bunny_ini_scope *s);
void		load_objs(t_scene *scene, t_obj *obj, const t_bunny_ini *ini);
void		load_obj_spec(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_plane(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_point(t_obj *obj, const t_bunny_ini_scope *scope);
t_scene		*load_scene(const char *file);
int		load_scene_elements(t_scene *s, const t_bunny_ini *ini);
void		load_scene_info(t_scene *s, const t_bunny_ini *ini);
void		load_sphere(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_spot(t_obj *obj, const t_bunny_ini_scope *scope);
