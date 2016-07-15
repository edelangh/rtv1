#include "libft.h"
#include <stdlib.h>

int		ft_ahextocolour(char *ahex)
{
	char	*str;
	char	*tmp;
	int		c;
	int		res;

	str = ft_strdup(ahex);
	str[2] = '\0';
	tmp = ft_convert_base(str, "0123456789ABCDEF", "0123456789");
	c = ft_atoi(tmp);
	res = c << 16;
	free(str);
	free(tmp);
	str = ft_strdup(ahex + 2);
	str[2] = '\0';
	tmp = ft_convert_base(str, "0123456789ABCDEF", "0123456789");
	c = ft_atoi(tmp);
	res |= c << 8;
	free(str);
	free(tmp);
	str = ft_strdup(ahex + 4);
	tmp = ft_convert_base(str, "0123456789ABCDEF", "0123456789");
	res |= ft_atoi(tmp);
	free(str);
	free(tmp);
	return (res);
}
