/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:11:58 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 23:09:36 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"
#include "so_long.h"
#include "clean.h"

#include <stdio.h>

void	clean_sprites(t_game *game)
{
	if (game->sprites->air)
		mlx_destroy_image(game->mlx, game->sprites->air);
	if (game->sprites->wall)
		mlx_destroy_image(game->mlx, game->sprites->wall);
	if (game->sprites->coin)
		mlx_destroy_image(game->mlx, game->sprites->coin);
	free(game->sprites);
}

int	clean(t_game *game, unsigned int state)
{
	if (state == STATE_PARSE)
		return (clean_to_parse(game));
	return (0);
}
