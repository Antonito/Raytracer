/*
** str.h for Raytracer1 in /gfx_raytracer2/include/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 10:23:14 2016 Antoine Baché
** Last update Tue Apr 19 23:40:12 2016 Ludovic Petrenko
*/

#ifndef	STR_H_
# define STR_H_

int		my_power(int, const int);
double		my_getdouble(const char *);
unsigned int	my_gethexa(const char *);
int		my_getnbr(const char *);
int		my_strlen(const char *);
int		my_strcmp(const char *s1, const char *s2);
int		my_strncmp(const char *s1, const char *s2, int n);
void		my_puterr(const char *);

#endif /* !STR_H_  */
