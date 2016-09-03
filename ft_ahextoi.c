/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ahextoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:11:00 by khansman          #+#    #+#             */
/*   Updated: 2016/07/16 15:11:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ft_ahextocolour(char *ahex)
{
	char	*str;
	char	*temp;
	int		c;
	int		res;

	str = ft_strdup(ahex);
	str[2] = '\0';
	temp = ft_convert_base(str, HEX_STR, DEC_STR);
	c = ft_atoi(temp);
	res = c << 16;
	free(str);
	free(temp);
	str = ft_strdup(ahex + 2);
	str[2] = '\0';
	temp = ft_convert_base(str, HEX_STR, DEC_STR);
	c = ft_atoi(temp);
	res |= c << 8;
	free(str);
	free(temp);
	str = ft_strdup(ahex + 4);
	temp = ft_convert_base(str, HEX_STR, DEC_STR);
	res |= ft_atoi(temp);
	free(str);
	free(temp);
	return (res);
}

size_t		ft_tablen(void **tab)
{
	size_t	len;

	len = 0;
	if (!tab)
		return (0);
	while (tab[len])
		++len;
	return (len);
}

double		ft_atof(const char *str)
{
	double	result;
	int		i;

	result = (double)ft_atoi(str);
	i = ft_len_untill(str, '.');
	if (i && str[i])
	{
		if (result >= 0 && str[0] != '-')
			result += ((double)ft_atoi(str + i + 1))
				/ ((ft_strlen(str + i + 1) * 10));
		else
			result -= ((double)ft_atoi(str + i + 1))
				/ ((ft_strlen(str + i + 1) * 10));
	}
	return (result);
}

size_t		ft_len_untill(const char *str, char c)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != c && str[len] != '\0')
		++len;
	return (len);
}

char		*ft_strrev(char *s)
{
	size_t	len;
	size_t	i;
	char	swap;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i != len / 2)
	{
		swap = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = swap;
		++i;
	}
	return (s);
}
