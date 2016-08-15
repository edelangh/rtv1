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
