/*
** skybox.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun May 22 02:07:23 2016 Ludovic Petrenko
** Last update Sun May 22 03:50:07 2016 Ludovic Petrenko
*/

#include "raytracer.h"

static unsigned int	skybox_x(t_scene *s, t_vec3 *i, double t)
{
  t_vec2		p;

  if (t > 0.0)
    p.x = (i->y - 3.0) / 4.0;
  else
    p.x = (-i->y + 1.0) / 4.0;
  p.y = i->z / 3.0;
  return (get_tex_pix(s->spec.skybox, p));
}

static unsigned int	skybox_y(t_scene *s, t_vec3 *i, double t)
{
  t_vec2		p;

  if (t < 0.0)
    p.x = (i->x - 1.0) / 4.0;
  else
    p.x = (-i->x + 3.0) / 4.0;
  p.y = i->z / 3.0;
  return (get_tex_pix(s->spec.skybox, p));
}

static unsigned int	skybox_z(t_scene *s, t_vec3 *i, double t)
{
  t_vec2		p;

  p.x = (i->x - 1.0) / 4.0;
  if (t > 0.0)
    p.y = (i->y - 2.0) / 3.0;
  else
    p.y = (-i->y + 2.0) / 3.0;
  return (get_tex_pix(s->spec.skybox, p));
}

unsigned int	skybox_intersect(t_scene *s, t_ray *r)
{
  t_vec3	i;
  double	t;

   if (!s->spec.skybox)
    return (s->spec.bg_color.full);
  t = ((r->dir.x > 0.0) ? -1.0 : 1.0) / r->dir.x;
  i.y = t * r->dir.y;
  i.z = t * r->dir.z;
  if (r->dir.x != 0.0 && i.y >= -1.0 && i.y <= 1.0 && i.z >= -1.0 && i.z <= 1.0)
    return (skybox_x(s, &i, r->dir.x));
  t = ((r->dir.y > 0.0) ? -1.0 : 1.0) / r->dir.y;
  i.x = t * r->dir.x;
  i.z = t * r->dir.z;
  if (r->dir.y != 0.0 && i.x >= -1.0 && i.x <= 1.0 && i.z >= -1.0 && i.z <= 1.0)
    return (skybox_y(s, &i, r->dir.y));
  t = ((r->dir.z > 0.0) ? -1.0: 1.0) / r->dir.z;
  i.x = t * r->dir.x;
  i.y = t * r->dir.y;
  if (r->dir.z != 0.0 && i.x >= -1.0 && i.x <= 1.0 && i.y >= -1.0 && i.y <= 1.0)
    return (skybox_z(s, &i, r->dir.z));
  return (s->spec.bg_color.full);
}
