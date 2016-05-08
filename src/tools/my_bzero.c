/*
** my_bzero.c for Raytracer2 in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sat May  7 21:31:16 2016 Antoine Baché
** Last update Sat May  7 21:31:37 2016 Antoine Baché
*/

void		my_bzero(void *content, int size)
{
  unsigned char	*addr;

  addr = content;
  while (size--)
    addr[size] = 0;
}
