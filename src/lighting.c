/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larz <larz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:17:07 by larz              #+#    #+#             */
/*   Updated: 2024/01/23 00:46:45 by larz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	count_lights(t_game g)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = -1;
	while (++y < g.map.size.y)
	{
		x = -1;
		while (++x < g.map.size.x)
		{
			if (ft_strchr("CE", g.map.data[y][x])
			|| (x == g.player.pos.x && y == g.player.pos.y))
				i++;
		}
	}
	return (i);
}

void    update_lights(t_game *g)
{
	int	c;
    int	x;
	int	y;

	c = count_lights(*g);
	if (g->lights)
		free(g->lights);
	g->lights = (t_vec2 *)malloc(sizeof(t_vec2) * (c + 1));
	g->lights[c--] = (t_vec2){-1, -1};
	y = -1;
	while (++y < g->map.size.y && c >= 0)
	{
		x = -1;
		while (++x < g->map.size.x && c >= 0)
		{
			if (ft_strchr("CE", g->map.data[y][x])
			|| (x == g->player.pos.x && y == g->player.pos.y))
				g->lights[c--] = (t_vec2){x, y};
		}
	}
}

float	get_lighting(t_game g, int x, int y)
{
	t_vec2	p;
	float	l;
	int		i;

	l = 0.f;
	i = 0;
	while (g.lights && g.lights[i].x >= 0)
	{
		p = get_screen_pos(g, (t_vec2){g.lights[i].x, g.lights[i].y});
		l = maxf(l, LIGHT_CONST / dist(p.x, p.y, x, y));
		i++;
	}
	return (l);
}
