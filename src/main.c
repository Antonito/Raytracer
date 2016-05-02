/*
** main.c for Raytracer2 in /home/bache_a/work/Infographie/raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Apr 14 12:38:13 2016 Antoine Baché
** Last update Mon May  2 01:55:13 2016 Antoine Baché
*/

#include <math.h>
#include <sys/time.h>
#include "tools/math.h"

#include <unistd.h>
#include "raytracer.h"
#include "solver.h"

int		main(int ac, char **av, char **env)
{
  t_data	*data;

  printf("Sol = %f\n", solver_third_degree(24.0, -32.0, 23.0, -89.0));
  return (0);
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
