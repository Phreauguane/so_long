/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:34:36 by jde-meo           #+#    #+#             */
/*   Updated: 2023/11/22 16:35:32 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_tex(t_tex	*tex, t_game game)
{
	if (tex == NULL)
		return ;
	free_tex(tex->next, game);
	mlx_destroy_image(game.mlx, tex->img);
	free(tex);
}

void	destroy_texs(t_game game)
{
	free_tex(game.set.floor, game);
	free_tex(game.set.wall, game);
	/*		ADD ALL TEXTURES		*/
}

t_tex	*create_tex(t_game game, char *file)
{
	t_tex	*tex;

	tex = malloc(sizeof(t_tex));
	tex->next = NULL;
	tex->file = file;
	tex->img = mlx_xpm_file_to_image(game.mlx, file, &(tex->size.x), &(tex->size.y));
	if (tex->img == NULL)
		exit_handler("Couldn't load texture from: ", file);
	tex->data = mlx_get_data_addr(tex->img, &(tex->bpp),
			   &(tex->line), &(tex->endian));
	ft_printf("Loaded texture at [%s]. size : %dx%d. BPP : %d\n", 
			tex->file, tex->size.x, tex->size.y, tex->bpp);
	return (tex);
}

void	add_tex(t_game game, t_tex **tex, char *file)
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
	game->set.floor = create_tex(*game, FLOOR_XPM);
	game->set.wall = create_tex(*game, WALL_XPM);
	/*		ADD ALL TEXTURES		*/
}
