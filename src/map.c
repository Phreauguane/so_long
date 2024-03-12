/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larz <larz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:31:41 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/12 14:14:42 by larz             ###   ########.fr       */
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
			break ;
	}
	close(fd);
	return (i);
}

void	verif_closed(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (x < map->size.x)
	{
		if (map->data[0][x++] != '1')
			map->valid = 0;
	}
	while (y < map->size.y)
	{
		if (map->data[y++][map->size.x - 1] != '1')
			map->valid = 0;
	}
	while (--x >= 0)
	{
		if (map->data[map->size.y - 1][x] != '1')
			map->valid = 0;
	}
	while (--y >= 0)
	{
		if (map->data[y][0] != '1')
			map->valid = 0;
	}
}

void	verif_chars(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->valid && y < map->size.y)
	{
		x = 0;
		while (map->valid && x < map->size.x)
		{
			if (strchr(MAP_CHARS, map->data[y][x]) == NULL)
				map->valid = 0;
			x++;
		}
		y++;
	}
}

int	verif_fd(int fd, t_game *g)
{
	if (fd < 1)
		exit_handler("Invalid file", NULL, g);
	return (fd);
}

void	init_map(char *file, t_game *g, t_map *map)
{
	int		y;
	int		x;
	int		fd;

	y = 0;
	x = 0;
	fd = verif_fd(open(file, O_RDONLY), g);
	map->size.y = count_lines(file);
	map->data = malloc(sizeof(char *) * (map->size.y + 1));
	map->buff = malloc(sizeof(char *) * (map->size.y + 1));
	while (y <= map->size.y)
	{
		map->data[y] = get_next_line(fd);
		if (map->data[y])
			map->buff[y] = ft_strdup(map->data[y]);
		else
			map->buff[y] = NULL;
		if (map->data[y] && ft_strlen(map->data[y]) > x)
			x = ft_strlen(map->data[y]);
		y++;
	}
	map->size.x = x - 1;
	verif_map(map);
	verif_closed(map);
	verif_chars(map);
}
