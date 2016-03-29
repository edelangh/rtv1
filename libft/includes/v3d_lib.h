/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3d_lib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edelangh <edelangh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 15:34:57 by edelangh          #+#    #+#             */
/*   Updated: 2015/03/20 13:57:12 by edelangh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef V3D_LIB_H
# define V3D_LIB_H

# include <math.h>

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

t_vect			*clamp_vec(t_vect *v1, double min, double max);
t_vect			*cross_product(t_vect *v1, t_vect *v2);
t_vect			*turn_orthogonal(t_vect *v1);
t_vect			*set_to(t_vect *v1, t_vect *v2);
t_vect			*scalar_multiply(t_vect *a, double amount);

t_vect			*add(t_vect *v1, t_vect *v2);
t_vect			*subtract(t_vect *v1, t_vect *v2);
t_vect			*multiply(t_vect *v1, t_vect *v2);
t_vect			*normalize(t_vect *a);
double			clamp(double n, double min, double max);
double			to_rad(double a);

double			saturate(double n);
t_vect			*saturate_vec(t_vect *n);
double			to_rad(double r);
double			dot_product(t_vect *v1, t_vect *v2);
double			length_vec(t_vect *z);
#endif
