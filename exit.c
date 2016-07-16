#include "rtv1.h"

void	ft_exit(int error)
{
	if (error == 0)
		exit(0);
	else if (error == 1)
		ft_putstr("\e[31mError :Not enouth info for spot\e[0m");
	else if (error == 2)
		ft_putstr("\e[31mError :Too many spots !\n\e[0m");
	else if (error == 3)
		ft_putstr("\e[31mError: invalide elem in file\n\e[0m");
	else if (error == 4)
		ft_putstr("\e[31mError: can't open file\n\e[0m");
	else if (error == 5)
		ft_putstr("\e[31mError: can't read sizes of file\n\e[0m");
	else if (error == 6)
		ft_putstr("\e[31mError: too many objs\n\e[0m");
	else if (error == 7)
		ft_putstr("\e[31mError: Too few arguments\n\e[0m");
	else if (error == 8)
		ft_putstr("\e[31mError: mlx init failed\n\e[0m");
	exit(0);
}
