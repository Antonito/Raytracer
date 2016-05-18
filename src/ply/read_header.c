/*
** read_header.c for read_header in info/gfx_raytracer2/src/ply
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Apr 20 10:22:11 2016 Arthur ARNAUD
** Last update Sun May 15 16:03:41 2016 Antoine Baché
*/

#include "ply.h"
#include "tools/str.h"
#include "tools/memory.h"
#include "tools/get_next_line.h"

int		is_in_tab(char *str, char **tab)
{
  int		i;

  i = -1;
  while (tab[++i])
    if (!(my_strcmp(str, tab[i])))
      return (i);
  return (-1);
}

static int	check_format(int fd)
{
  char		*str;

  if (((str = get_next_line(fd)) != NULL && my_strcmp(str, TYPE_FILE)) ||
      my_free(str) ||
      ((str = get_next_line(fd)) != NULL && my_strcmp(str, FORMAT)))
    return (1);
  my_free(str);
  return (0);
}

static int	check_key(int key, char **components, t_ply_info *info)
{
  static int	element = NO_ELEM;
  static int	nb_prop = 0;

  if ((key == ELEMENT && add_element(components, &element, &nb_prop, info)) ||
      (key == PROPERTY &&
       add_property(components, element, &nb_prop, info)))
    return (1);
  return (0);

}

int		read_header(int fd, t_ply_info *info)
{
  char		*str;
  int		key;
  char		**components;

  if (check_format(fd))
    return (1);
  while ((str = get_next_line(fd)) != NULL && my_strcmp(str, END_HEADER))
    {
      if (!(components = str_to_wordtab(str, ' ')) ||
	  (key = is_in_tab(components[KEY], info->list_key)) == -1 ||
	  check_key(key, components, info))
	return (1);
      my_free(components);
      my_free(str);
    }
  my_free(str);
  return (0);
}
