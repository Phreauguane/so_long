/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:37:08 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/20 20:48:59 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int on_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int on_keypress(int keysym, t_game *game)
{
	(void)game;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_handler("mlx_init() returned NULL", NULL);
	game->win = mlx_new_window(game->mlx, 600, 400, "sooooooooo_looooooooooong");
	if (!game->win)
		free(game->mlx);
	if (!game->win)
		exit_handler("mlx_new_window() returned NULL", NULL);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &on_keypress, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &on_destroy, game);
	mlx_loop(game->mlx);
}
