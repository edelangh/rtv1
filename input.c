/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 15:06:05 by edelangh          #+#    #+#             */
/*   Updated: 2015/03/22 12:21:58 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_key_input2(int key, t_env *e)
{
	if (key == 53)
		exit(0);
	else if (key == 126)
		e->pitch += 0.2;
	else if (key == 125)
		e->pitch -= 0.2;
	else if (key == 123)
		e->yaw += 0.2;
	else if (key == 124)
		e->yaw -= 0.2;
	else if (key == 12)
	{
		e->yaw += M_PI / 2;
		create_ray(e, &(e->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
		add(&(e->pos), &(e->dir)), e->yaw -= M_PI / 2;
	}
	else if (key == 2)
	{
		e->yaw -= M_PI / 2;
		create_ray(e, &(e->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
		add(&(e->pos), &(e->dir)), e->yaw += M_PI / 2;
	}
	else
		return (1);
	return (0);
}

int		ft_key_input(int key, t_env *e)
{
	ft_dprintf(1, "key pressed : %d\n", key);
	if (!ft_key_input2(key, e))
		(void)e;
	else if (key == 6)
	{
		add(&(e->pos), &(e->dir));
	}
	else if (key == 1)
		subtract(&(e->pos), &(e->dir));
	create_ray(e, &(e->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
	raytracer(e);
	ft_draw(e);
	return (0);
}
