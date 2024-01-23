/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:10:52 by jde-meo           #+#    #+#             */
/*   Updated: 2024/01/23 18:20:11 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	rotate(t_tex **tex)
{
	t_tex	*t;
	t_tex	*tmp;

	if (!(*tex))
		return ;
	t = *tex;
	while (t->next)
	{
		tmp = t;
		t = t->next;
	}
	if (t == *tex)
		return ;
	tmp->next = NULL;
	t->next = *tex;
	*tex = t;
}

void	rotate_textures(t_game *g)
{
	rotate(&g->set.wall);
	rotate(&g->set.player);
	rotate(&g->set.collec);
	rotate(&g->set.ennemy);
}

void	open_end(t_game *g)
{
	rotate(&g->set.end);
}
