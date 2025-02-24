/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_on_screen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 10:27:57 by ebini             #+#    #+#             */
/*   Updated: 2025/02/23 12:30:27 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#include "so_long_defs.h"
#include "geometry.h"

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

void	put_pixel_on_screen(t_game *game, char *pixel, t_point pos, int bpp)
{
	int		i;
	int		j;
	int		x;
	int		y;

	j = -1;
	while (++j < game->scale)
	{
		y = pos.y * game->scale + j;
		if (y < 0 || y > game->displayed->height)
			continue ;
		i = -1;
		while (++i < game->scale)
		{
			x = pos.x * game->scale + i;
			if (x < 0 || x > game->displayed->width)
				continue ;
			handle_pixel_cpy(game->displayed->data
				+ (y * game->displayed->size_line + x * (game->displayed->bpp / 8)), pixel,
				game->displayed->bpp, bpp);
		}
	}
}

/**
 * In this function we admit that the screen is the final image displayed on the
 * "real" screen of the user (so it is already scaled) and that the img is not
 * scaled. This is usefull because it will allow every calculation of physic and
 * speed to not need  and it will only be the camera's properties that will 
 * change.
 */
void	draw_img_on_screen(t_img *img, t_game *game, t_point pos)
{
	int		i;
	int		j;
	t_point	screen_pos;

	j = -1;
	while (++j < img->height)
	{
		i = -1;
		while (++i < img->width)
		{
			screen_pos.x = pos.x + i;
			screen_pos.y = pos.y + j;
			put_pixel_on_screen(game,
				img->data + (j * img->size_line + i * (img->bpp / 8)),
				screen_pos, img->bpp);
		}
	}
}
