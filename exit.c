#include "rtv1.h"

void	ft_exit(int error)
{
	if (error == 0)
		exit(0);
	else if (error == 1)
		ft_putstr("Error :Not enouth info for spot");
	else if (error == 2)
		ft_putstr("Error :Too many spots !\n");
	else if (error == 3)
		ft_putstr("{red}Error: invalide elem in file{eoc}\n");
	else if (error == 4)
		ft_putstr("{red}Error: can't open file\n{eoc}");
	else if (error == 5)
		ft_putstr("{red}Error: can't read sizes of file\n{eoc}");
	else if (error == 6)
		ft_putstr("{red}Error: too many objs\n{eoc}");
	else if (error == 7)
		ft_putstr("Error: Too few arguments\n");
	else if (error == 8)
		ft_putstr("Error: mlx init failed\n");
	exit(0);
}
