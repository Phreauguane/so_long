/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:39:43 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/12 12:09:26 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	verif_input(int ac, char **av)
{
	int	i;

	if (ac != 2 || !av[1])
		exit_handler("Wrong arguments", NULL, NULL);
	i = ft_strlen(av[1]);
	if (i < 4)
		exit_handler("Invalid file", NULL, NULL);
	if (av[1][i - 4] != '.' || av[1][i - 3] != 'b'
		|| av[1][i - 2] != 'e' || av[1][i - 1] != 'r')
		exit_handler("Invalid file", NULL, NULL);
}

int	main(int ac, char **av)
{
	t_game	game;

	verif_input(ac, av);
	ft_bzero(&game, sizeof(t_game));
	init_game(&game, av[1]);
	return (0);
}
