/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:52:55 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 06:45:35 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "so_long.h"
#include "settings.h"
#include "mlx.h"

bool	init_game_struct(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("init_game");
		return (true);
	}
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			GAME_TITLE);
	if (!game->win)
	{
		perror("init_game");
		clean_mlx(game->mlx);
		return (true);
	}
	game->displayed = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->displayed)
	{
		perror("init_game");
		clean_mlx(game->mlx);
		mlx_destroy_window(game->mlx, game->win);
		return (true);
	}
	return (false);
}

int	get_scale(int ac, char **av)
{
	int	scale;

	if (ac < 3)
		return (1);
	scale = ft_atoi(av[2]);
	if (scale > 0)
		return (scale);
	return (1);
}

void	init_game_values(int ac, char **av, t_game *game)
{
	game->scale = get_scale(ac, av);
	game->action_count = 0;
}

bool	init_game(int ac, char **av, t_game *game)
{
	if (init_game_struct(game))
		return (true);
	if (init_sprites(game))
	{
		clean_game_struct(game);
		return (true);
	}
	init_game_values(ac, av, game);
	return (false);
}
