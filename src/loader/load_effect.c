/*
** load_effect.c for Raytracer2 in /gfx_raytracer2/src/loader
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Wed May 18 22:43:51 2016 Antoine Baché
** Last update Sun May 22 18:44:57 2016 Ludovic Petrenko
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/str.h"

void		load_effect_nothing(t_config *conf, const t_bunny_ini *ini)
{
  (void)conf;
  (void)ini;
}

void		load_solarized(t_config *conf, const t_bunny_ini *ini)
{
  const char	*tmp;

  conf->solarized.max_r = MAX_R_DEFAULT;
  conf->solarized.max_g = MAX_G_DEFAULT;
  conf->solarized.max_b = MAX_B_DEFAULT;
  if ((tmp = bunny_ini_get_field(ini, SCOPE_EFFECT, MAX_R, 0)))
    conf->solarized.max_r = my_getnbr(tmp);
  if ((tmp = bunny_ini_get_field(ini, SCOPE_EFFECT, MAX_G, 0)))
    conf->solarized.max_r = my_getnbr(tmp);
  if ((tmp = bunny_ini_get_field(ini, SCOPE_EFFECT, MAX_B, 0)))
    conf->solarized.max_r = my_getnbr(tmp);
}

void		load_rotate(t_config *conf, const t_bunny_ini *ini)
{
  const char	*tmp;

  conf->rotate.angle_r = ANGLE_R_DEFAULT;
  conf->rotate.angle_g = ANGLE_G_DEFAULT;
  conf->rotate.angle_b = ANGLE_B_DEFAULT;
  if ((tmp = bunny_ini_get_field(ini, SCOPE_EFFECT, ANGLE_R, 0)))
    conf->rotate.angle_r = my_getdouble((char *)tmp);
  if ((tmp = bunny_ini_get_field(ini, SCOPE_EFFECT, ANGLE_G, 0)))
    conf->rotate.angle_g = my_getdouble((char *)tmp);
  if ((tmp = bunny_ini_get_field(ini, SCOPE_EFFECT, ANGLE_B, 0)))
    conf->rotate.angle_b = my_getdouble((char *)tmp);
}

void		load_contrast(t_config *conf, const t_bunny_ini *ini)
{
  const char	*tmp;

  conf->contrast.value = CONTRAST_DEFAULT;
  if ((tmp = bunny_ini_get_field(ini, SCOPE_EFFECT, VALUE, 0)))
    conf->contrast.value = my_getdouble((char *)tmp);
}

void		load_bayer(t_config *conf, const t_bunny_ini *ini)
{
  const char	*tmp;

  conf->bayer.value = BAYER_DEFAULT;
  if ((tmp = bunny_ini_get_field(ini, SCOPE_EFFECT, VALUE, 0)))
    conf->bayer.value = my_getnbr(tmp);
  if (conf->bayer.value < 1)
    conf->bayer.value = BAYER_DEFAULT;
}
