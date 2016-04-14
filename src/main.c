/*
** main.c for Raytracer2 in /home/bache_a/work/Infographie/raytracer2/src
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Apr 14 12:38:13 2016 Antoine Baché
** Last update Thu Apr 14 12:39:18 2016 Antoine Baché
*/

int	main(int ac, char **av, char **env)
{
  if (!*env)
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
