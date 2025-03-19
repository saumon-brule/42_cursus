/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:30:38 by ebini             #+#    #+#             */
/*   Updated: 2025/02/26 17:17:02 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

#include "so_long.h"

void	exit_game(t_game *game)
{
	free(game->map->data);
	free(game->map);
	clean_sprites(game);
	mlx_destroy_image(game->mlx, game->player->sprite);
	mlx_destroy_image(game->mlx, game->displayed);
	free(game->player);
	mlx_destroy_window(game->mlx, game->win);
	clean_mlx(game->mlx);
	free(game);
	exit(EXIT_SUCCESS);
}
