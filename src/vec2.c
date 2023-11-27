/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:09:05 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/27 15:15:37 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_vec2	addv(t_vec2 v1, t_vec2 v2)
{
	return ((t_vec2){v1.x + v2.x, v1.y + v2.y});
}

void	addv2(t_vec2 *v1, t_vec2 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
}

int	cmpv(t_vec2 v1, t_vec2 v2)
{
	return (v1.x == v2.x && v1.y == v2.y);
}
