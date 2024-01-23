/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 00:17:07 by larz              #+#    #+#             */
/*   Updated: 2024/01/23 19:01:58 by jde-meo          ###   ########.fr       */
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
	float	t;
	int		i;

	l = 0.f;
	i = 0;
	while (g.lights && g.lights[i].x >= 0)
	{
		p = gsp(g, (t_vec2){g.lights[i].x, g.lights[i].y});
		//l = maxf(l, LIGHT_CONST / dist(p.x, p.y, x, y));
		//l = maxf(l, maxf(0.f, LIGHT_CONST - dist(p.x, p.y, x, y)) / LIGHT_CONST);
		//l += maxf(0.f, LIGHT_CONST - dist(p.x, p.y, x, y)) / LIGHT_CONST;
		t = LIGHT_CONST / dist(p.x, p.y, x, y);
		if (t < .5f)
			l += 4.f * t * t * t;
		else
			l += 1.f - powf(-2.f * t + 2.f, 3.f) / 2.f;
		i++;
	}
	if (l > 1.f)
		return (1.f);
	return (l);
}

float	add_dithering(float l, int x, int y)
{
	if (l < .15f)
		return (0.f);
	if (l < 0.25f && (x % 4 != 0 || y % 4 != 0))
		return (0.f);
	if (l < 0.25f)
		return (1.f);
	if (l < 0.5f && (x % 2 != 0 || y % 2 != 0))
		return (0.f);
	if (l < 0.5f)
		return (1.f);
	if (l < 0.75f && ((x % 2 == 1 && y % 2 == 1)
		|| (x % 2 == 0 && y % 2 == 0)))
		return (0.f);
	if (l < 0.75f)
		return (1.f);
	if (l < 0.975f && ((x % 3 == 1 && y % 3 == 1)
		|| (x % 3 == 0 && y % 3 == 0)))
		return (0.f);
	return (1.f);
}
