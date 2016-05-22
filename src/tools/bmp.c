/*
** bmp.c for Raytracer 2 in /home/asphahyre/rendu/gfx_raytracer2/src/tools
** 
** Made by Luka Boulagnon
** Login   <boulag_l@epitech.net>
** 
** Started on  Sun May 22 15:40:04 2016 Luka Boulagnon
** Last update Sun May 22 17:33:45 2016 Luka Boulagnon
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
	    + header.width].argb[0] = buff.argb[3 - (type == BMP_24)];
	  ((t_color *)p->pixels)[header.height * p->clipable.clip_width
	    + header.width].argb[1] = buff.argb[2 - (type == BMP_24)];
	  ((t_color *)p->pixels)[header.height * p->clipable.clip_width
	    + header.width].argb[2] = buff.argb[1 - (type == BMP_24)];
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
  while (++hd.width < 22 * 1)
    read(fd, &buff, type);
  read_pixels(pic, hd, fd, type);
  close(fd);
  return (pic);
}
