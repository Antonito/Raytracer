/*
** material.h for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sun Apr 17 16:36:11 2016 Ludovic Petrenko
** Last update Wed May 18 22:56:32 2016 Ludovic Petrenko
*/

#ifndef MATERIAL_H_
# define MATERIAL_H_

# define DEFAULT_MAT_COLOR		0xFFFFFFFF
# define DEFAULT_MAT_OPACITY		1.0
# define DEFAULT_MAT_REFLECTIVITY	0.2
# define DEFAULT_MAT_FRESNEL		1.0
# define DEFAULT_MAT_DIFFUSE		1.0
# define DEFAULT_MAT_SPECULAR		1.0
# define DEFAULT_MAT_AMBIANT		0.3
# define DEFAULT_MAT_SHININESS		1.0

typedef struct	s_material
{
  const char	*name;
  unsigned int	color;
  double	opacity;
  double	diffuse;
  double	specular;
  double	shininess;
  double	reflectivity;
  double	fresnel;
}		t_material;

#endif /*!MATERIAL_H_ */
