/*
** load_mat.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Mon Apr 18 19:28:33 2016 Ludovic Petrenko
** Last update Wed May 18 18:58:55 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "engine/material.h"
#include "tools/str.h"

void	load_mat_data(t_material *mat, const t_bunny_ini *ini)
{
  char	*tmp;

  mat->color = DEFAULT_MAT_COLOR;
  mat->opacity = DEFAULT_MAT_OPACITY;
  mat->reflectivity = DEFAULT_MAT_REFLECTIVITY;
  mat->fresnel = DEFAULT_MAT_FRESNEL;
  mat->diffuse = DEFAULT_MAT_DIFFUSE;
  mat->specular = DEFAULT_MAT_SPECULAR;
  mat->shininess = DEFAULT_MAT_SHININESS;
  if ((tmp = (char *)bunny_ini_get_field(ini, mat->name, COLOR_FIELD, 0)))
    mat->color = my_gethexa(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, mat->name, OPACITY_FIELD, 0)))
    mat->opacity = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, mat->name, REFLECT_FIELD, 0)))
    mat->reflectivity = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, mat->name, FRESNEL_FIELD, 0)))
    mat->fresnel = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, mat->name, DIFFUSE_FIELD, 0)))
    mat->diffuse = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, mat->name, SPECULAR_FIELD, 0)))
    mat->specular = my_getdouble(tmp);
  if ((tmp = (char *)bunny_ini_get_field(ini, mat->name, SHININESS_FIELD, 0)))
    mat->shininess = my_getdouble(tmp);
}

int			load_mat(t_material *mat, const t_bunny_ini *ini)
{
  t_bunny_ini_scope	*scope;
  int			i;
  const char		*scope_name;

  i = 0;
  if (!(scope = bunny_ini_first((t_bunny_ini *)ini)))
    return (0);
  while ((scope = bunny_ini_next((t_bunny_ini *)ini, scope)))
    {
      scope_name = bunny_ini_scope_name(ini, scope);
      if (scope_name && !my_strncmp(scope_name, MAT_PREFIX, 4))
	{
	  mat[i].name = scope_name;
	  load_mat_data(mat + i, ini);
	  ++i;
	}
    }
  return (0);
}
