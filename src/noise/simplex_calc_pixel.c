/*
** simplex_calc_pixel.c for Raytracer in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed Apr 20 14:53:35 2016 Antoine Baché
** Last update Wed Apr 20 19:05:57 2016 Antoine Baché
*/

#include "noise.h"

static double	simplex_calc_pixel_2d(t_vec2 *d, t_vec2 *t, int *g)
{
  double	sum[3];
  double	tmp[3];
  double	res;

  sum[0] = 0.5 - d[0].x * d[0].x - d[0].y;
  sum[1] = 0.5 - d[1].x * d[1].x - d[1].y;
  sum[2] = 0.5 - d[2].x * d[2].x - d[2].y;
  tmp[0] = (sum[0] < 0) ? 0 : (sum[0] * sum[0] * sum[0] * sum[0] *
			       (t[g[0]].x * d[0].x + t[g[0]].y * d[0].y));
  tmp[1] = (sum[1] < 0) ? 0 : (sum[1] * sum[1] * sum[1] * sum[1] *
			       (t[g[1]].x * d[1].x + t[g[1]].y * d[1].y));
  tmp[2] = (sum[2] < 0) ? 0 : (sum[2] * sum[2] * sum[2] * sum[2] *
			       (t[g[2]].x * d[2].x + t[g[2]].y * d[2].y));
  res = (tmp[0] + tmp[1] + tmp[2]) * 70.0;
  return (res);
}

static double	simplex_calc_pixel_3d(t_vec3 *d, t_vec3 *t, int *g)
{
  double	sum[4];
  double	tmp[4];
  double	res;

  sum[0] = 0.6 - d[0].x * d[0].x - d[0].y - d[0].z * d[0].z;
  sum[1] = 0.6 - d[1].x * d[1].x - d[1].y - d[1].z * d[1].z;
  sum[2] = 0.6 - d[2].x * d[2].x - d[2].y - d[2].z * d[2].z;
  sum[3] = 0.6 - d[3].x * d[3].x - d[3].y - d[3].z * d[3].z;
  tmp[0] = (sum[0] < 0) ? 0 : (sum[0] * sum[0] * sum[0] * sum[0] *
			       (t[g[0]].x * d[0].x + t[g[0]].y * d[0].y +
				t[g[0]].z * d[0].z));
  tmp[1] = (sum[1] < 0) ? 0 : (sum[1] * sum[1] * sum[1] * sum[1] *
			       (t[g[1]].x * d[1].x + t[g[1]].y * d[1].y +
				t[g[1]].z * d[1].z));
  tmp[2] = (sum[2] < 0) ? 0 : (sum[2] * sum[2] * sum[2] * sum[2] *
			       (t[g[2]].x * d[2].x + t[g[2]].y * d[2].y +
				t[g[2]].z * d[2].z));
  tmp[3] = (sum[3] < 0) ? 0 : (sum[3] * sum[3] * sum[3] * sum[3] *
			       (t[g[3]].x * d[3].x + t[g[3]].y * d[3].y +
				t[g[3]].z * d[3].z));
  res = (tmp[0] + tmp[1] + tmp[2] + tmp[3]) * 32;
  return (res);
}

static double	simplex_calc_pixel_4d(t_vec4 *d, t_vec4 *t, int *g)
{
  double	sum[10];
  double	res;

  sum[0] = 0.6 - d[0].x * d[0].x - d[0].y - d[0].z * d[0].z - d[0].w * d[0].w;
  sum[1] = 0.6 - d[1].x * d[1].x - d[1].y - d[1].z * d[1].z - d[1].w * d[1].w;
  sum[2] = 0.6 - d[2].x * d[2].x - d[2].y - d[2].z * d[2].z - d[2].w * d[2].w;
  sum[3] = 0.6 - d[3].x * d[3].x - d[3].y - d[3].z * d[3].z - d[3].w * d[3].w;
  sum[4] = 0.6 - d[4].x * d[4].x - d[4].y - d[4].z * d[4].z - d[4].w * d[4].w;
  sum[5] = (sum[0] < 0) ? 0 : (sum[0] * sum[0] * sum[0] * sum[0] *
			       (t[g[0]].x * d[0].x + t[g[0]].y * d[0].y +
				t[g[0]].z * d[0].z + t[g[0]].w * d[0].w));
  sum[6] = (sum[1] < 0) ? 0 : (sum[1] * sum[1] * sum[1] * sum[1] *
			       (t[g[1]].x * d[1].x + t[g[1]].y * d[1].y +
				t[g[1]].z * d[1].z + t[g[1]].w * d[1].w));
  sum[7] = (sum[2] < 0) ? 0 : (sum[2] * sum[2] * sum[2] * sum[2] *
			       (t[g[2]].x * d[2].x + t[g[2]].y * d[2].y +
				t[g[2]].z * d[2].z + t[g[2]].w * d[2].w));
  sum[8] = (sum[3] < 0) ? 0 : (sum[3] * sum[3] * sum[3] * sum[3] *
			       (t[g[3]].x * d[3].x + t[g[3]].y * d[3].y +
				t[g[3]].z * d[3].z + t[g[3]].w * d[3].w));
  sum[9] = (sum[4] < 0) ? 0 : (sum[4] * sum[4] * sum[4] * sum[4] *
			       (t[g[4]].x * d[4].x + t[g[4]].y * d[4].y +
				t[g[4]].z * d[4].z + t[g[4]].w * d[4].w));
  res = (sum[5] + sum[6] + sum[7] + sum[8] + sum[9]) * 27.0;
  return (res);
}

double		simplex_calc_pixel(void *det, void *table, void *grad, int dim)
{
  if (dim == 2)
    return (simplex_calc_pixel_2d(det, table, grad));
  else if (dim == 3)
    return (simplex_calc_pixel_3d(det, table, grad));
  else if (dim == 4)
    return (simplex_calc_pixel_4d(det, table, grad));
  return (0.0);
}
