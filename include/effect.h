/*
** effect.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 12:36:29 2016 Antoine Baché
** Last update Wed May 18 17:38:45 2016 Antoine Baché
*/

#ifndef EFFECT_H_
# define EFFECT_H_

# include <lapin.h>

typedef enum		e_effect
  {
    NO_EFFECT		= -1,
    BLACK_AND_WHITE,
    PASTEL,
    NEGATIVE,
    BAYER,
    SEPIA,
    EIGHT_BIT,
    MAX_FILER,
    RETRO,
    WATERCOLOR
  }			t_effect;

void			apply_effect(t_bunny_pixelarray *, t_effect, int, int);

/*
** Effects
*/
void			black_and_white_effect(t_color *, int, int);
void			pastel_effect(t_color *, int, int);
void			negative_effect(t_color *, int, int);
void			bayer_effect(t_color *, int, int);
void			sepia_effect(t_color *, int, int);
void			eight_bit_effect(t_color *, int, int);
void			max_filter_effect(t_color *, int, int);
void			retro_effect(t_color *, int, int);
void			watercolor_effect(t_color *, int, int);

#endif /* !EFFECT_H_  */
