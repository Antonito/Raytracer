/*
** get_next_line.h for gnl in /tek1/semestre_01/CPE_2015_getnextline
**
** Made by Ludovic Petrenko
** Login   <petren_l@epitech.net>
**
** Started on  Tue Mar  8 18:10:48 2016 Ludovic Petrenko
** Last update Wed Mar  9 18:48:38 2016 Ludovic Petrenko
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# include <stdlib.h>
# include <unistd.h>

# ifndef READ_SIZE
#  define READ_SIZE (4096)
# endif /* !READ_SIZE */

char	*get_next_line(const int);
char	*my_strncat(char *, int, char *, int);

#endif /* !GET_NEXT_LINE_H_ */
