/*
** main.c for Raytracer2 in /home/bache_a/work/Infographie/raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Apr 14 12:38:13 2016 Antoine Baché
** Last update Fri May 20 19:24:20 2016 Ludovic Petrenko
*/

#include <unistd.h>
#include "raytracer.h"

#include <time.h>
#include <stdio.h>
#include "solver.h"
#include "tools/math.h"
int		main(int ac, char **av, char **env)
{
  t_data	*data;

  double oui[5] = {0};
  double non[5];
  double	sol[2];
  int		tot[2] = {0};

  srand(time(NULL));
  while (0)
    {
      while (oui[0] == 0)
	oui[0] = non[0] = rand() % 1000 - 500;
      oui[1] = non[1] = rand() % 1000 - 500;
      oui[2] = non[2] = rand() % 1000 - 500;
      oui[3] = non[3] = rand() % 1000 - 500;
      oui[4] = non[4] = rand() % 1000 - 500;
      sol[1] = solver_fourth_degree(oui[0], oui[1], oui[2], oui[3], oui[4]);
      sol[0] = solver_n_degree(non, 4);
      if (sol[1] == NOT_A_SOLUTION || sol[1] <= 0.0)
	sol[1] = -1.0;
      if (fabs(sol[0] - sol[1]) > 0.0001)
	{
	  printf("\e[31m%d/%d\e[0m === %f\n", tot[0], tot[1], 1.0 * tot[0] / tot[1]);
	  printf("N: \e[32m%f\e[0m | 4th: \e[91m%f\e[0m\n", sol[0], sol[1]);
	  printf("(%.0fx^4) + (%.0fx^3) + (%.0fx^2) + (%.0fx) + (%.0f)\n", oui[0], oui[1], oui[2], oui[3], oui[4]);
	  /* printf("(%.0fx^2) + (%.0fx) + (%.0f)\n", oui[0], oui[1], oui[2]); */
	  read(0, (char[1]){0}, 1);
	  tot[0]++;
	}
      tot[1]++;
      oui[0] = 0;
    }
  if (!*env || init_data(ac, av, &data) || launch_raytracer(data))
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
