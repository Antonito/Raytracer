/*
** noise.h for Raytracer2 in /gfx_raytracer2/include
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Mon Apr 18 11:54:08 2016 Antoine Baché
** Last update Mon Apr 18 12:35:19 2016 Antoine Baché
*/

#ifndef NOISE_H_
# define NOISE_H_

# include "tools/types.h"
# include "engine/vector.h"

double		perlin_noise(void *, float, int);

t_vec2		*perlin_2d_table(void);
t_vec3		*perlin_3d_table(void);
t_vec4		*perlin_4d_table(void);
void		perlin_4d_table_last(t_vec4 *);

#endif /* !NOISE_H_ */
