/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   draw_map.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ebini <ebini@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/02/20 07:12:13 by ebini			 #+#	#+#			 */
/*   Updated: 2025/02/20 09:44:30 by ebini			###   ########lyon.fr   */
/*																			*/
/* ************************************************************************** */

#include <mlx.h>

#include "so_long_defs.h"
#include "settings.h"

#include <stdio.h>

void	fill_image(void *addr, int color1, int color2, int line_length, int bpp)
{
	int	x;
	int	y;
	int	*pixel;

	y = WINDOW_HEIGHT;
	while (--y >= 0)
	{
		x = WINDOW_WIDTH;
		while (--x >= 0)
		{
			pixel = (int *)(addr + (y * line_length + x * (bpp / 8)));
			*pixel = (y % 50 == 0 || x % 50 == 0) ? color1 : color2;
		}
	}
}

void	draw_map(t_game *game)
{
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;

	addr = mlx_get_data_addr(game->displayed, &bpp, &line_length, &endian);
	fill_image(addr, 0x00FF00, 0xFF0000, line_length, bpp);
}
