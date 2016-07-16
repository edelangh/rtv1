#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "ft_mlx.h"
# include "ft_printf.h"
# include "v3d_lib.h"
# include "get_next_line.h"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# define WIN_WIDTH 640
# define WIN_HEIGHT 480
# define WIN_NAME "rtv1"

# define WIN_RATIO ((float)WIN_WIDTH / WIN_HEIGHT)
# define FOV 45.0
# define FOV_X_DEG 45.0
# define FOV_Y_DEG (FOV * WIN_RATIO)
# define FOV_X (FOV_X_DEG * M_PI / 180.0)
# define FOV_Y (FOV_Y_DEG * M_PI / 180.0)
# define ANGLE_X FOV_X / (WIN_WIDTH / 2)
# define ANGLE_Y FOV_Y / (WIN_HEIGHT / 2)
# define MAX_DIST 500.0
# define ZOOM_FACTOR_CALC tan(M_PI * 0.5 * 45.0 / 180)
# define ZOOM_FACTOR 0.39269908

# define ADD_LINE1 add(&(env->pos), &(env->dir)),
# define ADD_LINE2	env->yaw -= M_PI / 2
# define ADD_LINE3 ADD_LINE1 ADD_LINE2
# define ADD_LINE4 add(&(env->pos), &(env->dir)),
# define ADD_LINE5 env->yaw += M_PI / 2
# define ADD_LINE6 ADD_LINE4 ADD_LINE5
# define ADD_LINE7 (det = dot_product(&e[0], &p[0])),
# define ADD_LINE8 det > -0.000001 && det < 0.000001
# define ADD_LINE9 ADD_LINE7 ADD_LINE8
# define ADD_LINE10 (v[0] = dot_product(&p[1], &p[0]) * inv),
# define ADD_LINE11 v[0] < 0 || v[0] > 1
# define ADD_LINE12 ADD_LINE10 ADD_LINE11
# define ADD_LINE13 (v[1] = dot_product(r_dir, &p[1]) * inv),
# define ADD_LINE14 v[1] < 0 || v[0] + v[1] > 1
# define ADD_LINE15 ADD_LINE13 ADD_LINE14
# define ADD_LINE16 get_next_line(fd, &line),
# define ADD_LINE17 tab = ft_strsplit(line, ' ')
# define ADD_LINE18 ADD_LINE16 ADD_LINE17
# define ADD_LINE19 (tab = ft_strsplit(line, ' ')),
# define ADD_LINE20 tab && tab[0] && tab[0][0] != '#'
# define ADD_IF01 k = -1, !size[0] || !size[1]
# define ADD_IF02 ADD_LINE19 ADD_LINE20
# define ADD_IF03 x = -1, ++y < env->img->height

typedef struct	s_spot
{
	t_vect		pos;
	float		r;
	float		v;
	float		b;
	float		i;
	t_vect		dir;
}				t_spot;

typedef struct	s_obj
{
	t_vect		pos;
	t_vect		dir;
	t_vect		dir2;
	t_vect		dir3;
	t_vect		normal;
	int			type;
	float		r;
	float		h;
	float		reflexion;
	int			colour;
	int			id;
	int			(*hit)(struct s_obj*, t_vect*, t_vect*, float*);
	void		(*norm)(t_vect*, struct s_obj*, t_vect*, t_vect*);
}				t_obj;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			ac;
	char		**av;
	int			test;
	t_img		*img;
	t_vect		pos;
	t_vect		dir;
	t_vect		save_dir;
	t_spot		*spots;
	t_vect		*r_dir;
	t_vect		*r_pos;
	int			n_spot;
	t_obj		**tab_obj;
	t_obj		*screen;
	float		pitch;
	float		yaw;
	float		r;
	float		v;
	float		b;
}				t_env;

typedef struct	s_hit_equa
{
	t_vect		ab;
	t_vect		ao;
	t_vect		aa;
	t_vect		oxb;
	t_vect		v;
	t_vect		inter;
	t_vect		proj;
	t_vect		*r_dir;
	t_vect		*r_pos;
	float		a;
	float		b;
	float		c;
	float		ab2;
}				t_hit_equa;

int				ft_key_input(int key, t_env *e);
int				ft_draw(t_env *e);

void			raytracer(t_env *e);
void			create_ray(t_env *e, t_vect *ray, int x, int y);
int				cast_ray(t_env *e, t_vect *ray, int x, int y);
int				colour_phong(t_env *e, t_obj *obj, float dist, int a);
int				try_collision(t_env *e, t_vect *r_pos, int id, t_spot *spot);
void			init_spots(t_env *e, t_vect *r_pos, t_vect *r_dir);
void			init_tab_obj(t_env *e, char *src);
int				hit_sphere(t_obj *s, t_vect *r_pos, t_vect *r_dir, float *t);
void			norm_sphere(t_vect *r_pos, t_obj *obj, t_vect *ray, t_vect *n);
int				hit_plane(t_obj *p, t_vect *r_pos, t_vect *r_dir, float *t);
void			norm_plane(t_vect *r_pos, t_obj *obj, t_vect *ray, t_vect *n);
int				hit_cylinder(t_obj *s, t_vect *r_pos, t_vect *r_dir, float *t);
void			norm_cylinder(t_vect *r_pos, t_obj *o, t_vect *ray, t_vect *n);
int				hit_triangle(t_obj *s, t_vect *r_pos, t_vect *r_dir, float *t);
int				hit_cone(t_obj *c, t_vect *r_pos, t_vect *r_dir, float *t);
int				ft_ahextocolour(char *ahex);
#endif
