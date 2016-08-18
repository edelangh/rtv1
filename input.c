/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:11:07 by khansman          #+#    #+#             */
/*   Updated: 2016/07/16 15:11:08 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	ft_key_input3(int key, t_env *env)
{
	if (key == MLX_KEY_W)
		env->pos.z += env->dir.z;
	else if (key == MLX_KEY_S)
		env->pos.z -= env->dir.z;
	else if (key == MLX_KEY_Q)
	{
		env->pitch += M_PI / 2;
		create_ray(env, &(env->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
		add(&(env->pos), &(env->dir));
		env->pitch -= M_PI / 2;
	}
	else if (key == MLX_KEY_E)
	{
		env->pitch -= M_PI / 2;
		create_ray(env, &(env->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
		add(&(env->pos), &(env->dir));
		env->pitch += M_PI / 2;
	}
	else
		return (1);
	return (0);
}

static int	ft_key_input2(int key, t_env *env)
{
	if (key == MLX_KEY_ESC)
		exit(0);
	else if (key == MLX_KEY_UP)
		env->pitch += CAM_ANG_ADJ;
	else if (key == MLX_KEY_DOWN)
		env->pitch -= CAM_ANG_ADJ;
	else if (key == MLX_KEY_LEFT)
		env->yaw += CAM_ANG_ADJ;
	else if (key == MLX_KEY_RIGHT)
		env->yaw -= CAM_ANG_ADJ;
	else if (key == MLX_KEY_A)
	{
		env->yaw += M_PI / 2;
		create_ray(env, &(env->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
		ADD_LINE3;
	}
	else if (key == MLX_KEY_D)
	{
		env->yaw -= M_PI / 2;
		create_ray(env, &(env->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
		ADD_LINE6;
	}
	else
		return (ft_key_input3(key, env));
	return (0);
}

int			ft_key_input(int key, t_env *env)
{
	ft_key_input2(key, env);
	create_ray(env, &(env->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
	raytracer(env);
	ft_draw(env);
	return (0);
}
