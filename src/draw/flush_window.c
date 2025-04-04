/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flush.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 04:47:25 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 04:51:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long_defs.h"

void	flush_window(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->displayed, 0, 0);
}
