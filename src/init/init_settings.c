/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:05:41 by ebini             #+#    #+#             */
/*   Updated: 2025/03/24 19:17:41 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "so_long_defs.h"
#include "libft.h"

bool	init_debug(t_game *game)
{
	game->debug = ft_calloc(1, sizeof(t_debug));
	if (!game->debug)
	{
		perror("init_debug");
		return (true);
	}
	return (false);
}

bool	init_input_map(t_game *game)
{
	game->input_map = ft_calloc(1, sizeof(t_input_map));
	if (!game->input_map)
	{
		perror("init_input_map");
		return (true);
	}
	return (false);
}

bool	init_settings(t_game *game)
{
	game->settings = ft_calloc(1, sizeof(t_settings));
	if (!game->settings)
	{
		perror("init_settings");
		return (true);
	}
	if (init_input_map(game))
	{
		free(game->settings);
		return (true);
	}
	if (init_debug(game))
	{
		free(game->settings);
		free(game->input_map);
		return (true);
	}
	return (false);
}
