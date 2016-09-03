/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 07:44:59 by khansman          #+#    #+#             */
/*   Updated: 2016/08/16 07:45:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	change_camera(t_env *env, char **tab)
{
	env->pos.x = ft_atof(tab[1]);
	env->pos.y = ft_atof(tab[2]);
	env->pos.z = ft_atof(tab[3]);
	env->dir.x = ft_atof(tab[4]);
	env->dir.y = ft_atof(tab[5]);
	env->dir.z = ft_atof(tab[6]);
	env->yaw = ft_atof(tab[7]);
	env->pitch = ft_atof(tab[8]);
}
