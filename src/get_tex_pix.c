/*
** get_tex_pix.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat May 21 12:59:29 2016 Ludovic Petrenko
** Last update Sat May 21 14:34:24 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "tools/types.h"
#include "noise.h"

unsigned int	get_tex_pix(t_bunny_pixelarray *pix, t_vec2 pos)
{
  t_ivec2	p;
  unsigned int	*pixels;
  double	x;
  t_color	c;

  p.x = pix->clipable.clip_width * (pos.x + 1) / 2.0;
  p.y = pix->clipable.clip_height * (pos.y + 1) / 2.0;
  pixels = pix->pixels;
  return (pixels[p.x + p.y * pix->clipable.clip_width]);
  /* c.argb[0] = c.argb[1] = c.argb[2] = 10 * (simplex_noise(&pos, 10.0, 2, DRAW)); */
  /* return (c.full); */
}
