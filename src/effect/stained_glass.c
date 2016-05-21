/*
** stained_glass.c for Raytracer 2 in /home/asphahyre/rendu/gfx_raytracer2/src/effect
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Fri May 20 21:24:07 2016 Luka Boulagnon
** Last update Sat May 21 07:50:32 2016 Luka Boulagnon
*/

#include "raytracer.h"
#include "tools/memory.h"
#include "tools/math.h"

void		stained_glass_effect(t_color *pix, int height, int width,
				     t_config *conf)
{
  t_color	*sum;

  if (conf->pastel.radius >= height * width
      || !(sum = my_calloc(height * width, sizeof(t_color))))
    return ;
  (void)pix;
  my_free(sum);
}
