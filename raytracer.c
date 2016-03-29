/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 12:01:16 by edelangh          #+#    #+#             */
/*   Updated: 2015/03/22 11:07:05 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	create_ray(t_env *e, t_vect *ray, int x, int y)
{
	double	xx;
	double	yy;

	xx = (2 * (x / (double)WIN_WIDTH) - 1) * (double)WIN_RATIO * ZOOM_FACTOR;
	yy = (1 - 2 * (y / (double)WIN_HEIGHT)) * ZOOM_FACTOR;
	ray->x = -cos(e->pitch) * sin(e->yaw)
		+ xx * cos(e->yaw) + yy * sin(e->pitch) * sin(e->yaw);
	ray->y = sin(e->pitch) + yy * cos(e->pitch);
	ray->z = cos(e->pitch) * cos(e->yaw)
		+ xx * sin(e->yaw) - yy * sin(e->pitch) * cos(e->yaw);
	normalize(ray);
}

void	init_spots(t_env *e, t_vect *r_pos, t_vect *r_dir)
{
	int		i;

	i = -1;
	while (++i < e->n_spot)
	{
		set_to(&(e->spots[i].dir), r_dir);
		add(&(e->spots[i].dir), r_pos);
		subtract(&(e->spots[i].dir), &(e->spots[i].pos));
		normalize(&(e->spots[i].dir));
	}
}

int		try_collision(t_env *e, t_vect *r_pos, int id, t_spot *spot)
{
	double	dist;
	int		i;
	t_vect	a;

	i = -1;
	set_to(&a, &(spot->pos));
	subtract(&a, r_pos);
	dist = length_vec(&a);
	normalize(&a);
	while (e->tab_obj[++i])
	{
		if (e->tab_obj[i]->id != id &&
				e->tab_obj[i]->hit(e->tab_obj[i], r_pos, &a, &dist))
			return (1);
	}
	return (0);
}

int		cast_ray(t_env *e, t_vect *ray, int x, int y)
{
	double	dist;
	int		color;
	t_obj	*res;
	int		i;

	i = -1;
	dist = MAX_DIST;
	res = NULL;
	while (e->tab_obj[++i])
		if (e->tab_obj[i]->hit(e->tab_obj[i], &e->pos, ray, &dist))
			res = e->tab_obj[i];
	if (dist != MAX_DIST)
	{
		e->r_dir = ray;
		e->r_pos = &(e->pos);
		color_phong(e, res, dist, 1);
		color = ((int)(e->r * 0xFF) << 16) | ((int)(e->v * 0xFF) << 8)
											| (int)(e->b * 0xFF);
		ft_pixel_put_to_image(e->img, x, y, color);
		return (1);
	}
	return (0);
}

void	raytracer(t_env *e)
{
	int		x;
	int		y;
	t_vect	ray;

	set_to(&(e->screen->pos), &(e->dir));
	add(&(e->screen->pos), &(e->pos));
	set_to(&(e->screen->dir), &(e->dir));
	y = -1;
	while (x = -1, ++y < e->img->height)
		while (++x < e->img->width)
		{
			create_ray(e, &ray, x, y);
			cast_ray(e, &ray, x, y);
		}
}
