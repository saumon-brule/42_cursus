/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 22:05:41 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 23:14:26 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "so_long_defs.h"
#include "libft.h"

bool	init_input_map(t_game *game)
{
	game->input_map = ft_calloc(1, sizeof(t_input_map));
	if (!game->input_map)
	{
		perror("init_input_map");
		return (true);
	}
	game->settings = ft_calloc(1, sizeof(t_settings));
	if (!game->settings)
	{
		perror("init_input_map");
		free(game->input_map);
		return (true);
	}
	return (false);
}
