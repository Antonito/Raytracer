/*
** network.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Apr 17 14:38:13 2016 Antoine Baché
** Last update Sun Apr 17 18:01:29 2016 Antoine Baché
*/

#ifndef NETWORK_H_
# define NETWORK_H_

# define		CONNECTION_DELAY	15

# ifdef _WIN32
#  include <windows.h>
#  include <winsock2.h>
# endif /* _WIN32 */
# include <netdb.h>
# include <arpa/inet.h>
# include <sys/socket.h>
# include "tools/types.h"
# include "raytracer.h"

int			init_server(t_data *);

/*
** packet.c
*/
void			write_int(char *, int, int);
void			fill_int(char *, int, int *);
void			fill_uint(char *, int, unsigned int *);
void			create_packet(char *, unsigned int *, int, t_coord *);
void			read_packet(char *, t_bunny_pixelarray *, int);

/*
** connection.c
*/
void			connect_to_server(t_data *);

#endif /* !NETWORK_H_ */
