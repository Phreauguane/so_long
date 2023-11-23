/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_mob.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:48:36 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/23 17:11:42 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	min_positive(int r[5])
{
	if (r[0] >= 0 && r[0] <= r[1] && r[0] <= r[2] && r[0] <= r[3] && r[0] <= r[4])
		return (r[0]);
	if (r[1] >= 0 && r[1] <= r[0] && r[1] <= r[2] && r[1] <= r[3] && r[1] <= r[4])
		return (r[1]);
	if (r[2] >= 0 && r[2] <= r[0] && r[2] <= r[1] && r[2] <= r[3] && r[2] <= r[4])
		return (r[2]);
	if (r[3] >= 0 && r[3] <= r[0] && r[3] <= r[1] && r[3] <= r[2] && r[3] <= r[4])
		return (r[3]);
	if (r[4] >= 0 && r[4] <= r[0] && r[4] <= r[1] && r[4] <= r[2] && r[4] <= r[3])
		return (r[4]);
	return (-2);
}

int	abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	get_dist(t_vec2 p, t_vec2 d, t_map m)
{
	if (p.x < 0 || p.x >= m.size.x ||
		p.y < 0 || p.y >= m.size.y)
		return (-1);
	if (m.data[p.y][p.x] == '1')
		return (-1);
	if (p.x == d.x && p.y == d.y)
		return (0);
	return (abs(d.x - p.x) + abs(d.y - p.y));
}

t_vec2	find_move(t_vec2 p, t_vec2 d, t_map m)
{
	int		r[5];
	
	r[0] = get_dist((t_vec2){p.x + 1, p.y}, d, m);
	r[1] = get_dist((t_vec2){p.x - 1, p.y}, d, m);
	r[2] = get_dist((t_vec2){p.x, p.y + 1}, d, m);
	r[3] = get_dist((t_vec2){p.x, p.y - 1}, d, m);
	r[4] = get_dist(p, d, m);
	if (r[4] == min_positive(r))
		return ((t_vec2){0, 0});
	if (r[0] == min_positive(r))
		return ((t_vec2){1, 0});
	if (r[1] == min_positive(r))
		return ((t_vec2){-1, 0});
	if (r[2] == min_positive(r))
		return ((t_vec2){0, 1});
	if (r[3] == min_positive(r))
		return ((t_vec2){0, -1});
	return (p);
}

void	move_mobs(t_game *g)
{
	t_mob	*m;

	m = g->mobs;
	while (m)
	{
		m->move = find_move(m->pos, g->player.pos, g->map);
		m->pos.x += m->move.x;
		m->pos.y += m->move.y;
		m = m->next;
	}
}
