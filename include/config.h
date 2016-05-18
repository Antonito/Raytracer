/*
** config.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Fri Apr 15 01:30:32 2016 Ludovic Petrenko
** Last update Wed May 18 23:45:33 2016 Antoine Baché
*/

#ifndef CONFIG_H_
# define CONFIG_H_

# include "effect.h"

typedef struct		s_config
{
  union
  {
    t_contrast		contrast;
    t_rotate		rotate;
    t_solarized		solarized;
  };
}			t_config;

#endif /* !CONFIG_H_ */
