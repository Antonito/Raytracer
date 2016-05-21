/*
** str.h for Raytracer1 in /gfx_raytracer2/include/tools
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 10:23:14 2016 Antoine Baché
** Last update Sat May 21 22:32:08 2016 Antoine Baché
*/

#ifndef	STR_H_
# define STR_H_

void		my_bzero(void *, int);
void		my_memset(void *, int, const char);
int		my_power(int, const int);
double		my_getdouble(char *);
unsigned int	my_gethexa(const char *);
int		my_getnbr(const char *);
int		my_strlen(const char *);
int		my_strcmp(const char *s1, const char *s2);
int		my_strncmp(const char *s1, const char *s2, int n);
void		my_puterr(const char *);
char		**str_to_wordtab(char *str, char separator);
char		*my_strndup(const char *, int);
char		*my_strdup(const char *);

#endif /* !STR_H_  */
