/*
** bmp.h for bmp in /home/arnaud_e/rendu/info/gfx_raytracer2/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue May  3 16:39:40 2016 Arthur ARNAUD
** Last update Tue May 10 15:25:49 2016 Arthur ARNAUD
*/

#ifndef BMP_H_
# define BMP_H_

# include "raytracer.h"

typedef enum		e_bmp
  {
    BMP_32 ,
    BMP_24,
    BMP_8
  }			t_bmp;

typedef enum		e_nb_bits
  {

  }			t_nb_bits;

typedef struct		s_bmp_header
{
  unsigned short	sign;
  unsigned int		size;
  unsigned short	reserved1;
  unsigned short	reserved2;
  unsigned int		offset;
  unsigned int		size_header;
  unsigned int		width;
  unsigned int		height;
  unsigned short	nb_planes;
  unsigned short	nb_bits;
  unsigned int		compress_type;
  unsigned int		size_img;
  unsigned int		horizontal;
  unsigned int		vertical;
  unsigned int		nb_color;
  unsigned int		nb_imp_color;
}			__attribute__((packed))t_bmp_header;

#endif /* !BMP_H_ */
