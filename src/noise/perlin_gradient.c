/*
** perlin_gradient.c for Raytracer2 in /gfx_raytracer2/src/noise
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Tue Apr 19 08:54:01 2016 Antoine Baché
** Last update Tue Apr 19 09:15:12 2016 Antoine Baché
*/

#include "noise.h"

static void	calc_perlin_gradient_2d(t_gradient2 *grad, t_mask2 *mask,
					unsigned char *perm)
{
  grad->a = perm[mask->x + perm[mask->y]] & 7;
  grad->b = perm[mask->x + 1 + perm[mask->y]] & 7;
  grad->c = perm[mask->x + perm[mask->y + 1]] & 7;
  grad->d = perm[mask->x + 1 + perm[mask->y + 1]] & 7;
}

static void	calc_perlin_gradient_3d(t_gradient3 *grad, t_mask3 *mask,
					unsigned char *perm)
{
  grad->a = perm[mask->x + perm[mask->y + perm[mask->z]]] & 15;
  grad->b = perm[mask->x + 1 + perm[mask->y + perm[mask->z]]] & 15;
  grad->c = perm[mask->x + perm[mask->y + 1 + perm[mask->z]]] & 15;
  grad->d = perm[mask->x + 1 + perm[mask->y + 1 + perm[mask->z]]] & 15;
  grad->e = perm[mask->x + perm[mask->y + perm[mask->z + 1]]] & 15;
  grad->f = perm[mask->x + 1 + perm[mask->y + perm[mask->z + 1]]] & 15;
  grad->g = perm[mask->x + perm[mask->y + 1 + perm[mask->z + 1]]] & 15;
  grad->h = perm[mask->x + 1 + perm[mask->y + 1 + perm[mask->z + 1]]] & 15;
}

static void	calc_perlin_gradient_4d(t_gradient4 *grad, t_mask4 *m,
					unsigned char *p)
{
  grad->a = p[m->x + p[m->y + p[m->z + p[m->w]]]] & 31;
  grad->b = p[m->x + 1 + p[m->y + p[m->z + p[m->w]]]] & 31;
  grad->c = p[m->x + p[m->y + 1 + p[m->z + p[m->w]]]] & 31;
  grad->d = p[m->x + 1 + p[m->y + 1 + p[m->z + p[m->w]]]] & 31;
  grad->e = p[m->x + p[m->y + p[m->z + 1 + p[m->w]]]] & 31;
  grad->f = p[m->x + 1 + p[m->y + p[m->z + 1 + p[m->w]]]] & 31;
  grad->g = p[m->x + p[m->y + 1 + p[m->z + 1 + p[m->w]]]] & 31;;
  grad->h = p[m->x + 1 + p[m->y + 1 + p[m->z + 1 p[m->w]]]] & 31;
  grad->i = p[m->x + p[m->y + p[m->z + p[m->w + 1]]]] & 31;
  grad->j = p[m->x + 1 + p[m->y + p[m->z + p[m->w + 1]]]] & 31;
  grad->k = p[m->x + p[m->y + 1 + p[m->z + p[m->w + 1]]]] & 31;
  grad->l = p[m->x + 1 + p[m->y + 1 + p[m->z + p[m->w + 1]]]] & 31;
  grad->m = p[m->x + p[m->y + p[m->z + 1 + p[m->w + 1]]]] & 31;
  grad->n = p[m->x + 1 + p[m->y + p[m->z + 1 + p[m->w + 1]]]] & 31;
  grad->o = p[m->x + p[m->y + 1 + p[m->z + 1 + p[m->w + 1]]]] & 31;
  grad->p = p[m->x + 1 + p[m->y + 1 + p[m->z + 1 + p[m->w + 1]]]] & 31;
}

void		calc_perlin_gradient(void *grad, void *mask,
				     unsigned char *perm, int dim)
{
  if (dim == 2)
    calc_perlin_gradient_2d(grad, mask, perm);
  else if (dim == 3)
    calc_perlin_gradient_3d(grad, mask, perm);
  else if (dim == 4)
    calc_perlin_gradient_4d(grad, mask, perm);
}
