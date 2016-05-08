/*
** my_memset.c for Raytracer in /gfx_raytracer2/src/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun May  8 17:39:38 2016 Antoine Baché
** Last update Sun May  8 17:39:57 2016 Antoine Baché
*/


void		my_memset(void *content, int size, const char c)
{
  unsigned char	*addr;

  addr = content;
  while (size--)
    addr[size] = c;
}
