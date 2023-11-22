/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:22:01 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/22 16:32:07 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_tex_to_screen(t_game g, t_tex *t, int x, int y)
{
	char	*p;
	int		i;
	int		j;

	i = 0;
	while (i < t->size.x)
	{
		j = 0;
		while (j < t->size.y)
		{
			p = get_pix(*t, i, j);
			if (!pixel_cmp(p, "\0\0\0\0"))
				set_pixel(g, x + i, y + j, p);
			j++;
		}
		i++;
	}
}

void	clear_screen(t_game g)
{
	ft_memset(g.data, 0, g.size.x * g.size.y * (g.bpp / 8));
}

void	display_map(t_game g)
{
	int	x;
	int	y;
	int i;
	int j;

	y = 0;
	while (y < g.map.size.y)
	{
		x = 0;
		while (x < g.map.size.x)
		{
			i = (g.map.size.x - x - 1) * XPX + y * YPX;
			j = (y + 4) * YPY + x * XPY;
			put_tex_to_screen(g, g.set.floor, i, j);
			x++;
		}
		y++;
	}
}

void	display_up_layer(t_game g)
{
	int	x;
	int	y;
	int i;
	int j;

	y = 0;
	while (y < g.map.size.y)
	{
		x = 0;
		while (x < g.map.size.x)
		{
			i = (g.map.size.x - x - 1) * XPX + y * YPX;
			j = (y + 2) * YPY + x * XPY;
			if (g.map.data[y][x] == '1')
				put_tex_to_screen(g, g.set.wall, i, j);
			x++;
		}
		y++;
	}
}

void	draw_game(t_game game)
{
	display_map(game);
	display_up_layer(game);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
}
