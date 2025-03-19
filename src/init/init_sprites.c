/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 23:39:39 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 21:50:23 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include "settings.h"
#include "sources.h"

t_img	*new_xpm_img(t_game *game, char *path)
{
	t_img	*result;
	int		dummy_int;

	result = mlx_xpm_file_to_image(game->mlx, path, &dummy_int, &dummy_int);
	if (!result)
		ft_dprintf(2, "init_sprites: %s: %s\n", strerror(errno), path);
	return (result);
}

bool	init_sprites(t_game *game)
{
	game->sprites = malloc(sizeof(t_sprites));
	if (!game->sprites)
	{
		perror("init_sprites");
		return (true);
	}
	game->sprites->air = new_xpm_img(game, TEXTURE_AIR);
	game->sprites->wall = new_xpm_img(game, TEXTURE_WALL);
	game->sprites->coin = new_xpm_img(game, TEXTURE_COIN);
	if (!game->sprites->air || !game->sprites->wall || !game->sprites->coin)
	{
		clean_sprites(game);
		return (true);
	}
	return (false);
}
