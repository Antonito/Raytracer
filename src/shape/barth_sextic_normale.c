/*
** barth_sextic_normale.c for  in /gfx_raytracer2/src/shape
**
** Made by Arthur ARNAUD
** Login   <arnaud_e@epitech.net>
**
** Started on  Sun May 22 22:00:49 2016 Arthur ARNAUD
** Last update Sun May 22 22:20:35 2016 Arthur ARNAUD
*/

#include "engine/object.h"
#include "engine/intersect.h"

double	calc_x_derivative_barth(t_intersect *inter, t_vec3 tmp)
{
  return (((67938836298975792826966180.0 * tmp.z -
	    177866182664101167128215686.0
	    * tmp.y - 27481836562087133724513660.0) * tmp.x * inter->pos.x +
	   (-88933091332050583564107843.0 * tmp.z * tmp.z +
	    (219854692860001482357451080.0 * tmp.y -
	     27481836562087133724513660.0) * tmp.z + 33969418149487896413483090.0
	    * tmp.y * tmp.y -27481836562087133724513660.0 * tmp.y * tmp.y
	    + 27481836562087133724513660.0) * inter->pos.x)
	  / 1621895393606402022125985.0);
}

double	calc_y_derivative_barth(t_intersect *inter, t_vec3 tmp)
{
  return (-((177866182664101167128215686.0 * tmp.z -
	     67938836298975792826966180.0
	     * tmp.x + 27481836562087133724513660.0) * tmp.y * inter->pos.y +
	    (-33969418149487896413483090.0 * tmp.z * tmp.z +
	     (27481836562087133724513660.0 - 219854692860001482357451080.0
	      * tmp.x) * tmp.z + 88933091332050583564107843.0 * tmp.x * tmp.x +
	     27481836562087133724513660.0 * tmp.x - 27481836562087133724513660.0)
	    * inter->pos.y) / 1621895393606402022125985.0);
}

double	calc_z_derivative_barth(t_intersect *inter, t_vec3 tmp)
{
  return (((67938836298975792826966180.0 * tmp.y -
	    177866182664101167128215686.0
	    * tmp.x - 27481836562087133724513660.0) * tmp.z * inter->pos.z +
	   (-88933091332050583564107843.0 * tmp.y * tmp.y +
	    (219854692860001482357451080.0 * tmp.x -
	     27481836562087133724513660.0) *
	    tmp.y + 33969418149487896413483090.0 * tmp.x * tmp.x -
	    27481836562087133724513660.0 * tmp.x + 27481836562087133724513660.0)
	   * inter->pos.z) / 1621895393606402022125985.0);
}

void	calc_normale_barth(t_intersect *inter)
{
  calc_normale(calc_x_derivative_barth, calc_y_derivative_barth,
	       calc_z_derivative_barth,
	       inter);
}
