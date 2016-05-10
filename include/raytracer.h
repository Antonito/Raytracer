/*
** raytracer.h for Raytracer2 in /raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Thu Apr 14 12:39:45 2016 Antoine Baché
** Last update Tue May 10 13:04:36 2016 Antoine Baché
*/

#ifndef	RAYTRACER2_H_
# define RAYTRACER2_H_

# include <lapin.h>
# include <stdbool.h>
# include "engine/scene.h"
# include "config.h"
# include "events.h"
# include "tools/memory.h"

# define DEFAULT_WIDTH		1280
# define DEFAULT_HEIGHT		720
# define WIN_NAME		"Ray Ta Soeur"
# define UNUSED			__attribute__((unused))
# define MAX_RECURSIVE		50
# define MINIMUM_FPS		15

/*
** Scopes expected in .ini files
*/
# define SCOPE_NETWORK		"network"
# define PORT_NETWORK		"port"
# define CLIENT_NETWORK		"max_client"
# define RADIUS_FIELD		"radius"
# define NORMALE_FIELD		"normale"
# define HEIGHT_FIELD		"height"
# define COLOR_FIELD		"color"
# define POWER_FIELD		"power"
# define DIR_FIELD		"direction"
# define ANGLE_FIELD		"angle"
# define OPACITY_FIELD		"opacity"
# define REFLECT_FIELD		"reflectivity"
# define FRESNEL_FIELD		"fresnel"
# define POS_FIELD		"position"
# define ROT_FIELD		"rotation"
# define MAT_FIELD		"material"
# define CAM_FIELD		"camera"
# define FOV_FIELD		"fov"
# define FOCALE_FIELD		"focale"
# define SCENE_FIELD		"scene"
# define BACK_FIELD		"bg_color"
# define AMB_FIELD		"ambiant"
# define MAT_PREFIX		"mat_"
# define OBJ_PREFIX		"obj_"
# define LIGHT_PREFIX		"light_"
# define RADIUS_TORE_FIELD	"radius_hole"
# define RADIUS_TORE_FIELD2	"radius_solid"

/*
** Default configuration
*/
# define CONFIG_FILE		"config.ini"
# define SCENE_DEFAULT		"scenes/default.ini"
# define MAX_CLIENT_DEFAULT	"42"

/*
** Error messages
*/
# define MISSING_PORT_ERROR    	"Missing port in config.ini\n"
# define INVALID_PORT_ERROR	"Invalid port in config.ini\n"
# define CHOOSE_PORT_ERROR     	"Choose a port between 0 and 65535\n"
# define MAX_CLIENT_ERROR    	"Invalid max_client in config.ini\n"
# define NEW_CLIENT_ERROR	"Error: Cannot accept new client\n"
# define MAX_CLIENT_REACHED	"Max number of client reached\n"
# define INIT_SERVER_ERROR	"Error: Cannot start server\n"
# define SOCKET_ERROR		"Error: Cannot create scoket\n"
# define LISTEN_ERROR		"Error: Cannot listen\n"
# define CREATE_THREAD_ERROR	"Error: Cannot create the TCP thread\n"
# define THREAD_ERROR		"Error: In TCP thread\n"

/*
** Dhiver messages
*/
# define NEW_CLIENT		"New client added\n"
# define NEW_CLIENT_CONNECTED	"Infos: New client connected\n"
# define WAIT_CLIENT		"Waiting for clients...\n"

typedef struct		s_network
{
  int			fd;
  int			port;
  int			max_client;
  int			*clients;
  bool			run;
  bool			all_connected;
  bool			draw;
}			t_network;

typedef struct		s_data
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*render;
  int			width;
  int			height;
  int			cur_width;
  int			cur_height;
  bool			fullscreen;
  t_scene		*scene;
  t_config		config;
  t_network		network;
}			t_data;

typedef struct		s_calc_fragment
{
  t_data		*data;
  t_ivec2		pos[2];
}			t_calc_fragment;

int			init_data(int ac, char **av, t_data **data);
int			launch_raytracer(t_data *data);
t_bunny_response	main_events(UNUSED t_bunny_event_state s,
				    UNUSED t_bunny_keysym k,
				    t_data *data);
t_bunny_response	main_loop(t_data *data);
int			set_frame(t_data *data);
void			calc_fragment(t_data *data, unsigned int *buf,
				      t_ivec2 *pos);
unsigned int		calc_ray(t_scene *scene, t_ray *ray, int i);
void			set_vectors(t_data *data, t_camera *c);
void			refresh_size(t_data *data, int frame);
void			blit_scaled(t_bunny_pixelarray *, t_bunny_pixelarray *);
int			free_raytracer(t_data *data, int ret);

#endif /* RAYTRACER2_H_ */
