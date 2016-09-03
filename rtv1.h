/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:12:40 by khansman          #+#    #+#             */
/*   Updated: 2016/09/03 13:49:20 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

/*
**	Includes
*/

# include "libft.h"
# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

/*
**		Old Includes:
**			include "ft_mlx.h"
**			include "v3d_lib.h"
**			include "get_next_line.h"
*/

/*
**	Defines
*/

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
# define ADD_LINE7 (var.det = dot_product(&var.e[0], &var.p[0])),
# define ADD_LINE8 var.det > -0.000001 && var.det < 0.000001
# define ADD_LINE9 ADD_LINE7 ADD_LINE8
# define ADD_LINE10 (var.v[0] = dot_product(&var.p[1], &var.p[0]) * var.inv),
# define ADD_LINE11 var.v[0] < 0 || var.v[0] > 1
# define ADD_LINE12 ADD_LINE10 ADD_LINE11
# define ADD_LINE13 (var.v[1] = dot_product(r_dir, &var.p[1]) * var.inv),
# define ADD_LINE14 var.v[1] < 0 || var.v[0] + var.v[1] > 1
# define ADD_LINE15 ADD_LINE13 ADD_LINE14
# define ADD_LINE16 get_next_line(var.fd, &var.line),
# define ADD_LINE17 var.tab = ft_strsplit(var.line, ' ')
# define ADD_LINE18 (ADD_LINE16 ADD_LINE17)
# define ADD_LINE19 (var.tab = ft_strsplit(var.line, ' ')),
# define ADD_LINE20 var.tab && var.tab[0] && var.tab[0][0] != '#'
# define ADD_LINE21 remove_tabs(&(var.line))
# define ADD_LINE22 (y = -1), ++x < i->width
# define ADD_IF01 var.k = -1, !var.size[0] || !var.size[1]
# define ADD_IF02 ADD_LINE21 && (ADD_LINE19 ADD_LINE20)
# define ADD_IF03 x = -1, ++y < env->img->height
# define FREE00 ft_free2d(var.tab);free(var.line)
# define SET_VAR t_tab_var var;var.line = NULL

# define ERR01 "\e[31mError: Not enouth info for spot\e[0m"
# define ERR02 "\e[31mError: Too many spots !\n\e[0m"
# define ERR03 "\e[31mError: invalide elem in file\n\e[0m"
# define ERR04 "\e[31mError: can't open file\n\e[0m"
# define ERR05 "\e[31mError: can't read sizes of file\n\e[0m"
# define ERR06 "\e[31mError: too many objs\n\e[0m"
# define ERR07 "\e[31mError: Too few arguments\n\e[0m"
# define ERR08 "\e[31mError: mlx init failed\n\e[0m"

# define HEX_STR "0123456789ABCDEF"
# define DEC_STR "0123456789"
# define ALL_STR "Sphere\nPlane\nTriangle\nCone\nCylinder\nSpot"
# define CAM_ANG_ADJ 0.1

# define MLX_KEY_UP 126
# define MLX_KEY_DOWN 125
# define MLX_KEY_LEFT 123
# define MLX_KEY_RIGHT 124
# define MLX_KEY_PLUS1 24
# define MLX_KEY_MINUS1 27
# define MLX_KEY_ESC 53
# define MLX_KEY_A 0
# define MLX_KEY_S 1
# define MLX_KEY_D 2
# define MLX_KEY_Q 12
# define MLX_KEY_W 13
# define MLX_KEY_E 14
# define MLX_KEY_O 31
# define MLX_KEY_P 35
# define MLX_KEY_L 37
# define MLX_KEY_K 40

# define MLX_KEY_0 29
# define MLX_KEY_1 18
# define MLX_KEY_2 19
# define MLX_KEY_3 20
# define MLX_KEY_4 21
# define MLX_KEY_5 23
# define MLX_KEY_6 22
# define MLX_KEY_7 26
# define MLX_KEY_8 28
# define MLX_KEY_9 29

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define BUTTON_PRESS 4
# define BUTTON_RELEASE 5
# define MOTION_NOTIFY 6
# define KEY_PRESS_MASK (1L<<0)
# define KEY_RELEASE_MASK (1L<<1)
# define BUTTON_PRESS_MASK (1L<<2)
# define BUTTON_RELEASE_MASK (1L<<3)
# define MOTION_NOTIFY_MASK (1L<<6)

/*
**	Structures
*/

typedef unsigned int	t_uint;

typedef struct		s_vect
{
	double			x;
	double			y;
	double			z;
}					t_vect;

typedef struct		s_img
{
	void			*img;
	char			*data;
	unsigned int	*udata;
	int				width;
	int				height;
	int				endian;
	int				bpp;
	int				sizeline;
	int				sl_div;
	int				bpp_div;
}					t_img;

typedef struct		s_spot
{
	t_vect			pos;
	float			r;
	float			v;
	float			b;
	float			i;
	t_vect			dir;
}					t_spot;

typedef struct		s_obj
{
	t_vect			pos;
	t_vect			dir;
	t_vect			dir2;
	t_vect			dir3;
	t_vect			normal;
	int				type;
	float			r;
	float			h;
	float			reflexion;
	int				colour;
	int				id;
	int				(*hit)(struct s_obj*, t_vect*, t_vect*, float*);
	void			(*norm)(t_vect*, struct s_obj*, t_vect*, t_vect*);
}					t_obj;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				ac;
	char			**av;
	int				test;
	t_img			*img;
	t_vect			pos;
	t_vect			dir;
	t_vect			save_dir;
	t_spot			*spots;
	t_vect			*r_dir;
	t_vect			*r_pos;
	int				n_spot;
	t_obj			**tab_obj;
	t_obj			*screen;
	float			pitch;
	float			yaw;
	float			r;
	float			v;
	float			b;
	int				clear_img;
}					t_env;

typedef struct		s_hit_equa
{
	t_vect			ab;
	t_vect			ao;
	t_vect			aa;
	t_vect			oxb;
	t_vect			v;
	t_vect			inter;
	t_vect			proj;
	t_vect			*r_dir;
	t_vect			*r_pos;
	float			a;
	float			b;
	float			c;
	float			ab2;
}					t_hit_equa;

typedef struct		s_col_var
{
	t_vect			r;
	t_vect			temp;
	float			colour[5];
	int				k;
	t_obj			*res;
}					t_col_var;

typedef struct		s_tab_var
{

	int				k;
	int				fd;
	char			*line;
	char			**tab;
	int				size[2];
}					t_tab_var;

typedef struct		s_var_shp
{
	t_vect			dist;
	float			b;
	float			d;
	float			k[2];
	int				ret;
}					t_var_sph;

typedef struct		s_var_tri
{
	t_vect			e[2];
	t_vect			p[2];
	float			inv;
	float			det;
	float			v[3];
}					t_var_tri;

/*
**	Prototypes
*/

int					ft_key_input(int key, t_env *e);
int					ft_draw(t_env *e);

void				raytracer(t_env *e);
void				create_ray(t_env *e, t_vect *ray, int x, int y);
int					cast_ray(t_env *e, t_vect *ray, int x, int y);
int					colour_phong(t_env *e, t_obj *obj, float dist, int a);
int					try_collision(t_env *e, t_vect *r_pos, int id, \
		t_spot *spot);
void				init_spots(t_env *e, t_vect *r_pos, t_vect *r_dir);
void				init_tab_obj(t_env *e, char *src);
int					hit_sphere(t_obj *s, t_vect *r_pos, t_vect *r_dir, \
		float *t);
void				norm_sphere(t_vect *r_pos, t_obj *obj, t_vect *ray, \
		t_vect *n);
int					hit_plane(t_obj *p, t_vect *r_pos, t_vect *r_dir, float *t);
void				norm_plane(t_vect *r_pos, t_obj *obj, t_vect *ray, \
		t_vect *n);
int					hit_cylinder(t_obj *s, t_vect *r_pos, t_vect *r_dir, \
		float *t);
void				norm_cylinder(t_vect *r_pos, t_obj *o, t_vect *ray, \
		t_vect *n);
int					hit_triangle(t_obj *s, t_vect *r_pos, t_vect *r_dir, \
		float *t);
int					hit_cone(t_obj *c, t_vect *r_pos, t_vect *r_dir, float *t);
int					ft_ahextocolour(char *ahex);

/*
**		functions to rewrite:
*/

double				dot_product(t_vect *v1, t_vect *v2);
t_vect				*clamp_vec(t_vect *v1, double min, double max);
double				clamp(double n, double min2, double max2);
t_vect				*turn_orthogonal(t_vect *v1);
t_vect				*cross_product(t_vect *v1, t_vect *v2);
t_vect				*scalar_multiply(t_vect *a, double amount);
t_vect				*normalize(t_vect *a);
t_vect				*multiply(t_vect *v1, t_vect *v2);
t_vect				*add(t_vect *v1, t_vect *v2);
t_vect				*subtract(t_vect *v1, t_vect *v2);
t_vect				*set_to(t_vect *v1, t_vect *v2);
t_vect				*clamp_vec(t_vect *v1, double min, double max);
double				clamp(double n, double min2, double max2);
t_vect				*turn_orthogonal(t_vect *v1);
t_vect				*cross_product(t_vect *v1, t_vect *v2);
double				length_vec(t_vect *z);
t_vect				*scalar_multiply(t_vect *a, double amount);
void				ft_fill_img(t_img *i, unsigned int color);
t_uint				ft_get_pixel_from_image(t_img *i, int x, int y);
void				ft_pixel_put_to_image(t_img *i, int x, int y, \
		unsigned int color);
t_img				*ft_load_img(void *mlx, char *src);
t_img				*ft_new_img(void *mlx, int width, int height);
size_t				ft_tablen(void **tab);
double				ft_atof(const char *str);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
size_t				ft_len_untill(const char *str, char c);
char				*ft_strrev(char *s);

/*
**		newer functions:
*/

void				ft_exit(int error);
int					ft_exit_prog(t_env *env);
int					count_tabs(char **tab);
int					val_tab_count(char **tab);
int					remove_tabs(char **str);
void				change_camera(t_env *env, char **tab);
int					valid_object(char *str);

#endif
