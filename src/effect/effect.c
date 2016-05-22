/*
** effect.c for Raytracer2 in /home/bache_a/work/Infographie/gfx_raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 12:39:56 2016 Antoine Baché
** Last update Sun May 22 21:18:30 2016 Antoine Baché
*/

#include "raytracer.h"

void		apply_effect(t_bunny_pixelarray *pix, t_effect effect,
			     void *data)
{
  static void	(*effect_func[])() =
    { black_and_white_effect, pastel_effect, negative_effect, bayer_effect,
      sepia_effect, eight_bit_effect, solarized_effect,
      rotate_effect, contrast_effect, stained_glass_effect};

  effect_func[effect]((t_color *)pix->pixels, ((t_data *)data)->config.height,
		      ((t_data *)data)->config.width,
		      &((t_data *)data)->config);
}
