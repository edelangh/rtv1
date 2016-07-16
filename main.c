#include "rtv1.h"

int		ft_draw(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, -1);
	return (0);
}

int		button_pess(int button, int x, int y, t_env *env)
{
	t_vect	ray;

	(void)button;
	env->test = 1;
	create_ray(env, &ray, x, y);
	cast_ray(env, &ray, x, y);
	env->test = 0;
	return (1);
}

void	init_env(t_env *env, int ac, char **av)
{
	if (ac < 2)
		ft_exit(7);
	env->ac = ac;
	env->av = av;
	env->img = ft_new_img(env->mlx, WIN_WIDTH, WIN_HEIGHT);
	env->dir.x = 0;
	env->dir.y = 0;
	env->dir.z = 1;
	env->pos.x = 0;
	env->pos.y = 0;
	env->pos.z = -5;
	env->screen = ft_memalloc(sizeof(t_obj));
	init_tab_obj(env, av[1]);
	raytracer(env);
}

int		main(int ac, char **av)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	if ((env.mlx = mlx_init()))
		if ((env.win = mlx_new_window(env.mlx, WIN_WIDTH,
			WIN_HEIGHT, WIN_NAME)))
		{
			init_env(&env, ac, av);
			mlx_hook(env.win, KEY_PRESS, KEY_PRESS_MASK, ft_key_input, &env);
			mlx_hook(env.win, 17, 0L, ft_exit_prog, (void *)&env);
			mlx_hook(env.win, BUTTON_PRESS, BUTTON_PRESS_MASK,
				button_pess, &env);
			mlx_expose_hook(env.win, ft_draw, &env);
			mlx_loop(env.mlx);
		}
	if (!env.mlx || !env.win)
		ft_exit(8);
	return (0);
}
