/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:43:58 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/20 20:16:52 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	min(int x, int y)
{
	if (x < y)
		return (x);
	return (y);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}

void	exit_handler(char *msg, char *info)
{
	ft_putstr_fd("Error: ", 2);
	if (info)
	{
		ft_putstr_fd(msg, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(info, 2);
	}
	else
		ft_putendl_fd(msg, 2);
	exit(-1);
}