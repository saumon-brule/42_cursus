/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:53:57 by ebini             #+#    #+#             */
/*   Updated: 2025/03/30 06:10:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "mlx.h"
#include "sources.h"
#include "so_long_defs.h"

bool	init_player(t_game *game)
{
	game->player.sprite = mlx_xpm_file_to_image(game->mlx, TEXTURE_PLAYER,
			&(game->player.width), &(game->player.height));
	if (!game->player.sprite)
	{
		perror("init_player");
		return (true);
	}
	game->player.speed.x = 0;
	game->player.speed.y = 0;
	game->player.acc.x = 0;
	game->player.acc.y = 0;
	game->player.is_walled = false;
	game->player.is_grounded = true;
	return (false);
}
