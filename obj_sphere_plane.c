#include "rtv1.h"

int		hit_plane(t_obj *p, t_vect *r_pos, t_vect *r_dir, float *t)
{
	t_vect	temp;
	float	d;

	set_to(&temp, r_pos);
	subtract(&temp, &(p->pos));
	d = -(dot_product(&p->dir, &temp) / dot_product(&p->dir, r_dir));
	if (d > -0.0001 && d < *t)
	{
		*t = d;
		return (1);
	}
	return (0);
}

int		hit_sphere(t_obj *s, t_vect *r_pos, t_vect *r_dir, float *t)
{
	t_var_sph	var;

	var.ret = 0;
	subtract(set_to(&var.dist, &s->pos), r_pos);
	var.b = dot_product(r_dir, &var.dist);
	var.d = (var.b * var.b) - dot_product(&var.dist, &var.dist)
		+ (s->r * s->r);
	if (var.d < 0.0f)
		return (0);
	var.k[0] = var.b - sqrtf(var.d);
	var.k[1] = var.b + sqrtf(var.d);
	if ((var.k[0] > 0.1f) && (var.k[0] < *t))
	{
		*t = var.k[0];
		var.ret = 1;
	}
	if ((var.k[1] > 0.1) && (var.k[1] < *t))
	{
		*t = var.k[1];
		var.ret = 1;
	}
	return (var.ret);
}

void	norm_plane(t_vect *r_pos, t_obj *obj, t_vect *ray, t_vect *n)
{
	set_to(n, &(obj->dir));
	normalize(n);
	if (dot_product(n, ray) < 0)
		scalar_multiply(n, -1);
	(void)r_pos;
	(void)ray;
}

void	norm_sphere(t_vect *r_pos, t_obj *obj, t_vect *ray, t_vect *n)
{
	set_to(n, ray);
	add(n, r_pos);
	subtract(n, &(obj->pos));
	scalar_multiply(n, -1);
	normalize(n);
}
