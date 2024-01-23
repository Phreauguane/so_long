/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:37:08 by jde-meo           #+#    #+#             */
/*   Updated: 2024/01/23 18:45:30 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_destroy(t_game *game)
{
	ft_free_split(game->map.data);
	ft_free_split(game->map.buff);
	destroy_texs(*game);
	free_mobs(game->mobs);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_game *game) 
{
	move_player(game, keysym);
	return (0);
}

void	display_info(t_game g)
{
	char	*s;
	char	*num1;
	char	*num2;

	num1 = ft_itoa(g.player.collected);
	num2 = ft_itoa(g.player.moves - 1);
	s = str_adds(NULL, "Moves: ", 7);
	s = str_adds(s, num2, ft_strlen(num2));
	mlx_string_put(g.mlx, g.win, 10, 10, trgb(255, 255, 255, 255), s);
	free(s);
	s = str_adds(NULL, "Collected: ", 12);
	s = str_adds(s, num1, ft_strlen(num1));
	free(num1);
	free(num2);
	mlx_string_put(g.mlx, g.win, 10, 20, trgb(255, 255, 255, 255), s);
	free(s);
}

int	loop(t_game *game)
{
	static int	frame;

	frame++;
	if (!(frame % (ANIM_DELAY / 2)))
		rotate_textures(game);
	if (!(frame % ANIM_DELAY))
		move_mobs(game);
	draw_game(*game);
	display_info(*game);
	return (0);
}

void	init_game(t_game *game, char *file)
{
	init_map(file, &(game->map));
	if (!game->map.valid)
		exit_handler("Map is invalid", NULL);
	init_plr(game);
	game->mobs = init_mobs(game->map);
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_handler("mlx_init() returned NULL", NULL);
	game->size.x = game->map.size.x * XPX + game->map.size.y * YPX;
	game->size.y = game->map.size.x * XPY + game->map.size.y * YPY + B_H * 2;
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
	mlx_loop_hook (game->mlx, &loop, game);
	update_lights(game);
	draw_game(*game);
	mlx_loop(game->mlx);
}
