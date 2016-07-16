#include "rtv1.h"

int		hit_plane(t_obj *p, t_vect *r_pos, t_vect *r_dir, double *t)
{
	t_vect	temp;
	double	d;

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

int		hit_sphere(t_obj *s, t_vect *r_pos, t_vect *r_dir, double *t)
{
	t_vect	dist;
	double	b;
	double	d;
	double	k[2];
	int		ret;

	ret = 0;
	subtract(set_to(&dist, &s->pos), r_pos);
	b = dot_product(r_dir, &dist);
	d = (b * b) - dot_product(&dist, &dist) + (s->r * s->r);
	if (d < 0.0f)
		return (0);
	k[0] = b - sqrtf(d);
	k[1] = b + sqrtf(d);
	if ((k[0] > 0.1f) && (k[0] < *t))
	{
		*t = k[0];
		ret = 1;
	}
	if ((k[1] > 0.1) && (k[1] < *t))
	{
		*t = k[1];
		ret = 1;
	}
	return (ret);
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
