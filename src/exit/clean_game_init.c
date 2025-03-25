/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_game_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:23:17 by ebini             #+#    #+#             */
/*   Updated: 2025/03/24 19:02:31 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "so_long.h"

int	clean_to_mlx(t_game *game)
{
	free(game);
	return (1);
}

int	clean_to_player(t_game *game)
{
	mlx_destroy_image(game->mlx, game->displayed);
	mlx_destroy_window(game->mlx, game->win);
	clean_mlx(game->mlx);
	return (clean_to_mlx(game));
}

int	clean_to_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player->sprite);
	free(game->player);
	return (clean_to_player(game));
}

int	clean_to_input(t_game *game)
{
	mlx_destroy_image(game->mlx, game->sprites->air);
	mlx_destroy_image(game->mlx, game->sprites->wall);
	mlx_destroy_image(game->mlx, game->sprites->coin);
	free(game->sprites);
	return (clean_to_sprites(game));
}

int	clean_to_parse(t_game *game)
{
	free(game->settings);
	free(game->input_map);
	free(game->debug);
	return (clean_to_input(game));
}
