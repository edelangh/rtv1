#include "rtv1.h"

void	norm_cylinder(t_vect *r_pos, t_obj *obj, t_vect *ray, t_vect *n)
{
	set_to(n, &(obj->normal));
	(void)r_pos;
	(void)ray;
}

int		hit_triangle(t_obj *m, t_vect *r_pos, t_vect *r_dir, float *out)
{
	t_var_tri	var;

	subtract(set_to(&var.e[0], &(m->dir2)), &(m->dir));
	subtract(set_to(&var.e[1], &(m->dir3)), &(m->dir));
	cross_product(set_to(&var.p[0], r_dir), &var.e[1]);
	if (ADD_LINE9)
		return (0);
	var.inv = 1.0 / var.det;
	subtract(set_to(&var.p[1], r_pos), &(m->dir));
	if (ADD_LINE12)
		return (0);
	cross_product(&var.p[1], &var.e[0]);
	if (ADD_LINE15)
		return (0);
	if ((var.v[2] = dot_product(&var.e[1], &var.p[1]) * var.inv) > 0.000001)
	{
		*out = var.v[2];
		return (1);
	}
	return (0);
}
