/*
** effect.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 12:36:29 2016 Antoine Baché
** Last update Sun May 22 20:15:44 2016 Ludovic Petrenko
*/

#ifndef EFFECT_H_
# define EFFECT_H_

# define CONTRAST_DEFAULT	200.0
# define BAYER_DEFAULT		2
# define ANGLE_R_DEFAULT	1.0
# define ANGLE_G_DEFAULT	1.3
# define ANGLE_B_DEFAULT	1.5
# define MAX_R_DEFAULT 		152
# define MAX_G_DEFAULT 		116
# define MAX_B_DEFAULT 		124

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
    MAX_FILTER,
    RETRO,
    WATERCOLOR,
    SOLARIZED,
    ROTATE,
    CONTRAST,
    STAINEDGLASS,
    NB_EFFECT
  }			t_effect;

typedef struct		s_solarized
{
  int			max_r;
  int			max_g;
  int			max_b;
}			t_solarized;

typedef struct		s_rotate
{
  double		angle_r;
  double		angle_g;
  double		angle_b;
}			t_rotate;

typedef struct		s_contrast
{
  int			value;
}			t_contrast;

typedef struct		s_bayer
{
  int			value;
}			t_bayer;

typedef struct		s_pastel
{
  int			radius;
  int			level;
}			t_pastel;

typedef struct		s_stainedglass
{
  int			nb_points;
  int			seed;
}			t_stainedglass;

# include "config.h"

void			antialiasing(t_bunny_pixelarray *pix, int ratio);
void			apply_effect(t_bunny_pixelarray *, t_effect, void *);

/*
** Effects
*/
void			bayer_effect(t_color *, int, int, t_config *);
void			black_and_white_effect(t_color *, int, int, t_config *);
void			contrast_effect(t_color *, int, int, t_config *);
void			eight_bit_effect(t_color *, int, int, t_config *);
void			max_filter_effect(t_color *, int, int, t_config *);
void			negative_effect(t_color *, int, int, t_config *);
void			pastel_effect(t_color *, int, int, t_config *);
void			retro_effect(t_color *, int, int, t_config *);
void			rotate_effect(t_color *, int, int, t_config *);
void			sepia_effect(t_color *, int, int, t_config *);
void			solarized_effect(t_color *, int, int, t_config *);
void			stained_glass_effect(t_color *, int, int, t_config *);
void			watercolor_effect(t_color *, int, int, t_config *);

#endif /* !EFFECT_H_  */
