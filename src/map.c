/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:31:41 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/22 11:45:48 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	count_lines(char *file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		if (line)
			free(line);
		else
			break;
	}
	close(fd);
	return (i);
}

t_map	init_map(char *file)
{
	t_map	map;
	int		y;
	int		x;
	int 	fd;
	
	y = 0;
	x = 0;
	map.size.y = count_lines(file);
	map.data = malloc(sizeof(char *) * (map.size.y + 1));
	map.buff = malloc(sizeof(char *) * (map.size.y + 1));
	fd = open(file, O_RDONLY);
	while (y <= map.size.y)
	{
		map.data[y] = get_next_line(fd);
		if (map.data[y])
			map.buff[y] = ft_strdup(map.data[y]);
		else
			map.buff[y] = NULL;
		if (map.data[y] && ft_strlen(map.data[y]) > x)
			x = ft_strlen(map.data[y]);
		y++;
	}
	map.size.x = x;
	verif_map(&map);
	return (map);
}

void	print_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.size.y)
		ft_printf("%s", map.data[i++]);
}