/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 01:56:46 by ebini             #+#    #+#             */
/*   Updated: 2025/03/24 19:14:32 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include <stdio.h>

#include "libft.h"
#include "so_long.h"
#include "settings.h"
#include "sources.h"
#include "clean.h"

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

bool	init_game(int ac, char **av, t_game **game)
{
	*game = ft_calloc(1, sizeof(t_game)); // malloc ?
	if (!*game)
	{
		perror("init_game");
		return (true);
	}
	if (init_mlx(*game))
		return (clean(*game, STATE_MLX));
	if (init_player(*game))
		return (clean(*game, STATE_PLAYER));
	if (init_sprites(*game))
		return (clean(*game, STATE_SPRITES));
	if (init_settings(*game))
		return (clean(*game, STATE_INPUT));
	(*game)->scale = get_scale(ac, av);
	return (false);
}
