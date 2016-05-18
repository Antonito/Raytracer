/*
** export_img.c for export_img in info/gfx_raytracer2/src/export
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Tue May  3 17:46:16 2016 Arthur ARNAUD
** Last update Tue May 10 18:00:37 2016 Arthur ARNAUD
*/

#include "bmp.h"

int	fill_header(t_bunny_pixelarray* pix,
		    t_bmp_header *header,
		    int mode,
		    short *tab)
{
  if (!(header = malloc(sizeof(t_bmp_header *))))
    return (1);
  header->sign = 0x424D;
  header->reserved1 = 0;
  header->reserved2 = 0;
  header->offset = 40;
  header->size_header = 40;
  header->width = pix->clipable.clip_width;
  header->height = pix->clipable.clip_height;
  header->size_img = pix->clipable.clip_width * pix->clipable.clip_height;
  header->nb_bits = tab[mode];
  header->nb_planes = 1;
  header->compress_type = 0;
  header->horizontal = DEFAULT_WIDTH;
  header->vertical = DEFAULT_HEIGHT;
  header->nb_color = 0;
  header->nb_imp_color = 0;
  return (0);
}

int	export_img(t_bunny_pixelarray *pix, int	mode)
{
  t_bmp_header	*bmp_header;

  bmp_header = NULL;
  if (fill_header(pix, bmp_header, mode, (short *){24, 24, 8})
      || (fd = create_file(bmp_header)) == -1
      ||fill_bmp(fd, pix, bmp_header, mode))
    return (1);
  return (0);
}
