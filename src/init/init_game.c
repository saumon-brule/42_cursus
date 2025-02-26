/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saumon <saumon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:56:46 by ebini             #+#    #+#             */
/*   Updated: 2025/02/25 20:02:07 by saumon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>

#include "libft.h"
#include "so_long.h"
#include "settings.h"
#include "sources.h"

bool	init_sprites(t_game *game)
{
	int	a;

	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
		return (true);
	game->sprites->air = mlx_xpm_file_to_image(game->mlx, TEXTURE_AIR, &a, &a);
	game->sprites->wall = mlx_xpm_file_to_image(game->mlx, TEXTURE_WALL,
			&a, &a);
	game->sprites->coin = mlx_xpm_file_to_image(game->mlx, TEXTURE_COIN,
			&a, &a);
	if (!game->sprites->air || !game->sprites->wall
		|| !game->sprites->coin)
	{
		clean_sprites(game);
		perror("init_sprites");
		return (true);
	}
	return (false);
}

bool	init_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		perror("init_mlx");
		return (true);
	}
	game->displayed = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!game->displayed)
	{
		perror("init_mlx");
		clean_mlx(game->mlx);
		return (true);
	}
	game->win = mlx_new_window(game->mlx,
			WINDOW_WIDTH, WINDOW_HEIGHT, GAME_TITLE);
	if (!game->win)
	{
		perror("init_mlx");
		clean_mlx(game->mlx);
		mlx_destroy_image(game->mlx, game->displayed);
		return (true);
	}
	return (false);
}

bool	init_player(t_game *game)
{
	game->player = malloc(sizeof(t_player));
	if (!game->player)
	{
		perror("init_player");
		return (true);
	}
	game->player->sprite = mlx_xpm_file_to_image(game->mlx, TEXTURE_PLAYER,
			&(game->player->width), &(game->player->height));
	if (!game->player->sprite)
	{
		free(game->player);
		perror("init_player");
		return (true);
	}
	game->player->speed.x = 0;
	game->player->speed.y = 0;
	game->player->acc.x = 0;
	// game->player->acc.y = 10;
	game->player->acc.y = 0;
	game->player->is_walled = false;
	game->player->is_grounded = true;
	game->player->pos.x = 50;
	game->player->pos.y = 200;
	return (false);
}

int	get_scale(int ac, char **av)
{
	// int	scale;

	if (ac < 3 || ft_strlen(av[2]) > 1)
		return (1);
	// scale = ft_atoi(av[2]);
	// if (scale > 0)
	// 	return (scale);
	return (av[2][0] - '0');
}

t_game	*init_game(int ac, char **av)
{
	t_game	*game;

	game = calloc(1, sizeof(t_game)); //check
	if (!game)
	{
		perror("init_game");
		return (NULL);
	}
	if (init_mlx(game))
	{
		free(game);
		return (NULL);
	}
	if (init_player(game))
	{
		free(game->mlx);
		free(game->win);
		free(game);
		return (NULL);
	}
	if (init_sprites(game))
	{
		perror("tkt"); // soon
	}
	game->scale = get_scale(ac, av);
	return (game);
}
