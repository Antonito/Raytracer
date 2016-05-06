/*
** calc_fragment.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Thu Apr 21 20:09:40 2016 Ludovic Petrenko
** Last update Sat May  7 00:45:25 2016 Ludovic Petrenko
*/

#include <math.h>
#include "raytracer.h"
#include "engine/vector.h"

void		set_vectors(t_data *data, t_camera *c)
{
  double	len;
  t_vec3	tmp;

  /* printf("FOV = %.2f\n", c->fov); */
  len = tan(c->fov / 2.0 * M_PI / 180.0) * 2.0 / (double)data->width;
  /* printf("len: %f\n", len); */
  /* printf("tan: %f\n", tan(c->fov / 2.0 * M_PI / 180.0) * 2.0); */
  /* tmp = cross_vec3(c->dir, vec3(0, 0, 1.0)); */

  tmp = vec3_normalize(vec3(c->dir.y, -c->dir.x, 0));

  /* printf("DIR (%.5f, %.5f, %.5f)\n", tmp.x, tmp.y, tmp.z); */
  c->incr_x = mult_vec3(tmp, len);
  len = tan(c->fov * data->height / data->width / 2.0
	    * M_PI / 180.0) * 2.0 / data->height;
  tmp = vec3_normalize(cross_vec3(c->dir, tmp));
  /* printf("\nTMP (%.2f, %.2f, %.2f)\n", tmp.x, tmp.y, tmp.z); */
  c->incr_y = mult_vec3(tmp, len);
  c->origin = add_vec3(c->pos, c->dir);
  c->origin = sub_vec3(c->origin, mult_vec3(c->incr_x, data->width / 2.0));
  c->origin = sub_vec3(c->origin, mult_vec3(c->incr_y, data->height / 2.0));
  /* printf("\nPOS (%.2f, %.2f, %.2f)\n", c->pos.x, c->pos.y, c->pos.z); */
  /* printf("DIR (%.2f, %.2f, %.2f)\n", c->dir.x, c->dir.y, c->dir.z); */
  /* printf("  O (%.2f, %.2f, %.2f)\n", c->origin.x, c->origin.y, c->origin.z); */
  /* printf("  X (%.5f, %.5f, %.5f)\n", c->incr_x.x, c->incr_x.y, c->incr_x.z); */
  /* printf("  Y (%.5f, %.5f, %.5f)\n", c->incr_y.x, c->incr_y.y, c->incr_y.z); */
}

unsigned int	calc_pixel(t_scene *scene, t_ivec2 *pix)
{
  t_ray		ray;

  ray.pos = scene->cam.pos;
  ray.dir = add_vec3(scene->cam.origin,
		     mult_vec3(scene->cam.incr_x, (double)pix->x));
  ray.dir = add_vec3(ray.dir, mult_vec3(scene->cam.incr_y, (double)pix->y));
  ray.dir = vec3_normalize(sub_vec3(ray.dir, ray.pos));
  /* printf("DIR (%.5f, %.5f, %.5f)\n", ray.dir.x, ray.dir.y, ray.dir.z); */
  return (calc_ray(scene, &ray, 0));
}

void		calc_fragment(t_data *data, unsigned int *buf, t_ivec2 *pos)
{
  t_ivec2	tmp;
  int		i;

  tmp = pos[0];
  i = 0;
  while (tmp.y < pos[1].y)
    {
      buf[i] = calc_pixel(data->scene, &tmp);
      tmp.x = (tmp.x + 1 < pos[1].x) ? tmp.x + 1 : 0;
      tmp.y += (tmp.x == 0);
      ++i;
    }
}
