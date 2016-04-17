/*
** material.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun Apr 17 16:36:11 2016 Ludovic Petrenko
** Last update Sun Apr 17 16:44:35 2016 Ludovic Petrenko
*/

#ifndef MATERIAL_H_
# define MATERIAL_H_

typedef struct	s_material
{
  unsigned int	ambiant_color;
  unsigned int	diffuse_color;
  unsigned int	reflection_color;
  unsigned int	specular_color;
  double	ambiant;
  double	diffuse;
  double	reflection;
  double	specular;
  double	opacity;
  double	fresnel;
}		t_material;

#endif /*!MATERIAL_H_ */
