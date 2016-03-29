/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_calc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 15:32:58 by edelangh          #+#    #+#             */
/*   Updated: 2015/02/14 14:45:50 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "v3d_lib.h"

t_vect	*normalize(t_vect *a)
{
	return (scalar_multiply(a, 1 / length_vec(a)));
}

t_vect	*multiply(t_vect *v1, t_vect *v2)
{
	v1->x *= v2->x;
	v1->y *= v2->y;
	v1->z *= v2->z;
	return (v1);
}

t_vect	*add(t_vect *v1, t_vect *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
	return (v1);
}

t_vect	*subtract(t_vect *v1, t_vect *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
	return (v1);
}

t_vect	*set_to(t_vect *v1, t_vect *v2)
{
	v1->x = v2->x;
	v1->y = v2->y;
	v1->z = v2->z;
	return (v1);
}
