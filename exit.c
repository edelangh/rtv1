/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:10:50 by khansman          #+#    #+#             */
/*   Updated: 2016/07/16 15:10:53 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_exit(int error)
{
	if (error == 0)
		exit(0);
	else if (error == 1)
		ft_putstr(ERR01);
	else if (error == 2)
		ft_putstr(ERR02);
	else if (error == 3)
		ft_putstr(ERR03);
	else if (error == 4)
		ft_putstr(ERR04);
	else if (error == 5)
		ft_putstr(ERR05);
	else if (error == 6)
		ft_putstr(ERR06);
	else if (error == 7)
		ft_putstr(ERR07);
	else if (error == 8)
		ft_putstr(ERR08);
	exit(0);
}

int		ft_exit_prog(t_env *env)
{
	(void)env;
	exit(0);
}
