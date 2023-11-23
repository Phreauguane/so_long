/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 19:21:35 by jde-meo            #+#    #+#             */
/*   Updated: 2023/11/22 16:23:32 by jde-meo          ###   ########.fr       */
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

/*============= MACROS =============*/
# define WALL_XPM "textures/wall.xpm"
# define PLAYER_XPM "textures/player.xpm"
# define COLLEC_XPM "textures/collect.xpm"
# define END_XPM "textures/end.xpm"
# define END2_XPM "textures/end2.xpm"
# define TEX_W 64
# define TEX_H 64
# define B_H 50
# define B_W 64
# define XPX 20
# define XPY 20
# define YPX 44
# define YPY 14
# define ZPX 0
# define ZPY 30
# define FRAME_DELAY 1000
# define ANIM_DELAY 5
/*=================================*/

typedef struct s_vec2
{
	int	x;
	int	y;
}	t_vec2;

typedef struct s_tex
{
	char			*file;
	char			*data;
	void			*img;
	int				bpp;
	int				line;
	int				endian;
	t_vec2			size;
	struct s_tex	*next;
}	t_tex;

typedef struct s_tileset
{
	t_tex	*player;
	t_tex	*floor;
	t_tex	*wall;
	t_tex	*collec;
	t_tex	*end;
}	t_tileset;

typedef struct s_map
{
	t_vec2	size;
	char	**data;
	char	**buff;
	int		to_collect;
	char	valid;
}	t_map;

typedef struct s_plr
{
	t_vec2	pos;
	int		collected;
	int		moves;
	int		last_move;
}	t_plr;

typedef struct s_mob
{
	t_vec2			pos;
	t_vec2			move;
	struct s_mob	*next;
}	t_mob;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			line;
	int			endian;
	t_vec2		size;
	t_map		map;
	t_tileset	set;
	t_plr		player;
	t_mob		*mobs;
}	t_game;

/*	GAME.C			*/
void	init_game(t_game *game, char *file);
int		on_destroy(t_game *game);

/*	MAP.C			*/
void	init_map(char *file, t_map *map);
void	print_map(t_map map);

/*	VERIF_MAP.C		*/
t_vec2	get_pos(t_map map, char c);
void	verif_map(t_map *map);
void	reset_buff(t_map map);

/*	DRAW.C			*/
void	draw_game(t_game game);

/*	DRAW2.C			*/
void	set_pixel(t_game g, int x, int y, char *val);
char	*get_pix(t_tex t, int x, int y);
char	*get_pix2(t_game g, int x, int y);
int		pixel_cmp(char *p1, char *p2);
void	clear_screen(t_game g);

/*	TEXTURES.C		*/
void	destroy_texs(t_game game);
void	init_texs(t_game *game);

/*	UTILS.c			*/
int		min(int x, int y);
int		max(int x, int y);
void	exit_handler(char *msg, char *info);
int		trgb(int t, int r, int g, int b);

/*	PLAYER.C		*/
void	move_player(t_game *g, int key);
void	init_plr(t_game *g);

/*	ANIM.C			*/
void	rotate_textures(t_game *g);

/*	MOBS.c			*/
t_mob	*init_mobs(t_map map);
void	free_mobs(t_mob *mobs);

/*	MOVE_MOBS.c		*/
void	move_mobs(t_game *g);

#endif