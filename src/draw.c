/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:22:01 by jde-meo           #+#    #+#             */
/*   Updated: 2024/01/25 23:41:08 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_tex_to_screen(t_game g, t_tex *t, int x, int y)
{
	char	*p;
	float	d;
	int		i;
	int		j;

	i = -1;
	d = (float)g.size.x * (float)g.size.y;
	while (g.lights && g.lights[++i].x >= 0)
		d = minf(d, dis2(x + 32, y + 32, gsp(g, g.lights[i])));
	if (d > 175.f)
		return ;
	i = -1;
	while (++i < t->size.x)
	{
		j = -1;
		while (++j < t->size.y)
		{
			p = get_pix(*t, i, j);
			if (!pixel_cmp(p, "\0\0\0\0")
				&& x + i < g.size.x && y + j < g.size.y
				&& x + 1 > 0 && y + j > 0)
				set_pixel(g, x + i, y + j, p);
		}
	}
}

void	display_map(t_game g)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	while (y < g.map.size.y)
	{
		x = 0;
		while (x < g.map.size.x)
		{
			i = (g.map.size.x - x - 1) * XPX + y * YPX;
			j = y * YPY + x * XPY + ZPY;
			put_tex_to_screen(g, g.set.floor, i, j);
			x++;
		}
		y++;
	}
}

void	put_to(t_game g, int x, int y)
{
	t_mob	*m;
	int		i;
	int		j;

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
	m = g.mobs;
	while (m)
	{
		if (x == m->pos.x && y == m->pos.y)
			put_tex_to_screen(g, g.set.ennemy, i, j);
		m = m->next;
	}
}

void	display_up_layer(t_game g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g.map.size.y)
	{
		x = 0;
		while (x < g.map.size.x)
		{
			put_to(g, x, y);
			x++;
		}
		y++;
	}
}

void	draw_game(t_game game)
{
	clear_screen(game);
	display_map(game);
	display_up_layer(game);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
}
