/*
** main.c for Raytracer2 in /home/bache_a/work/Infographie/raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Apr 14 12:38:13 2016 Antoine Baché
** Last update Thu May  5 17:15:42 2016 Ludovic Petrenko
*/

#include <unistd.h>
#include "raytracer.h"
#include "solver.h"

int		main(int ac, char **av, char **env)
{
  t_data	*data;

  if (!*env || init_data(ac, av, &data) ||
      launch_raytracer(data))
    {
#ifdef	DEBUG
      write(1, "Status: KO\n", 11);
#endif
      return (1);
    }
#ifdef	DEBUG
  write(1, "Status: OK\n", 11);
#endif
  return (0);
}
