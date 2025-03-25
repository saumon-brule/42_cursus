/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 20:01:53 by ebini             #+#    #+#             */
/*   Updated: 2025/03/24 21:18:21 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "so_long.h"
#include "libft.h"

#include <stdio.h>

void	draw_line_x(t_game *game, t_segment *line)
{
	const int	width = (int)line->vec.x;
	int			step;
	int			i;

	if (!width)
		return ;
	step = width / (int)fabs(line->vec.x);
	i = 0;
	while (i != width)
	{
		put_debug_pixel(game, (t_point){line->pos.x + i, line->pos.y
			+ ((double)i / width) * line->vec.y});
		i += step;
	}
}

void	draw_line_y(t_game *game, t_segment *line)
{
	const int	height = (int)line->vec.y;
	int			step;
	int			i;

	if (!height)
		return ;
	step = height / (int)fabs(line->vec.y);
	i = 0;
	while (i != height)
	{
		put_debug_pixel(game, (t_point){line->pos.x + ((double)i / height)
			* line->vec.x, line->pos.y + i});
		i += step;
	}
}

void	draw_line(t_game *game, t_segment *line)
{
	if (fabs(line->vec.x) > fabs(line->vec.y))
		draw_line_x(game, line);
	else
		draw_line_y(game, line);
}
