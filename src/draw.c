/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:22:01 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/23 13:58:13 by jde-meo          ###   ########.fr       */
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
			if (!pixel_cmp(p, "\0\0\0\0")
				&& x + i < g.size.x && y + j < g.size.y
				&& x + 1 > 0 && y + j > 0)
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
			j = y * YPY + x * XPY + ZPY;
			put_tex_to_screen(g, g.set.wall, i, j);
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
			j = y * YPY + x * XPY;
			if (g.map.data[y][x] == '1')
				put_tex_to_screen(g, g.set.wall, i, j);
			if (g.map.data[y][x] == 'C')
				put_tex_to_screen(g, g.set.collec, i, j);
			if (g.map.data[y][x] == 'E')
				put_tex_to_screen(g, g.set.end, i, j);
			if (x == g.player.pos.x && y == g.player.pos.y)
				put_tex_to_screen(g, g.set.player, i, j);
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
