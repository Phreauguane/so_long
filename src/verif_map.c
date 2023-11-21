/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:12:25 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/21 11:14:59 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inclues/so_long.h"


t_vec2	get_pos(char **tab, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				return ((t_vec2){j, i});
			j++;
		}
		i++;
	}
	return ((t_vec2){-1, -1});
}

int	count_char(char **tab, char c)
{
	int	out;
	int	i;
	int	j;

	i = 0;
	j = 0;
	out = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (tab[i][j] == c)
				out++;
			j++;
		}
		i++;
	}
	return (out);
}

int	count(int x, int y, t_map *map, char block)
{
	int	r;
	int	l;
	int	u;
	int	d;
	
	if (x < 0 || x >= map->size.x
		|| y < 0 || y >= map->size.y)
		return (0);
	if (map->data[y][x] == '1' || map->buff[y][x] == '1')
		return (0);
	map->buff[y][x] = '1';
	r = count(x + 1, y, map, block);
	l = count(x - 1, y, map, block);
	u = count(x, y - 1, map, block);
	d = count(x, y + 1, map, block);
	if (map->data[y][x] == block)
		return (1 + r + l + u + d);
	return (r + l + u + d);
}

void	verif_map(t_map *map)
{
	int		collectibles;
	int		end;
	int		spawn;
	t_vec2	spos;

	if (map->size.x < 1 || map->size.y < 1)
		exit_handler("Invalid map", NULL);
	collectibles = count_char(map->data, 'C');
	spawn = count_char(map->data, 'P');
	end = count_char(map->data, 'E');
	if (collectibles == 0 || spawn != 1 || end != 1)
		map->valid = 0;
	spos = get_pos(map->data, 'P');
	if (spos.x < 0)
		return ;
	if (collectibles != count(spos.x, spos.y, map, 'C'))
		map->valid = 0;
	if (end != count(spos.x, spos.y, map, 'E'))
		map->valid = 0;
}
