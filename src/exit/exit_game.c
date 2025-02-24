/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:30:38 by ebini             #+#    #+#             */
/*   Updated: 2025/02/24 19:09:39 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

#include "so_long_defs.h"

void	exit_game(t_game *game)
{
	free(game->map->data);
	free(game->map);
	mlx_destroy_image(game->mlx, game->player->sprite);
	mlx_destroy_image(game->mlx, game->displayed);
	free(game->player);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}
