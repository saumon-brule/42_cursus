/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:30:38 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 03:26:22 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

#include "so_long.h"

void	exit_game(t_game *game)
{
	free(game->map.data);
	clean_sprites(game);
	clean_game_struct(game);
	exit(EXIT_SUCCESS);
}
