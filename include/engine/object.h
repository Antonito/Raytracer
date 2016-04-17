/*
** object.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:33:45 2016 Ludovic Petrenko
** Last update Sun Apr 17 16:56:50 2016 Ludovic Petrenko
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include "vector.h"
# include "ray.h"
# include "intersect.h"
# include "material.h"

typedef enum	e_obj_type
  {
    NONE = -1,
    LIGHT,
    SPHERE,
    PLANE,
    CYLINDER,
    CONE
  }		t_obj_type;

typedef enum	e_light_type
  {
    POINT,
    DIRECTIONNAL,
    SPOT
  }		t_light_type;

typedef struct	s_obj
{
  t_obj_type	type;
  t_vec3	pos;
  t_vec3	rot;
  t_material	*mat;
  struct s_obj	*next;
  t_intersect	(*get_intersect)(void *, t_ray);
}		t_obj;

typedef struct	s_light
{
  t_obj_type	type;
  t_vec3	pos;
  t_vec3	dir;
  t_material	*mat;
  struct s_obj	*next;
  t_intersect	(*get_intersect)(void *, t_ray);
  t_light_type	light_type;
  unsigned int	color;
  double        radius;
  double        power;
  }		t_light;

typedef struct	s_sphere
{
  t_obj_type	type;
  t_vec3	pos;
  t_vec3	rot;
  t_material	*mat;
  struct s_obj	*next;
  t_intersect	(*get_intersect)(void *, t_ray);
  double	radius;
}		t_sphere;

typedef struct	s_plane
{
  t_obj_type	type;
  t_vec3	pos;
  t_vec3	rot;
  t_material	*mat;
  struct s_obj	*next;
  t_intersect	(*get_intersect)(void *, t_ray);
}		t_plane;

typedef struct	s_cylinder
{
  t_obj_type	type;
  t_vec3	pos;
  t_vec3	rot;
  t_material	*mat;
  struct s_obj	*next;
  t_intersect	(*get_intersect)(void *, t_ray);
  double	radius;
  double	height;
}		t_cylinder;

typedef struct	s_cone
{
  t_obj_type	type;
  t_vec3	pos;
  t_vec3	rot;
  t_material	*mat;
  struct s_obj	*next;
  t_intersect	(*get_intersect)(void *, t_ray);
  double	angle;
  double	height;
}		t_cone;

#endif /* !OBJECT_H_ */
