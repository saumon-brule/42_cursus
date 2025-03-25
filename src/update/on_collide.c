/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_collide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:42:36 by ebini             #+#    #+#             */
/*   Updated: 2025/03/24 12:43:44 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_defs.h"

void get_collision_direction(t_player *player, t_point hit, int vertice_index)
{
	
}

void stick_player(t_player *player, t_point hit, int vertice_index)
{
	if (vertice_index == 0)
		player->pos = hit;
	else if (vertice_index == 1)
		player->pos = (t_point){hit.x - player->width, hit.y};
	else if (vertice_index == 2)
		player->pos = (t_point){hit.x, hit.y - player->height};
	else
		player->pos = (t_point){hit.x - player->width, hit.y - player->height};
	if ()
}
