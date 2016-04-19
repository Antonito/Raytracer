/*
** load_config.c for Raytracer2 in /rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Tue Apr 19 23:13:18 2016 Ludovic Petrenko
** Last update Tue Apr 19 23:48:49 2016 Antoine Baché
*/

#include "raytracer.h"
#include "loader.h"
#include "tools/str.h"

int		load_network(t_data *data, const t_bunny_ini *ini)
{
  const char	*tmp;

  if (!(tmp = bunny_ini_get_field(ini, "network", "port", 0)))
    {
      my_puterr("Missing port in config.ini\n");
      return (1);
    }
  if ((data->network.port = my_getnbr(tmp)) > 65535 || data->network.port < 0)
    {
      my_puterr("Invalid port in config.ini\n"\
		"Choose a port between 0 and 65535\n");
      return (1);
    }
  if (!(tmp = bunny_ini_get_field(ini, "network", "max_client", 0)))
    tmp = "42";
  if ((data->network.max_client = my_getnbr(tmp)) < 0)
    {
      my_puterr("Invalid max_client in config.ini\n");
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
