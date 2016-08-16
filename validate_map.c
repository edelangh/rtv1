/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 12:31:58 by khansman          #+#    #+#             */
/*   Updated: 2016/08/15 12:31:59 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		count_tabs(char **tab)
{
	int		k;

	k = 0;
	if (!tab || !*tab || !**tab)
		return (-1);
	while (tab[k] != NULL)
		k++;
	return (k);
}

int		val_tab_count(char **tab)
{
	int		k;

	k = count_tabs(tab);
	if (k != 14)
	{
		if (tab && *tab && !ft_strcmp(*tab, "Spot") && k == 8)
			return (1);
		else if (tab && *tab && !ft_strcmp(*tab, "Camera") && k == 9)
			return (1);
		else
			return (0);
	}
	return (1);
}

int		remove_tabs(char **str)
{
	char	*s;

	s = *str;
	if (!s || !*s)
		return (0);
	while (*s)
	{
		if (*s == '\t')
			*s = ' ';
		s++;
	}
	return (1);
}

int		valid_object(char *str)
{
	if (!ft_strcmp(str, "Sphere") || !ft_strcmp(str, "Plane"))
		return (1);
	if (!ft_strcmp(str, "Triangle") || !ft_strcmp(str, "Cone"))
		return (1);
	if (!ft_strcmp(str, "Cyliner") || !ft_strcmp(str, "Spot"))
		return (1);
	return (0);
}
