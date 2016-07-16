#include "rtv1.h"
#include <fcntl.h>

void	add_spot(t_env *env, char **tab, int size[2])
{
	int	k;

	if (ft_tablen((void**)tab) < 7)
		exit(ft_dprintf(2, "error :Not enouth info for spot"));
	k = env->n_spot;
	env->spots[k].pos.x = ft_atof(tab[1]);
	env->spots[k].pos.y = ft_atof(tab[2]);
	env->spots[k].pos.z = ft_atof(tab[3]);
	env->spots[k].r = ft_atof(tab[4]);
	env->spots[k].v = ft_atof(tab[5]);
	env->spots[k].b = ft_atof(tab[6]);
	env->spots[k].i = ft_atof(tab[7]);
	env->n_spot++;
	if (env->n_spot > size[1])
		exit(ft_dprintf(2, "error :Too many spots !\n"));
}

void	set_obj_triangle(t_obj *obj, char **tab)
{
	obj->hit = &hit_triangle;
	obj->norm = &norm_plane;
	obj->dir.x = ft_atof(tab[1]);
	obj->dir.y = ft_atof(tab[2]);
	obj->dir.z = ft_atof(tab[3]);
	obj->dir2.x = ft_atof(tab[4]);
	obj->dir2.y = ft_atof(tab[5]);
	obj->dir2.z = ft_atof(tab[6]);
	obj->dir3.x = ft_atof(tab[7]);
	obj->dir3.y = ft_atof(tab[8]);
	obj->dir3.z = ft_atof(tab[9]);
}

void	select_type(char **tab, t_obj *obj)
{
	if (!ft_strcmp(tab[0], "Sphere"))
	{
		obj->hit = &hit_sphere;
		obj->norm = &norm_sphere;
	}
	else if (!ft_strcmp(tab[0], "Plane"))
	{
		obj->hit = &hit_plane;
		obj->norm = &norm_plane;
	}
	else if (!ft_strcmp(tab[0], "Triangle"))
		set_obj_triangle(obj, tab);
	else if (!ft_strcmp(tab[0], "Cone"))
	{
		obj->hit = &hit_cone;
		obj->norm = &norm_cylinder;
	}
	else if (!ft_strcmp(tab[0], "Cylinder"))
	{
		obj->hit = &hit_cylinder;
		obj->norm = &norm_cylinder;
	}
}

void	add_obj_to_tab(t_env *env, char **tab, int k, int size[2])
{
	t_obj	*obj;

	if (tab && !ft_strcmp(tab[0], "Spot"))
	{
		add_spot(env, tab, size);
		return ;
	}
	if (!tab || ft_tablen((void**)tab) < 13)
		exit(ft_dprintf(2, "{red}error invalide elem in file{eoc}\n"));
	obj = ft_memalloc(sizeof(t_obj));
	obj->pos.x = ft_atof(tab[1]);
	obj->pos.y = ft_atof(tab[2]);
	obj->pos.z = ft_atof(tab[3]);
	obj->dir.x = ft_atof(tab[4]);
	obj->dir.y = ft_atof(tab[5]);
	obj->dir.z = ft_atof(tab[6]);
	obj->id = k;
	obj->r = ft_atof(tab[10]);
	obj->h = ft_atof(tab[11]);
	obj->colour = ft_ahextocolour(tab[12]);
	obj->reflexion = ft_atof(tab[13]);
	select_type(tab, obj);
	env->tab_obj[k] = obj;
}

void	init_tab_obj(t_env *env, char *src)
{
	t_tab_var var;

	var.line = NULL;
	if ((var.fd = open(src, O_RDONLY)) <= 0)
		exit(ft_dprintf(2, "{red}error can't open file\n{eoc}"));
	ADD_LINE18;
	var.size[0] = ft_atoi(var.tab[0]);
	var.size[1] = ft_atoi(var.tab[1]);
	if (ADD_IF01)
		exit(ft_dprintf(2, "{red}error can't read sizes of file\n{eoc}"));
	env->tab_obj = ft_memalloc(sizeof(t_obj*) * (var.size[0] + 1));
	env->spots = ft_memalloc(sizeof(t_spot) * (var.size[1] + 1));
	while (get_next_line(var.fd, &var.line) > 0)
	{
		if (ADD_IF02)
			add_obj_to_tab(env, var.tab, ++var.k, var.size);
		if (var.k > var.size[0])
			exit(ft_dprintf(2, "{red}error too many objs\n{eoc}"));
		ft_freetab(var.tab);
		free(var.line);
	}
}
