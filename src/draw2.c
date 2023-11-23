/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:05:19 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/23 13:20:35 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_pixel(t_game g, int x, int y, char *val)
{
	//ft_printf("Changin pixel at %d %d\n", x, y);
	g.data[y * g.line + x * (g.bpp / 8) + 0] = val[0];
	g.data[y * g.line + x * (g.bpp / 8) + 1] = val[1];
	g.data[y * g.line + x * (g.bpp / 8) + 2] = val[2];
}

char	*get_pix(t_tex t, int x, int y)
{
	return (&(t.data[y * t.line + x * (t.bpp / 8)]));
}

char	*get_pix2(t_game g, int x, int y)
{
	return (&(g.data[y * g.line + x * (g.bpp / 8)]));
}

int	pixel_cmp(char *p1, char *p2)
{
	return (p1[0] == p2[0]
			&& p1[1] == p2[1]
			&& p1[2] == p2[2]);
}
