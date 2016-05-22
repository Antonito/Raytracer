/*
** bmp.c for Raytracer 2 in /home/asphahyre/rendu/gfx_raytracer2/src/tools
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sun May 22 15:40:04 2016 Luka Boulagnon
** Last update Sun May 22 21:50:55 2016 Luka Boulagnon
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "raytracer.h"
#include "bmp.h"

void			read_pixels(t_bunny_pixelarray *p, t_bmp_header header,
				    int fd, t_bmp type)
{
  t_color		buff;

  while (header.height--)
    {
      header.width = 0;
      while (header.width < (long)p->clipable.clip_width)
	{
	  read(fd, &buff, type);
	  ((t_color *)p->pixels)[header.height * p->clipable.clip_width
	    + header.width].argb[0] = buff.argb[type - 1];
	  ((t_color *)p->pixels)[header.height * p->clipable.clip_width
	    + header.width].argb[1] = buff.argb[type - 2];
	  ((t_color *)p->pixels)[header.height * p->clipable.clip_width
	    + header.width].argb[2] = buff.argb[type - 3];
	  ((t_color *)p->pixels)[header.height * p->clipable.clip_width
	    + header.width].argb[3] = (type == BMP_32) ? buff.argb[0] : 255;
	  ++header.width;
	}
    }
}

static int		len(const char *s)
{
  return (*s ? len(s + 1) + 1 : 0);
}

static void		*error(const char *err, const char *path)
{
  write(2, "[31m", 5);
  write(2, err, len(err));
  write(2, ": ", 2);
  write(2, path, len(path));
  write(2, "[0m\n", 5);
  return (NULL);
}

t_bunny_pixelarray	*load_bmp(const char *path)
{
  int			fd;
  t_bmp			type;
  t_bmp_header		hd;
  t_bunny_pixelarray	*pic;
  t_color		buff;

  if ((fd = open(path, O_RDONLY)) == -1)
    return (error("File not found", path));
  read(fd, &hd, sizeof(t_bmp_header));
  if (hd.nb_bits == 32)
    type = BMP_32;
  else if (hd.nb_bits == 24)
    type = BMP_24;
  else
    return (error("Invalid BMP format", path));
  if (!(pic = bunny_new_pixelarray(hd.width, hd.height)))
    return (error("File to heavy", path));
  hd.width = 0;
  while (++hd.width < 22)
    read(fd, &buff, type);
  read_pixels(pic, hd, fd, type);
  close(fd);
  return (pic);
}

int			save_bmp(t_bunny_pixelarray *pix, const char *path)
{
  int			fd;
  t_bmp_header		header;
  int			x;
  int			y;

  if ((fd = open(path, O_WRONLY | O_TRUNC | O_CREAT,
		 S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
    return (!error("Can't open file for writing", path));
  x = pix->clipable.clip_width;
  y = pix->clipable.clip_height;
  header = (t_bmp_header){19778, x * y * 3 + 122, 0, 0, 122,
    108, x, y, 1, 24, 0, x * y * 3, 3779, 3779, 0, 0};
  write(fd, &header, sizeof(header));
  write(fd, (char [66]){0}, 66);
  while (x = -1, y--)
    while (++x < (int)header.width)
      {
	write(fd, ((t_color *)pix->pixels)[y * pix->clipable.clip_width
	      + x].argb + 1, 1);
	write(fd, ((t_color *)pix->pixels)[y * pix->clipable.clip_width
	      + x].argb + 0, 1);
	write(fd, ((t_color *)pix->pixels)[y * pix->clipable.clip_width
	      + x].argb + 2, 1);
      }
  return (0);
}
