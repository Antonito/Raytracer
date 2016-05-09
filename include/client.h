/*
** client.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 10:52:05 2016 Antoine Baché
** Last update Sat May  7 20:41:30 2016 Antoine Baché
*/

#ifndef	CLIENT_H_
# define CLIENT_H_

# include "raytracer.h"

int		client_loop(int fd);

/*
** Load scene
*/
t_scene		*get_scene(int);
int		get_camera(int, t_scene *);
int		get_objs(int, t_scene *);
int		get_lights(int, t_scene *);
int		get_mats(int, t_scene *);
int		get_specs(int, t_scene *);

#endif /* CLIENT_H_  */
