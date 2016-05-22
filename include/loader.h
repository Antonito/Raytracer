/*
** loader.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 19:09:07 2016 Ludovic Petrenko
** Last update Sun May 22 22:04:58 2016 Antoine Baché
*/

#ifndef LOADER_H_
# define LOADER_H_

# include "raytracer.h"
# include "engine/material.h"
# include "engine/scene.h"
# include "engine/light.h"

int		load_config(t_data *data, const char *file);
int		ini_count_prefix(const t_bunny_ini *ini, const char *prefix);
void		load_camera(t_camera *c, const t_bunny_ini *ini);
void		load_directionnal(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_light_spec(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_obj_basics(t_obj *obj, const t_bunny_ini_scope *s);
void		load_obj_data(t_scene *scene, t_obj *o,
			      const t_bunny_ini_scope *s);
int		load_objs(t_scene *scene, t_obj *obj, const t_bunny_ini *ini);
void		load_obj_spec(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_point(t_obj *obj, const t_bunny_ini_scope *scope);

/*
** Scene
*/
t_scene		*load_scene(const char *file, t_data *data);
int		load_scene_elements(t_scene *s, const t_bunny_ini *ini);
void		load_scene_info(t_scene *s, const t_bunny_ini *ini);
void		load_spot(t_obj *obj, const t_bunny_ini_scope *scope);

/*
** Materials
*/
t_material	*get_material(t_material *mat, int nb, const char *name);
int		load_mat(t_material *mat, const t_bunny_ini *ini);
void		load_mat_data(t_material *mat, const t_bunny_ini *ini);
int		load_materials(t_scene *s, const t_bunny_ini *ini);

/*
** Objects
*/
void		load_klein(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_mobius(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_void_cube(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_triangle(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_sphere(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_plane(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_torus(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_cone(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_cylinder(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_hyperbola(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_ellipsoid(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_ply(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_boy(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_cassini(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_chair(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_kusner(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_tritrumpet(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_whitney(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_tetrahedral(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_barth_sextic(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_bifolia(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_duplin(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_cushion(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_double_sphere(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_tooth(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_heart(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_hunt(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_miter(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_kiss(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_kummer(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_enneper(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_bohemian_dome(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_bohemian_star(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_c8(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_chubs(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_devil(t_obj *obj, const t_bunny_ini_scope *scope);
void		load_quartic_cylinder(t_obj *obj, const t_bunny_ini_scope *);
void		load_spheroid(t_obj *obj, const t_bunny_ini_scope *scope);

/*
** Ply functions
*/
void		build_ply_obj(t_obj *ply);

/*
** Effects
*/
void		load_effect_nothing(t_config *, const t_bunny_ini *);
void		load_solarized(t_config *, const t_bunny_ini *);
void		load_rotate(t_config *, const t_bunny_ini *);
void		load_contrast(t_config *, const t_bunny_ini *);
void		load_bayer(t_config *, const t_bunny_ini *);

#endif /* !LOADER_H_  */
