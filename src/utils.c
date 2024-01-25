/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:43:58 by jde-meo           #+#    #+#             */
/*   Updated: 2024/01/25 23:58:41 by jde-meo          ###   ########.fr       */
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

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

float	dist(int x1, int y1, int x2, int y2)
{
	return (sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
