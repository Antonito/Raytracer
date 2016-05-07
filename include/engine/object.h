/*
** object.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:33:45 2016 Ludovic Petrenko
** Last update Sat May  7 06:30:31 2016 Ludovic Petrenko
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include "vector.h"
# include "ray.h"
# include "intersect.h"
# include "material.h"

# define DEFAULT_SPHERE_RADIUS		0.5
# define DEFAULT_PLANE_NORMALE		vec3(0.0, 0.0, 1.0)
# define DEFAULT_CYLINDER_RADIUS	0.5
# define DEFAULT_CYLINDER_HEIGHT	5.0
# define DEFAULT_CONE_ANGLE		30.0
# define DEFAULT_CONE_HEIGHT		3.0
# define DEFAULT_LIGHT_COLOR		0xFFFFFF
# define DEFAULT_LIGHT_RADIUS		0.2
# define DEFAULT_LIGHT_POWER		1.0
# define DEFAULT_LIGHT_DIR		vec3(-1.0, 0.0, -1.0)
# define DEFAULT_LIGHT_ANGLE		40.0
# define DEFAULT_TORUS_RADIUS_HOLE	2.0
# define DEFAULT_TORUS_RADIUS_SOLID	0.5

typedef enum	e_obj_type
  {
    NONE = -1,
    LIGHT,
    SPHERE,
    PLANE,
    CYLINDER,
    CONE,
    TRIANGLE,
    TORUS,
    MOBIUS,
    VOID_CUBE,
    NB_OBJ_TYPE
  }		t_obj_type;

typedef enum	e_light_type
  {
    POINT,
    DIRECTIONNAL,
    SPOT,
    NB_LIGHT_TYPE
  }		t_light_type;

typedef struct	s_light
{
  t_light_type  type;
  unsigned int	color;
  double        radius;
  double        power;
  t_vec3	dir;
  double	angle;
}		t_light;

typedef struct	s_sphere
{
  double	radius;
}		t_sphere;

typedef struct	s_plane
{
  t_vec3	normale;
}		t_plane;

typedef struct	s_cylinder
{
  double	radius;
  double	height;
}		t_cylinder;

typedef struct	s_cone
{
  double	angle;
  double	height;
  double	radius;
}		t_cone;

typedef struct	s_triangle
{
  t_vec3	poly[3];
}		t_triangle;

typedef struct	s_torus
{
  double	radius_hole;
  double	radius_solid;
}		t_torus;

typedef struct	s_mobius
{
  double	radius;
}		t_mobius;

typedef struct	s_obj
{
  t_obj_type	type;
  t_vec3	pos;
  t_vec3	rot;
  t_material	*mat;
  struct s_obj	*next;
  t_intersect	(*get_intersect)(struct s_obj *, t_ray *);
  union
  {
    t_light	light;
    t_sphere	sphere;
    t_plane	plane;
    t_cylinder	cylinder;
    t_cone	cone;
    t_triangle	triangle;
    t_torus	torus;
    t_mobius	mobius;
  };
}		t_obj;

/*
** Functions
*/
void		light_dim(t_obj *, t_vec3 *);
void		sphere_dim(t_obj *, t_vec3 *);
void	        cylinder_dim(t_obj *, t_vec3 *);
void		cone_dim(t_obj *, t_vec3 *);
void		torus_dim(t_obj *, t_vec3 *);
t_intersect	get_intersect_sphere(t_obj *, t_ray *);
t_intersect	get_intersect_cylinder(t_obj *, t_ray *);
t_intersect	get_intersect_plane(t_obj *, t_ray *);
t_intersect	get_intersect_tore(t_obj *, t_ray *);
t_intersect	get_intersect_triangle(t_obj *, t_ray *);
t_intersect	get_intersect_cone(t_obj *, t_ray *);
t_intersect	get_intersect_mobius(t_obj *, t_ray *);
t_intersect	get_intersect_void_cube(t_obj *, t_ray *);

#endif /* !OBJECT_H_ */
