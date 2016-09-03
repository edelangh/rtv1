/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_cyl_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:11:38 by khansman          #+#    #+#             */
/*   Updated: 2016/07/16 15:11:40 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	c2(float x)
{
	float	a;

	a = cos(x);
	return (a * a);
}

float	s2(float x)
{
	float	a;

	a = sin(x);
	return (a * a);
}

int		solv_equa(t_hit_equa *q, t_obj *s, float *t)
{
	float	time;
	float	d;
	float	temp;

	d = q->b * q->b - 4 * q->a * q->c;
	if (d < 0)
		return (0);
	time = (-q->b - sqrt(d)) / (2 * q->a);
	if (time < 0 || time > *t)
		return (0);
	scalar_multiply(set_to(&(q->inter), q->r_dir), time);
	add(&(q->inter), q->r_pos);
	subtract(set_to(&(q->proj), &(q->inter)), &(q->aa));
	temp = dot_product(&(q->ab), &(q->proj)) / q->ab2;
	scalar_multiply(&(q->ab), temp);
	add(&(q->ab), &(q->aa));
	set_to(&(q->proj), &(q->ab));
	subtract(&(q->proj), &(s->pos));
	temp = length_vec(&(q->proj));
	if (temp < s->h)
		*t = time;
	else
		return (0);
	return (1);
}

int		hit_cone(t_obj *s, t_vect *r_pos, t_vect *r_dir, float *t)
{
	t_hit_equa	q;
	float		x;
	float		y;
	t_vect		delta;

	q.r_pos = r_pos;
	q.r_dir = r_dir;
	add(set_to(&(q.aa), &(s->pos)), &(s->dir));
	subtract(set_to(&(q.ab), &(q.aa)), &(s->pos));
	subtract(set_to(&(q.v), r_pos), &(q.aa));
	cross_product(set_to(&(q.oxb), &(q.v)), &(q.ab));
	cross_product(set_to(&(q.v), r_dir), &(q.ab));
	q.ab2 = dot_product(&(q.ab), &(q.ab));
	subtract(set_to(&delta, r_pos), &(s->pos));
	x = dot_product(r_dir, &(s->dir));
	y = dot_product(&delta, &(s->dir));
	q.a = c2(s->r) * dot_product(&(q.v), &(q.v)) - s2(s->r) * x * x;
	q.b = 2 * c2(s->r) * dot_product(&(q.v), &(q.oxb)) - 2 * s2(s->r) * x * y;
	q.c = c2(s->r) * dot_product(&(q.oxb), &(q.oxb)) - s2(s->r) * y * y;
	if (!solv_equa(&q, s, t))
		return (0);
	subtract(set_to(&(s->normal), &(q.inter)), &(s->pos));
	scalar_multiply(normalize(&(q.proj)), length_vec(&(s->normal)) / cos(s->r));
	scalar_multiply(normalize(subtract(&(s->normal), &(q.proj))), -1);
	return (1);
}

int		hit_cylinder(t_obj *s, t_vect *r_pos, t_vect *r_dir, float *t)
{
	t_hit_equa	q;

	q.r_pos = r_pos;
	q.r_dir = r_dir;
	add(set_to(&(q.aa), &(s->pos)), &(s->dir));
	subtract(set_to(&(q.ab), &(q.aa)), &(s->pos));
	subtract(set_to(&(q.v), r_pos), &(q.aa));
	cross_product(set_to(&(q.oxb), &(q.v)), &(q.ab));
	cross_product(set_to(&(q.v), r_dir), &(q.ab));
	q.ab2 = dot_product(&(q.ab), &(q.ab));
	q.a = dot_product(&(q.v), &(q.v));
	q.b = 2 * dot_product(&(q.v), &(q.oxb));
	q.c = dot_product(&(q.oxb), &(q.oxb)) - (s->r * s->r * q.ab2);
	if (!solv_equa(&q, s, t))
		return (0);
	set_to(&(s->normal), &(q.inter));
	add(&(q.proj), &(s->pos));
	subtract(&(s->normal), &(q.proj));
	normalize(&(s->normal));
	scalar_multiply(&(s->normal), -1);
	return (1);
}
