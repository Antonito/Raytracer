//Header Epitech

// Dans le nom des fonctions on remplace obj par le nom de l'objet
// On utilise pas ray->pos mais tmp
// Exemple: ray->pos.x devient tmp.x
// Exemple equation de degree 5:
// sol[0]*t^5 + sol[1]*t^4 + sol[2]*t^3 + sol[3]*t^2 + sol[4]*t + sol[5] = 0

#include "solver.h"
#include "engine/intersect.h"
#include "engine/object.h"

//Si degree > 4
#include "tools/memory.h"
inline static void	calc_a_obj(t_ray *ray, t_vec3 tmp)
{
  return (le_calcul_de_a);
}

static void		get_dist_obj(t_obj *obj, t_ray *ray, t_intersect *inter,
				     t_vec3 tmp)
{
  double	*sol;

  if (!(sol = my_malloc((degree + 1) * sizeof(double))))
    return (inter);
  sol[0] = calc_a_obj();
  sol[1] = calc_b_obj();
  ...;
  sol[degree] = ;
  if ((inter->dist = solver_n_degree(sol, degree)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

// Sinon si degree < 5
static void	get_dist_obj(t_obj *obj, t_ray *ray, t_intersect *inter,
			     t_vec3 tmp)
{
  double	sol[degree + 1];

  sol[0] = ...;
  sol[1] = ...;
  ...;
  sol[degree] ;
  // Degree 2 -> solver_second_degree()
  // Degree 3 -> solver_third_degree()
  // Degree 4 -> solver_fourth_degree()
  if ((inter->dist = solver_fourth_degree(a, b, c)) == NOT_A_SOLUTION)
    inter->dist = -1.0;
}

t_intersect	get_intersect_obj(t_obj *obj, t_ray *ray)
{
  t_intersect	inter;

  inter.dir = ray->dir;
  inter.mat = obj->mat;
  inter.dist = -1.0;
  get_dist_obj(obj, ray, &inter, sub_vec3(ray->pos, obj->pos));
  if (inter.dist <= 0.0)
    return (inter);
  //Calcul Normale
  return (inter);
}
