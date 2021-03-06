/*
** ply.h for ply in /home/arnaud_e/rendu/info/gfx_raytracer2/include
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Wed Apr 20 09:57:10 2016 Arthur ARNAUD
** Last update Sun May 22 03:45:38 2016 Antoine Baché
*/

#ifndef PLY_H_
# define PLY_H_

# include <lapin.h>
# include "engine/vector.h"

# define LIST_ELEM		"no_elem vertex face"
# define LIST_V_VAR		"x y z red green blue alpha nx ny nz"
# define COORD_TYPE		"float"
# define COLOR_TYPE		"uchar"
# define LIST_F_VAR1		"vertex_indices texcoord "
# define LIST_F_VAR2		"texnumber red green blue alpha"
# define LIST_F_VAR		LIST_F_VAR1 LIST_F_VAR2
# define LIST_KEY		"comment property element"
# define TYPE_FILE		"ply"
# define FORMAT			"format ascii 1.0"
# define END_HEADER		"end_header"

typedef enum	e_key
{
  COMMENT,
  PROPERTY,
  ELEMENT
}		t_key;

typedef enum	e_element
{
  NO_ELEM,
  VERTEX,
  FACE
}		t_element;

typedef enum	e_desc
  {
    KEY,
    TYPE,
    VALUE
  }		t_desc;

typedef enum	e_vertex_property
  {
    V_X,
    V_Y,
    V_Z,
    V_RED,
    V_GREEN,
    V_BLUE,
    V_ALPHA,
    V_NX,
    V_NY,
    V_NZ,
    NB_V_VAR
  }		t_vertex_property;

typedef enum	e_face_property
  {
    F_VERTICES_INDICES,
    F_TEXCOORD,
    F_TEXNUMBER,
    F_RED,
    F_GREEN,
    F_BLUE,
    F_ALPHA,
    NB_F_VAR
  }		t_face_property;

typedef struct	s_vertex
{
  t_vec3	vec;
  t_color	color;
  bool		get_color;
}		t_vertex;

typedef struct	s_face
{
  int		*face;
  double	*texcoord;
  int		nb_face;
  int		nb_tex;
  int		texnumber;
  t_color	color;
}		t_face;

typedef struct	s_ply_info
{
  int		nb_vertex;
  int		nb_face;
  char		**list_elem;
  char		**list_v_var;
  char		**list_f_var;
  char		**list_key;
  int		vertex_prop[NB_V_VAR];
  int		face_prop[NB_F_VAR];
}		t_ply_info;

typedef struct	s_ply
{
  int		nb_vertex;
  int		nb_face;
  t_vertex	*list_vertex;
  t_face	*list_face;
}		t_ply;

t_ply		*get_ply(char *);
int		add_element(char **, int *, int *, t_ply_info *);
int		add_property(char **, int, int *, t_ply_info *);
int		check_vertex_var(char **, char **);
int		check_face_var(char **, char **, int);
int		count_prop(const int * const, int);
int		init_info(t_ply_info *);
int		init_ply(t_ply *, t_ply_info *);
int		is_in_tab(char *, char **);
int		read_header(int, t_ply_info *);
int		fill_face(t_ply *, t_ply_info *, int);
int		fill_vertex(t_ply *, t_ply_info *, int);
int		fill_ply(t_ply *, t_ply_info *, int);
int		*add_list_face(char **, int *, int *, int);
double		*add_list_texcoord(char **, int *, int *, int);
int		parse_color_face(t_color *, char **, int *, int);
int		parse_color_vertex(t_color *, char **, int *, bool *);
void		free_tab(char **tab);
void		free_ply_info(t_ply_info *info);
void		free_ply(t_ply *ply);
void		resize_ply(t_ply *ply, double ratio);

#endif /* !PLY_H_ */
