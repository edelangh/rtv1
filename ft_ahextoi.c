#include "libft.h"
#include <stdlib.h>

int		ft_ahextocolour(char *ahex)
{
	char	*str;
	char	*temp;
	int		c;
	int		res;

	str = ft_strdup(ahex);
	str[2] = '\0';
	temp = ft_convert_base(str, "0123456789ABCDEF", "0123456789");
	c = ft_atoi(temp);
	res = c << 16;
	free(str);
	free(temp);
	str = ft_strdup(ahex + 2);
	str[2] = '\0';
	temp = ft_convert_base(str, "0123456789ABCDEF", "0123456789");
	c = ft_atoi(temp);
	res |= c << 8;
	free(str);
	free(temp);
	str = ft_strdup(ahex + 4);
	temp = ft_convert_base(str, "0123456789ABCDEF", "0123456789");
	res |= ft_atoi(temp);
	free(str);
	free(temp);
	return (res);
}
