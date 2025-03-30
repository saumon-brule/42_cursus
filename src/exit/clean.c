/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:11:58 by ebini             #+#    #+#             */
/*   Updated: 2025/03/30 06:38:10 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "so_long.h"
#include "clean.h"

#include <stdio.h>

void	clean_sprites(t_game *game)
{
	if (game->sprites.air)
		mlx_destroy_image(game->mlx, game->sprites.air);
	if (game->sprites.wall)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.coin)
		mlx_destroy_image(game->mlx, game->sprites.coin);
}
