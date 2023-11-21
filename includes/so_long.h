/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:21:35 by asimon            #+#    #+#             */
/*   Updated: 2023/11/21 11:13:00 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <fcntl.h>

typedef struct	s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct	s_map
{
	t_vec2	size;
	char	**data;
	char	**buff;
	char	valid;
}	t_map;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_vec2	size;
	t_map	map;
}	t_game;

/*	GAME.C			*/
void	init_game(t_game *game);

/*	MAP.C			*/
t_map	init_map(char *file);

/*	VERIF_MAP.C		*/
void	verif_map(t_map *map);

/*	UTILS.c			*/
int		min(int x, int y);
int		max(int x, int y);
void	exit_handler(char *msg, char *info);

#endif