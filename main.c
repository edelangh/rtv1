#include "rtv1.h"

int		ft_draw(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img->img, 0, -1);
	return (0);
}

int		button_pess(int button, int x, int y, t_env *e)
{
	t_vect	ray;

	(void)button;
	e->test = 1;
	create_ray(e, &ray, x, y);
	cast_ray(e, &ray, x, y);
	e->test = 0;
	return (1);
}

void	init_env(t_env *e, int ac, char **av)
{
	if (ac < 2)
		exit(ft_dprintf(2, "usage : %s <map>\n", av[0]));
	e->ac = ac;
	e->av = av;
	e->img = ft_new_img(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->dir.x = 0;
	e->dir.y = 0;
	e->dir.z = 1;
	e->pos.x = 0;
	e->pos.y = 0;
	e->pos.z = -5;
	e->screen = ft_memalloc(sizeof(t_obj));
	init_tab_obj(e, av[1]);
	raytracer(e);
}

int		main(int ac, char **av)
{
	t_env	e;

	ft_bzero(&e, sizeof(t_env));
	if ((e.mlx = mlx_init()))
		if ((e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME)))
		{
			init_env(&e, ac, av);
			mlx_hook(e.win, KEY_PRESS, KEY_PRESS_MASK, ft_key_input, &e);
			mlx_hook(e.win, BUTTON_PRESS, BUTTON_PRESS_MASK, button_pess, &e);
			mlx_expose_hook(e.win, ft_draw, &e);
			mlx_loop(e.mlx);
		}
	if (!e.mlx || !e.win)
		ft_dprintf(2, "%s:mlx init error\n", (ac ? av[0] : NULL));
	return (0);
}
