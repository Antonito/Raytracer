/*
** load_config.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 23:13:18 2016 Ludovic Petrenko
** Last update Thu Apr 21 17:52:00 2016 Antoine Baché
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/str.h"

int		load_network(t_data *data, const t_bunny_ini *ini)
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
    return (1);
  if (load_network(data, ini))
    {
      bunny_delete_ini(ini);
      return (1);
    }
  /* load_keyboard(data, ini); */
  bunny_delete_ini(ini);
  return (0);
}
