/*
** object.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 00:33:45 2016 Ludovic Petrenko
** Last update Sun May 22 03:48:59 2016 Antoine Baché
*/

#ifndef OBJECT_H_
# define OBJECT_H_

# include "vector.h"
# include "ray.h"
# include "ply.h"
# include "intersect.h"
# include "material.h"

# define DEFAULT_POLY_PTS0		vec3(-1.0, 3.0, 0.0);
# define DEFAULT_POLY_PTS1		vec3(1.0, 3.0, 0.0);
# define DEFAULT_POLY_PTS2		vec3(0.0, 0.0, 0.0);
# define DEFAULT_ELLIPSOID_HEIGHT	5.0
# define DEFAULT_ELLIPSOID_LENGTH	9.0
# define DEFAULT_ELLIPSOID_WIDTH	3.0
# define DEFAULT_HYPERBOLA_HEIGHT	3.0
# define DEFAULT_SPHERE_RADIUS		0.5
# define DEFAULT_SPHEROID_RADIUS	DEFAULT_SPHERE_RADIUS
# define DEFAULT_SPHEROID_HEIGHT	1.0
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

typedef enum		e_obj_type
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
    KLEIN,
    HYPERBOLA,
    ELLIPSOID,
    PLY,
    BOY,
    CASSINI,
    CHAIR,
    KUSNER,
    TRITRUMPET,
    WHITNEY,
    TETRAHEDRAL,
    BARTH_SEXTIC,
    BIFOLIA,
    DUPLIN,
    CUSHION,
    DOUBLE_SPHERE,
    TOOTH,
    HEART,
    HUNT,
    MITER,
    KISS,
    KUMMER,
    ENNEPER,
    BOHEMIAN_DOME,
    BOHEMIAN_STAR,
    C8,
    CHUBS,
    DEVIL,
    QUARTIC_CYLINDER,
    SPHEROID,
    NB_OBJ_TYPE
  }			t_obj_type;

typedef enum		e_light_type
  {
    POINT,
    DIRECTIONNAL,
    SPOT,
    NB_LIGHT_TYPE
  }			t_light_type;

typedef struct		s_light
{
  t_light_type		type;
  t_color		color;
  double		radius;
  double		power;
  t_vec3		dir;
  double		angle;
}			t_light;

typedef struct		s_sphere
{
  double		radius;
}			t_sphere;

typedef struct		s_plane
{
  t_vec3		normale;
}			t_plane;

typedef struct		s_cylinder
{
  double		radius;
  double		height;
}			t_cylinder;

typedef struct		s_cone
{
  double		angle;
  double		height;
  double		radius;
}			t_cone;

typedef struct		s_triangle
{
  t_color		color;
  t_vec3		pts[3];
}			t_triangle;

typedef struct		s_torus
{
  double		radius_hole;
  double		radius_solid;
}			t_torus;

typedef struct		s_mobius
{
  double		radius;
}			t_mobius;

typedef struct		s_hyperbola
{
  double		length;
}			t_hyperbola;

typedef struct		s_ellipsoid
{
  double		height;
  double		width;
  double		length;
}			t_ellipsoid;

typedef struct		s_spheroid
{
  double		height;
  double		radius;
}			t_spheroid;

typedef struct		s_obj
{
  t_obj_type		type;
  t_vec3		pos;
  t_vec3		rot;
  t_material		*mat;
  t_bunny_pixelarray	*tex;
  t_vec3		box[2];
  struct s_obj		*next;
  t_intersect		(*get_intersect)(struct s_obj *, t_ray *);
  union
  {
    t_light		light;
    t_sphere		sphere;
    t_plane		plane;
    t_cylinder		cylinder;
    t_cone		cone;
    t_triangle		triangle;
    t_torus		torus;
    t_mobius		mobius;
    t_hyperbola		hyperbola;
    t_ellipsoid		ellipsoid;
    struct
    {
      t_ply		*ply;
      struct s_obj	*objs;
      void		*node;
      int		nb_obj;
    }			ply;
    t_spheroid		spheroid;
  };
}			t_obj;

typedef struct		s_ply_load
{
  t_color		color;
  t_ply			*ply;
  t_obj			*objs;
  void			*node;
  int			nb_obj;
}			t_ply_load;

/*
** Generic Normal Vector Calculator
**
** The first function pointeurs should take as parameters inter and a t_vec3
** The t_vec3 is basically inter->pos * inter->pos (it allows optimization)
*/
void			calc_normale(double (*)(), double (*)(), double (*)(),
				     t_intersect *);

/*
** Functions
*/
void			light_dim(t_obj *, t_vec3 *);
void			sphere_dim(t_obj *, t_vec3 *);
void			cylinder_dim(t_obj *, t_vec3 *);
void			cone_dim(t_obj *, t_vec3 *);
void			torus_dim(t_obj *, t_vec3 *);
t_intersect		get_intersect_sphere(t_obj *, t_ray *);
t_intersect		get_intersect_light(t_obj *, t_ray *);
t_intersect		get_intersect_cylinder(t_obj *, t_ray *);
t_intersect		get_intersect_plane(t_obj *, t_ray *);
t_intersect		get_intersect_tore(t_obj *, t_ray *);
t_intersect		get_intersect_triangle(t_obj *, t_ray *);
t_intersect		get_intersect_cone(t_obj *, t_ray *);
t_intersect		get_intersect_mobius(t_obj *, t_ray *);
t_intersect		get_intersect_void_cube(t_obj *, t_ray *);
t_intersect		get_intersect_klein(t_obj *, t_ray *);
t_intersect		get_intersect_hyperbola(t_obj *, t_ray *);
t_intersect		get_intersect_ellipsoid(t_obj *, t_ray *);
t_intersect		get_intersect_ply(t_obj *, t_ray *);
t_intersect		get_intersect_boy(t_obj *, t_ray *);
t_intersect		get_intersect_cassini(t_obj *, t_ray *);
t_intersect		get_intersect_chair(t_obj *, t_ray *);
t_intersect		get_intersect_kusner(t_obj *, t_ray *);
t_intersect		get_intersect_tritrumpet(t_obj *, t_ray *);
t_intersect		get_intersect_whitney(t_obj *, t_ray *);
t_intersect		get_intersect_tetrahedral(t_obj *, t_ray *);
t_intersect		get_intersect_barth_sextic(t_obj *, t_ray *);
t_intersect    		get_intersect_bifolia(t_obj *, t_ray *);
t_intersect		get_intersect_duplin(t_obj *, t_ray *);
t_intersect	       	get_intersect_cushion(t_obj *, t_ray *);
t_intersect		get_intersect_double_sphere(t_obj *, t_ray *);
t_intersect		get_intersect_tooth(t_obj *, t_ray *);
t_intersect		get_intersect_heart(t_obj *, t_ray *);
t_intersect		get_intersect_hunt(t_obj *, t_ray *);
t_intersect		get_intersect_miter(t_obj *, t_ray *);
t_intersect		get_intersect_kiss(t_obj *, t_ray *);
t_intersect		get_intersect_kummer(t_obj *, t_ray *);
t_intersect		get_intersect_enneper(t_obj *, t_ray *);
t_intersect		get_intersect_bohemian_dome(t_obj *, t_ray *);
t_intersect		get_intersect_bohemian_star(t_obj *, t_ray *);
t_intersect		get_intersect_c8(t_obj *, t_ray *);
t_intersect		get_intersect_chubs(t_obj *, t_ray *);
t_intersect		get_intersect_devil(t_obj *, t_ray *);
t_intersect		get_intersect_quartic_cylinder(t_obj *, t_ray *);
t_intersect		get_intersect_spheroid(t_obj *, t_ray *);

/*
** Klein specific functions
*/
double			calc_d_klein(t_ray *, t_vec3, t_vec3, t_vec3);
double			calc_e_klein(t_ray *, t_vec3, t_vec3, t_vec3);
double			calc_f_klein(t_ray *, t_vec3, t_vec3);
double			calc_g_klein(t_ray *, t_vec3, t_vec3);
void			calc_normale_klein(t_intersect *);

void			build_ply_obj(t_obj *);
void			set_box(t_obj *);

#endif /* !OBJECT_H_ */
