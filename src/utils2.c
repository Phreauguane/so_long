/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:17:33 by larz              #+#    #+#             */
/*   Updated: 2024/01/25 23:58:38 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_vec2	gsp(t_game g, t_vec2 pos)
{
	t_vec2	out;

	out.x = (g.map.size.x - pos.x - 1) * XPX + pos.y * YPX + 1.5f * XPX;
	out.y = pos.y * YPY + pos.x * XPY + ZPY + YPY;
	return (out);
}

float	maxf(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

float	minf(float x, float y)
{
	if (x < y)
		return (x);
	return (y);
}

float	dis2(int x1, int y1, t_vec2 p)
{
	return (sqrtf((p.x - x1) * (p.x - x1) + (p.y - y1) * (p.y - y1)));
}
