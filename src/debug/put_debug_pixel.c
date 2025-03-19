/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_debug_pixel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:21:39 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 23:41:16 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>

void	put_debug_pixel(t_game *game, t_point pos)
{
	put_pixel_on_screen(game, (char []){0, 0, 255, 255}, pos, 32);
}
