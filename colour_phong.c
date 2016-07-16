#include "rtv1.h"

void	colour_reflexion(t_env *env, t_obj *obj, t_vect *n, int a)
{
	t_vect	r;
	t_vect	temp;
	float	colour[5];
	int		k;
	t_obj	*res;

	scalar_multiply(set_to(&r, n), dot_product(n, &(env->save_dir)) * 2);
	subtract(set_to(&temp, &(env->save_dir)), &r);
	normalize(set_to(&r, &temp));
	colour[4] = obj->reflexion;
	k = -1;
	colour[3] = MAX_DIST;
	res = NULL;
	while (env->tab_obj[++k])
		if (k != obj->id && env->tab_obj[k]->hit(env->tab_obj[k],
				env->r_dir, &r, &(colour[3])))
			res = env->tab_obj[k];
	ft_memcpy(colour, &(env->r), sizeof(float) * 3);
	env->r_pos = env->r_dir;
	env->r_dir = &r;
	if (colour[3] != MAX_DIST)
		colour_phong(env, res, colour[3], a - 1);
	env->r = colour[0] * (1 - colour[4]) + (env->r * colour[4]);
	env->v = colour[1] * (1 - colour[4]) + (env->v * colour[4]);
	env->b = colour[2] * (1 - colour[4]) + (env->b * colour[4]);
}

int		colour_specular(t_env *env, t_vect *n, t_spot *spot)
{
	t_vect	inv_spot;
	float	temp;

	set_to(&inv_spot, &(spot->dir));
	scalar_multiply(&inv_spot, -1);
	temp = -dot_product(&inv_spot, n);
	if (temp > 0)
	{
		temp = pow(temp, 64) * spot->i * 0.4;
		env->r += temp;
		env->v += temp;
		env->b += temp;
	}
	return (0);
}

int		colour_diffuse(t_env *env, t_vect *n, t_spot *spot, t_obj *obj)
{
	float	temp;

	temp = dot_product(n, &(spot->dir));
	if (temp > 0)
	{
		env->r += ((float)((obj->colour >> 16) & 0xFF) / 0xFF) *
			spot->r * temp;
		env->v += ((float)((obj->colour >> 8) & 0xFF) / 0xFF) * spot->v * temp;
		env->b += ((float)((obj->colour >> 0) & 0xFF) / 0xFF) * spot->b * temp;
	}
	return (0);
}

int		colour_phong2(t_env *env, t_obj *obj, t_vect *n, int a)
{
	int		k;
	t_vect	intersection;

	k = -1;
	while (++k < env->n_spot)
	{
		add(set_to(&intersection, env->r_pos), env->r_dir);
		if (!try_collision(env, &intersection, obj->id, &(env->spots[k])))
		{
			colour_diffuse(env, n, &(env->spots[k]), obj);
			colour_specular(env, n, &(env->spots[k]));
		}
	}
	if (a && obj->reflexion)
	{
		add(env->r_dir, &(env->pos));
		colour_reflexion(env, obj, n, a);
	}
	env->r = (env->r > 1.0 ? 1.0 : env->r);
	env->v = (env->v > 1.0 ? 1.0 : env->v);
	env->b = (env->b > 1.0 ? 1.0 : env->b);
	return (0);
}

int		colour_phong(t_env *env, t_obj *obj, float dist, int a)
{
	t_vect	n;
	t_vect	*ray;
	t_vect	*r_pos;

	ray = env->r_dir;
	set_to(&(env->save_dir), ray);
	r_pos = env->r_pos;
	env->r = ((float)((obj->colour >> 16) & 0xFF) / 0xFF) * 0.1;
	env->v = ((float)((obj->colour >> 8) & 0xFF) / 0xFF) * 0.1;
	env->b = ((float)((obj->colour >> 0) & 0xFF) / 0xFF) * 0.1;
	scalar_multiply(ray, dist);
	init_spots(env, r_pos, ray);
	obj->norm(&(env->pos), obj, ray, &n);
	return (colour_phong2(env, obj, &n, a));
}
