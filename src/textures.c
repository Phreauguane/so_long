/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:34:36 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/11 12:46:49 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_tex(t_tex	*tex, t_game game)
{
	if (tex == NULL)
		return ;
	free_tex(tex->next, game);
	if (tex->img)
		mlx_destroy_image(game.mlx, tex->img);
	if (tex->img)
		tex->img = NULL;
	free2(tex);
}

void	destroy_texs(t_game game)
{
	free_tex(game.set.floor, game);
	free_tex(game.set.wall, game);
	free_tex(game.set.player, game);
	free_tex(game.set.collec, game);
	free_tex(game.set.end, game);
	free_tex(game.set.ennemy, game);
}

t_tex	*create_tex(t_game *game, char *file)
{
	t_tex	*tex;

	tex = malloc(sizeof(t_tex));
	ft_bzero(tex, sizeof(t_tex));
	tex->file = file;
	tex->img = mlx_xpm_file_to_image(game->mlx, file,
			&(tex->size.x), &(tex->size.y));
	if (tex->img == NULL)
		exit_handler("Couldn't load texture from: ", file, game);
	tex->data = mlx_get_data_addr(tex->img, &(tex->bpp),
			&(tex->line), &(tex->endian));
	return (tex);
}

void	add_tex(t_game *game, t_tex **tex, char *file)
{
	t_tex	*t;

	t = *tex;
	while (t && t->next)
		t = t->next;
	if (t)
		t->next = create_tex(game, file);
	else
		*tex = create_tex(game, file);
}

void	init_texs(t_game *game)
{
	game->set.floor = create_tex(game, FLOOR_XPM);
	game->set.wall = create_tex(game, WALL_XPM);
	game->set.player = create_tex(game, PLAYER_XPM);
	add_tex(game, &(game->set.player), PLAYER2_XPM);
	add_tex(game, &(game->set.player), PLAYER3_XPM);
	add_tex(game, &(game->set.player), PLAYER4_XPM);
	add_tex(game, &(game->set.player), PLAYER5_XPM);
	add_tex(game, &(game->set.player), PLAYER6_XPM);
	add_tex(game, &(game->set.player), PLAYER7_XPM);
	add_tex(game, &(game->set.player), PLAYER8_XPM);
	add_tex(game, &(game->set.player), PLAYER9_XPM);
	game->set.collec = create_tex(game, COLLEC_XPM);
	add_tex(game, &(game->set.collec), COLLEC2_XPM);
	add_tex(game, &(game->set.collec), COLLEC3_XPM);
	add_tex(game, &(game->set.collec), COLLEC4_XPM);
	add_tex(game, &(game->set.collec), COLLEC5_XPM);
	add_tex(game, &(game->set.collec), COLLEC6_XPM);
	game->set.end = create_tex(game, END_XPM);
	add_tex(game, &(game->set.end), END2_XPM);
	game->set.ennemy = create_tex(game, ENNEMY_XPM);
	add_tex(game, &(game->set.ennemy), ENNEMY2_XPM);
	update_lights(game);
}
