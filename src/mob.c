/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:32:33 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/23 16:47:54 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_mobs(t_mob *mobs)
{
	if (mobs == NULL)
		return ;
	free_mobs(mobs->next);
	free(mobs);
}

t_mob	*create_mob(int x, int y)
{
	t_mob	*mob;

	mob = malloc(sizeof(t_mob));
	mob->next = NULL;
	mob->pos = (t_vec2){x, y};
	return (mob);
}

void	add_mob(t_mob **mobs, int x, int y)
{
	t_mob	*m;

	m = *mobs;
	while (m && m->next)
		m = m->next;
	if (m)
		m->next = create_mob(x, y);
	else
		*mobs = create_mob(x, y);
}

t_mob	*init_mobs(t_map map)
{
	t_mob	*mobs;
	int		x;
	int		y;

	y = 0;
	mobs = NULL;
	while (y < map.size.y)
	{
		x = 0;
		while (x < map.size.x)
		{
			if (map.data[y][x] == 'M')
				add_mob(&mobs, x, y);
			x++;
		}
		y++;
	}
	return (mobs);
}
