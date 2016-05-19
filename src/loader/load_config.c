/*
** load_config.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 23:13:18 2016 Ludovic Petrenko
** Last update Thu May 19 02:52:47 2016 Antoine Baché
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/str.h"

static t_effect	load_effect_get(const char * const tmp)
{
  int		i;
  static char	*ref[] =
    {"black_and_white", "pastel", "negative", "bayer", "sepia", "eight_bit",
     "max_filter", "retro", "watercolor", "solarized", "rotate", "contrast"};

  i = 0;
  while (i < NB_EFFECT)
    {
      if (!my_strcmp(tmp, ref[i]))
	return (i);
      ++i;
    }
  return (NO_EFFECT);
}

static int	load_effect(t_data *data, const t_bunny_ini *ini)
{
  const char	*tmp;
  static void	(*effects[])() =
    {load_effect_nothing, load_effect_nothing, load_effect_nothing,
     load_bayer, load_effect_nothing, load_effect_nothing,
     load_effect_nothing, load_effect_nothing, load_effect_nothing,
     load_solarized, load_rotate, load_contrast};

  tmp = NULL;
  if (!(tmp = bunny_ini_get_field(ini, SCOPE_EFFECT, TYPE_FIELD, 0)))
    {
      my_puterr(MISSING_EFFECT_SCOPE);
      return (1);
    }
  if ((data->effect = load_effect_get(tmp)) != NO_EFFECT)
    effects[data->effect](&data->config, ini);
  return (0);
}

static int	load_network(t_data *data, const t_bunny_ini *ini)
{
  const char	*tmp;

  if (!(tmp = bunny_ini_get_field(ini, SCOPE_NETWORK, PORT_NETWORK, 0)))
    {
      my_puterr(MISSING_PORT_ERROR);
      return (1);
    }
  if ((data->network.port = my_getnbr(tmp)) > 65535 || data->network.port < 0)
    {
      my_puterr(INVALID_PORT_ERROR);
      my_puterr(CHOOSE_PORT_ERROR);
      return (1);
    }
  if (!(tmp = bunny_ini_get_field(ini, SCOPE_NETWORK, CLIENT_NETWORK, 0)))
    tmp = MAX_CLIENT_DEFAULT;
  if ((data->network.max_client = my_getnbr(tmp)) < 0)
    {
      my_puterr(MAX_CLIENT_ERROR);
      return (1);
    }
  return (0);
}

int		load_config(t_data *data, const char *file)
{
  t_bunny_ini	*ini;

  if (!(ini = bunny_load_ini(file)))
    {
      my_puterr(ERROR_CONFIG_FILE);
      return (1);
    }
  if (load_network(data, ini) ||
      load_effect(data, ini))
    {
      bunny_delete_ini(ini);
      return (1);
    }
  /* load_keyboard(data, ini); */
  bunny_delete_ini(ini);
  return (0);
}
