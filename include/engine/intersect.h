/*
** intersect.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 01:23:21 2016 Ludovic Petrenko
** Last update Tue May  3 16:59:59 2016 Antoine Baché
*/

#ifndef INTERSECT_H_
# define INTERSECT_H_

# include "vector.h"
# include "ray.h"

typedef struct	s_intersect
{
  t_vec3	pos;
  t_vec3	dir;
  t_vec3	norm;
  double	dist;
  unsigned int	color;
}		t_intersect;

/*
** Functions
*/
t_intersect	get_intersect_sphere(t_obj *, t_ray *);
t_intersect	get_intersect_cylinder(t_obj *, t_ray *);
t_intersect	get_intersect_plane(t_obj *, t_ray *);
t_intersect	get_intersect_tore(t_obj *, t_ray *);
t_intersect	get_intersect_void_cube(t_obj *, t_ray *);

#endif /* !INTERSECT_H_ */
