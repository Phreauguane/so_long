/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:31:41 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/21 11:12:49 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_map	init_map(char *file)
{
	t_map	map;
	int		y;
	int		x;
	int 	fd;

	y = 0;
	x = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd))
		y++;
	map.data = malloc(sizeof(char *) * (y + 1));
	map.buff = malloc(sizeof(char *) * (y + 1));
	map.size.y = y;
	y = 0;
	while (y == 0 || map.data[y - 1] != NULL)
	{
		map.data[y] = get_next_line(fd);
		map.buff[y] = ft_strdup(map.data[y]);
		if (map.data[y] && ft_strlen(map.data[y]) > x)
			x = ft_strlen(map.data[y]);
		y++;
	}
	map.size.x = x;
	verif_map(&map);
	return (map);
}
