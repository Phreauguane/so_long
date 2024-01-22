/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larz <larz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:17:33 by larz              #+#    #+#             */
/*   Updated: 2024/01/23 00:48:08 by larz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_vec2  get_screen_pos(t_game g, t_vec2 pos)
{
    t_vec2  out;

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
