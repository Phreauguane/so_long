/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:38:47 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/23 14:57:26 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_plr(t_game *g)
{
	g->player.pos = get_pos(g->map, 'P');
	g->player.collected = 0;
	g->player.last_move = 's';
	g->player.moves = 0;
}

void	move_to(t_game *g, int x, int y)
{
	g->player.pos.x = x;
	g->player.pos.y = y;
	g->player.moves++;
}

void	move_event(t_game *g, int x, int y)
{
	if (g->map.data[y][x] != '1')
		move_to(g, x, y);
	if (g->map.data[y][x] == 'C')
	{
		g->map.data[y][x] = 0;
		(g->player.collected)++;
	}
	if (g->map.data[y][x] == 'E'
		&& g->map.to_collect == g->player.collected)
		on_destroy(g);
}

void	move_player(t_game *g, int key)
{
	int		x;
	int		y;
	int		tx;
	int		ty;

	x = g->player.pos.x;
	y = g->player.pos.y;
	tx = x;
	ty = y;
	g->player.last_move = key;
	if (key == 'w')
		tx--;
	if (key == 'a')
		ty--;
	if (key == 's')
		tx++;
	if (key == 'd')
		ty++;
	move_event(g, tx, ty);
}
