/*
** config.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 01:30:32 2016 Ludovic Petrenko
** Last update Sat May 21 07:59:05 2016 Luka Boulagnon
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# include "effect.h"

typedef struct		s_config
{
  bool			fullscreen;
  int			cur_height;
  int			cur_width;
  int			height;
  int			minimum_fps;
  int			width;
  union
  {
    t_bayer		bayer;
    t_contrast		contrast;
    t_pastel		pastel;
    t_rotate		rotate;
    t_solarized		solarized;
    t_stainedglass	stainedglass;
  };
}			t_config;

#endif /* !CONFIG_H_ */
