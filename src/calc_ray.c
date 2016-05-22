/*
** calc_ray.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 30 23:30:01 2016 Ludovic Petrenko
** Last update Sun May 22 19:55:38 2016 Antoine Baché
*/

#define _ISOC99_SOURCE

#include <math.h>
#include "raytracer.h"
#include "engine/scene.h"
#include "tools/math.h"
#include "tools/str.h"

unsigned int	mix_colors(t_scene *s, t_intersect *i,
			   t_intersect *r, t_intersect *t)
{
  t_color	final;
  double	refl;
  double	refr;
  int		j;
  double	light[3];
  double	tmp;

  refl = i->mat->reflectivity;
  refr = i->mat->opacity;
  if (t->dist >= 0.0 && t->dist != INFINITY)
    refr = MAX(MIN(refr / t->dist * 50, 1.0), 0.0);
  get_light(s, i, light);
  j = -1;
  while (++j < 3)
    {
      tmp = r->color.argb[j] * refl + (1)
	* (i->color.argb[j] * refr * light[j] +
	   t->color.argb[j] * (1 - refr));
      final.argb[j] = (unsigned char)MIN(tmp, 255);
    }
  return (final.full);
}

static void	get_reflected_ray(t_intersect *inter, t_ray *i, t_ray *r)
{
  r->dir = add_vec3(i->dir, mult_vec3(inter->norm, -2.0 *
				      dot_vec3(inter->norm, i->dir)));
  r->dir = vec3_normalize(r->dir);
  r->pos = add_vec3(inter->pos, mult_vec3(inter->norm, -0.00001 *
					  dot_vec3(inter->dir, inter->norm)));
  r->env = i->env;
}

static void	get_refracted_ray(t_intersect *inter, t_ray *i, t_ray *r)
{
  double	coeff[2];
  double	c;
  double	s;
  double	tmp;

  coeff[0] = (i->env) ? ((t_obj *)i->env)->mat->fresnel : 1.0;
  coeff[1] = (inter->mat) ? inter->mat->fresnel : 1.0;
  c = dot_vec3(i->dir, inter->norm);
  s = (coeff[0] / coeff[1]) * (coeff[0] / coeff[1]) * (1 - c * c);
  r->dir = mult_vec3(i->dir, coeff[0] / coeff[1]);
  tmp = coeff[0] / coeff[1] * c - sqrt(1 - s);
  r->dir = add_vec3(r->dir, mult_vec3(inter->norm, tmp));
  r->dir = vec3_normalize(r->dir);
  r->pos = inter->pos;
  r->pos = sub_vec3(inter->pos, mult_vec3(inter->norm, 0.00001 *
					  dot_vec3(inter->dir, inter->norm)));
  if (dot_vec3(inter->dir, inter->norm) >= 0.0)
    r->env = NULL;
  else
    r->env = inter->obj;
}

static int	calc_ray_color(t_intersect *inter, t_scene *scene,
				       t_ray *ray)
{
  if (inter->dist < 0.00001 || inter->dist == INFINITY || inter->mat == NULL)
    {
      inter->color.full = skybox_intersect(scene, ray);
      return (1);
    }
  if (inter->obj == scene->select && -dot_vec3(inter->norm, ray->dir) < 0.25)
    {
      inter->color.full = 0xFF0000FF;
      return (1);
    }
  return (0);
}

void		calc_ray(t_scene *scene, t_ray *ray, int i, t_intersect *inter)
{
  t_intersect	refl;
  t_intersect	refr;
  t_ray		tmp;

  my_bzero(inter, sizeof(t_intersect));
  inter->dist = INFINITY;
  inter->color = scene->spec.bg_color;
  refl = refr = *inter;
  if (i >= MAX_RECURSIVE)
    return ;
  scene_intersect(scene, ray, inter);
  if ((inter->obj && inter->obj != scene->select && ((t_obj*)inter->obj)->type
       == LIGHT) || calc_ray_color(inter, scene, ray))
    return ;
  if (!IS_ZERO(inter->mat->reflectivity))
    {
      get_reflected_ray(inter, ray, &tmp);
      calc_ray(scene, &tmp, i + 1, &refl);
    }
  if (!IS_ZERO(inter->mat->opacity - 1.0))
    {
      get_refracted_ray(inter, ray, &tmp);
      calc_ray(scene, &tmp, i + 1, &refr);
    }
  inter->color.full = mix_colors(scene, inter, &refl, &refr);
}
