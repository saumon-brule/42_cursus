/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:23:17 by ebini             #+#    #+#             */
/*   Updated: 2025/03/30 06:48:38 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "so_long.h"

int	clean_to_player(t_game *game)
{
	mlx_destroy_image(game->mlx, game->displayed);
	mlx_destroy_window(game->mlx, game->win);
	clean_mlx(game->mlx);
	return (EXIT_FAILURE);
}

int	clean_to_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.sprite);
	return (clean_to_player(game));
}

int	clean_to_parsing(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprites.air);
	mlx_destroy_image(game->mlx, game->sprites.wall);
	mlx_destroy_image(game->mlx, game->sprites.coin);
	return (clean_to_sprites(game));
}
