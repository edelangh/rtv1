#include "rtv1.h"

void	create_ray(t_env *env, t_vect *ray, int x, int y)
{
	float	xx;
	float	yy;

	xx = (2 * (x / (float)WIN_WIDTH) - 1) * (float)WIN_RATIO * ZOOM_FACTOR;
	yy = (1 - 2 * (y / (float)WIN_HEIGHT)) * ZOOM_FACTOR;
	ray->x = -cos(env->pitch) * sin(env->yaw)
		+ xx * cos(env->yaw) + yy * sin(env->pitch) * sin(env->yaw);
	ray->y = sin(env->pitch) + yy * cos(env->pitch);
	ray->z = cos(env->pitch) * cos(env->yaw)
		+ xx * sin(env->yaw) - yy * sin(env->pitch) * cos(env->yaw);
	normalize(ray);
}

void	init_spots(t_env *env, t_vect *r_pos, t_vect *r_dir)
{
	int		k;

	k = -1;
	while (++k < env->n_spot)
	{
		set_to(&(env->spots[k].dir), r_dir);
		add(&(env->spots[k].dir), r_pos);
		subtract(&(env->spots[k].dir), &(env->spots[k].pos));
		normalize(&(env->spots[k].dir));
	}
}

int		try_collision(t_env *env, t_vect *r_pos, int id, t_spot *spot)
{
	float	dist;
	int		k;
	t_vect	a;

	k = -1;
	set_to(&a, &(spot->pos));
	subtract(&a, r_pos);
	dist = length_vec(&a);
	normalize(&a);
	while (env->tab_obj[++k])
	{
		if (env->tab_obj[k]->id != id &&
				env->tab_obj[k]->hit(env->tab_obj[k], r_pos, &a, &dist))
			return (1);
	}
	return (0);
}

int		cast_ray(t_env *env, t_vect *ray, int x, int y)
{
	float	dist;
	int		colour;
	t_obj	*res;
	int		k;

	k = -1;
	dist = MAX_DIST;
	res = NULL;
	while (env->tab_obj[++k])
		if (env->tab_obj[k]->hit(env->tab_obj[k], &env->pos, ray, &dist))
			res = env->tab_obj[k];
	if (dist != MAX_DIST)
	{
		env->r_dir = ray;
		env->r_pos = &(env->pos);
		colour_phong(env, res, dist, 1);
		colour = ((int)(env->r * 0xFF) << 16) | ((int)(env->v * 0xFF) << 8)
											| (int)(env->b * 0xFF);
		ft_pixel_put_to_image(env->img, x, y, colour);
		return (1);
	}
	return (0);
}

void	raytracer(t_env *env)
{
	int		x;
	int		y;
	t_vect	ray;

	set_to(&(env->screen->pos), &(env->dir));
	add(&(env->screen->pos), &(env->pos));
	set_to(&(env->screen->dir), &(env->dir));
	y = -1;
	while (ADD_IF03)
		while (++x < env->img->width)
		{
			create_ray(env, &ray, x, y);
			cast_ray(env, &ray, x, y);
		}
}
