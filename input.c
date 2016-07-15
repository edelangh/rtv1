#include "rtv1.h"

int		ft_key_input2(int key, t_env *env)
{
	if (key == 53)
		exit(0);
	else if (key == 126)
		env->pitch += 0.2;
	else if (key == 125)
		env->pitch -= 0.2;
	else if (key == 123)
		env->yaw += 0.2;
	else if (key == 124)
		env->yaw -= 0.2;
	else if (key == 12)
	{
		env->yaw += M_PI / 2;
		create_ray(env, &(env->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
		add(&(env->pos), &(env->dir)), env->yaw -= M_PI / 2;
	}
	else if (key == 2)
	{
		env->yaw -= M_PI / 2;
		create_ray(env, &(env->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
		add(&(env->pos), &(env->dir)), env->yaw += M_PI / 2;
	}
	else
		return (1);
	return (0);
}

int		ft_key_input(int key, t_env *env)
{
	ft_dprintf(1, "key pressed : %d\n", key);
	if (!ft_key_input2(key, env))
		(void)env;
	else if (key == 6)
	{
		add(&(env->pos), &(env->dir));
	}
	else if (key == 1)
		subtract(&(env->pos), &(env->dir));
	create_ray(env, &(env->dir), WIN_WIDTH / 2, WIN_HEIGHT / 2);
	raytracer(env);
	ft_draw(env);
	return (0);
}
