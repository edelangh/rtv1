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

# define WIN_RATIO ((double)WIN_WIDTH / WIN_HEIGHT)
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

typedef struct	s_spot
{
	t_vect		pos;
	double		r;
	double		v;
	double		b;
	double		i;
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
	double		r;
	double		h;
	double		reflexion;
	int			colour;
	int			id;
	int			(*hit)(struct s_obj*, t_vect*, t_vect*, double*);
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
	double		pitch;
	double		yaw;
	double		r;
	double		v;
	double		b;
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
	double		a;
	double		b;
	double		c;
	double		ab2;
}				t_hit_equa;

int				ft_key_input(int key, t_env *e);
int				ft_draw(t_env *e);

void			raytracer(t_env *e);
void			create_ray(t_env *e, t_vect *ray, int x, int y);
int				cast_ray(t_env *e, t_vect *ray, int x, int y);
int				colour_phong(t_env *e, t_obj *obj, double dist, int a);
int				try_collision(t_env *e, t_vect *r_pos, int id, t_spot *spot);
void			init_spots(t_env *e, t_vect *r_pos, t_vect *r_dir);
void			init_tab_obj(t_env *e, char *src);
int				hit_sphere(t_obj *s, t_vect *r_pos, t_vect *r_dir, double *t);
void			norm_sphere(t_vect *r_pos, t_obj *obj, t_vect *ray, t_vect *n);
int				hit_plane(t_obj *p, t_vect *r_pos, t_vect *r_dir, double *t);
void			norm_plane(t_vect *r_pos, t_obj *obj, t_vect *ray, t_vect *n);
int				hit_cylinder(t_obj *s, t_vect *r_pos, t_vect *r_dir, double *t);
void			norm_cylinder(t_vect *r_pos, t_obj *o, t_vect *ray, t_vect *n);
int				hit_triangle(t_obj *s, t_vect *r_pos, t_vect *r_dir, double *t);
int				hit_cone(t_obj *c, t_vect *r_pos, t_vect *r_dir, double *t);
int				ft_ahextocolour(char *ahex);
#endif
