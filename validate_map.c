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
	if  (count_tabs(tab) != 14)
	{
		if (tab && *tab && !ft_strcmp(*tab, "Spot"))
			return (1);
		return (0);
	}
	return (1);
}

void	remove_tabs(char **str)
{
	char 	*s;

	s = *str;
	while (s && *s)
	{
		if (*s == '\t')
			*s = ' ';
		s++;
	}
}
