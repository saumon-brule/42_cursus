/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_on_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:27:57 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 03:04:32 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#include "so_long_defs.h"

#include <stdio.h>

void	handle_pixel_cpy(char *dest, char *src, int bpp_dest, int bpp_src)
{
	dest[0] = src[0];
	dest[1] = src[1];
	dest[2] = src[2];
	if (bpp_dest == 24)
		return ;
	if (bpp_src == 32)
		dest[3] = src[3];
	else
		dest[3] = (char)255;
}

void	put_pixel_on_screen(t_game *game, char *pixel, t_tuple pos, int bpp)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		y_pos;

	j = -1;
	while (++j < game->scale)
	{
		y = pos.y * game->scale + j;
		if (y < 0 || y > game->displayed->height)
			continue ;
		i = -1;
		y_pos = y * game->displayed->size_line;
		while (++i < game->scale)
		{
			x = pos.x * game->scale + i;
			if (x < 0 || x >= game->displayed->width)
				continue ;
			handle_pixel_cpy(game->displayed->data
				+ (y_pos + x * (game->displayed->bpp / 8)),
				pixel, game->displayed->bpp, bpp);
		}
	}
}

/**
 * In this function we admit that the screen is the final image displayed on the
 * "real" screen of the user (so it is already scaled) and that the img is not
 * scaled.
 */
void	draw_img_on_screen(t_img *img, t_game *game, t_tuple pos)
{
	int		i;
	int		j;
	t_tuple	screen_pos;

	j = -1;
	while (++j < img->height)
	{
		i = -1;
		while (++i < img->width)
		{
			screen_pos.x = (pos.x + i);
			screen_pos.y = (pos.y + j);
			put_pixel_on_screen(game,
				img->data + (j * img->size_line + i * (img->bpp / 8)),
				screen_pos, img->bpp);
		}
	}
}
