/*
** log.h for Raytracer2 in /home/ludonope/rendu/semestre_02/gfx_raytracer2
**
** Made by Ludovic Petrenko
** Login   <ludonope@epitech.net>
**
** Started on  Sat Apr 16 16:29:09 2016 Ludovic Petrenko
** Last update Sat Apr 16 16:29:45 2016 Ludovic Petrenko
*/

#ifndef LOG_H_
# define LOG_H_

typedef struct		s_log
{
  int			log_level;
  int			output_fd;
}			t_log;

extern t_log		log_info;

#endif /* !LOG_H_ */
