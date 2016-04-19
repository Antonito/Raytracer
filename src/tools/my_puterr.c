/*
** my_puterr.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 23:21:03 2016 Ludovic Petrenko
** Last update Tue Apr 19 23:48:23 2016 Antoine Baché
*/

#include <unistd.h>
#include "tools/str.h"

void	my_puterr(const char *str)
{
  write(2, str, my_strlen(str));
}
