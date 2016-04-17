/*
** packet.c for Raytracer2 in /gfx_raytracer2/src/cluster
**
** Made by Antoine Baché
** Login   <bache_a@epitech.net>
**
** Started on  Sun Apr 17 15:17:11 2016 Antoine Baché
** Last update Sun Apr 17 17:41:49 2016 Antoine Baché
*/

#include "tools/types.h"

void		write_int(char *packet, int pos, int nb)
{
  char		*tmp;

  tmp = (char *)&nb;
  packet[pos] = tmp[0];
  packet[pos + 1] = tmp[1];
  packet[pos + 2] = tmp[2];
  packet[pos + 3] = tmp[3];
}

void		fill_uint(char *packet, int pos, unsigned int *nb)
{
  char		*tmp;

  tmp = (char *)nb;
  tmp[0] = packet[pos];
  tmp[1] = packet[pos + 1];
  tmp[2] = packet[pos + 2];
  tmp[3] = packet[pos + 3];
}

void		fill_int(char *packet, int pos, int *nb)
{
  char		*tmp;

  tmp = (char *)nb;
  tmp[0] = packet[pos];
  tmp[1] = packet[pos + 1];
  tmp[2] = packet[pos + 2];
  tmp[3] = packet[pos + 3];
}

void		create_packet(char *packet, unsigned int *pixels, int id,
			      t_coord *coord)
{
  int		pos;
  int		i;

  i = -1;
  pos = 16;
  write_int(packet, 0, id);
  write_int(packet, 4, coord[0].x);
  write_int(packet, 8, coord[0].y);
  write_int(packet, 12, coord[1].x);
  write_int(packet, 16, coord[1].y);
  while (pixels)
    {
      ++i;
      pos += 4;
      write_int(packet, pos, pixels[i]);
    }
}

void		read_packet(char *packet, t_bunny_pixelarray *pix, int size)
{
  int		index;
  int		i;
  int		pos;
  t_coord	coord[2];
  t_bunny_color	*colors;

  fill_int(packet, 0, &index);
  fill_int(packet, 4, &coord[0].x);
  fill_int(packet, 8, &coord[0].y);
  fill_int(packet, 12, &coord[1].x);
  fill_int(packet, 16, &coord[1].y);
  pos = 16;
  colors = pix[index].pixels;
  i = -1;
  while (i < size)
    {
      ++i;
      pos += 4;
      fill_uint(packet, pos, &colors[i + pos].full);
    }
}
