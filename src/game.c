/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:37:08 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/22 16:35:39 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_destroy(t_game *game)
{
	ft_free_split(game->map.data);
	ft_free_split(game->map.buff);
	destroy_texs(*game);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_game *game) 
{
	(void)game;
	ft_printf("Pressed key: %d\n", keysym);
	return (0);
}

void	init_game(t_game *game, char *file)
{
	init_map(file, &(game->map));
	if (!game->map.valid)
		exit_handler("Map is invalid", NULL);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_handler("mlx_init() returned NULL", NULL);
	game->size.x = (game->map.size.x + game->map.size.y) * B_W;
	game->size.y = (game->map.size.x + game->map.size.y + 4) * B_H + 32;
	game->win = mlx_new_window(game->mlx, game->size.x, game->size.y, "so_long");
	game->img = mlx_new_image(game->mlx, game->size.x, game->size.y);
	game->data = mlx_get_data_addr(game->img, &(game->bpp),
				&(game->line), &(game->endian));
	if (!game->win || !game->img)
		free(game->mlx);
	if (!game->win || !game->img)
		exit_handler("Couldn't create window", NULL);
	init_texs(game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, &on_keypress, game);
	mlx_hook(game->win, DestroyNotify, StructureNotifyMask, &on_destroy, game);
	draw_game(*game);
	mlx_loop(game->mlx);
}
