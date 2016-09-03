/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 15:32:37 by edelangh          #+#    #+#             */
/*   Updated: 2015/02/14 13:05:30 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	dot_product(t_vect *v1, t_vect *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double	to_rad(double r)
{
	return (r * M_PI / 180.0);
}

double	saturate(double n)
{
	return (clamp(n, 0.0, 1.0));
}

t_vect	*saturate_vec(t_vect *n)
{
	return (clamp_vec(n, 0.0, 1.0));
}

double	length_vec(t_vect *z)
{
	return (sqrt(z->x * z->x + z->y * z->y + z->z * z->z));
}
