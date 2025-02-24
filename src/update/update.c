/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 06:24:41 by ebini             #+#    #+#             */
/*   Updated: 2025/02/24 19:04:55 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>

#include "so_long.h"
#include "settings.h"

/**
 * player physics and movements :
 * update speed
 * move
 * update grounded/walled
 */

#include <stdio.h>

void	move_player(t_map *map, t_player *player, double dt)
{
	const t_vec		movement = {
		player->speed.x * dt,
		player->speed.y * dt
	};
	const t_index	collision = get_nearest_collision(map, player, movement);

	if (collision.x != -1)
		printf("colliding with : %c\n", get_map(map, collision.x, collision.y));
	else
		printf("colliding with : Nothing\n");
	player->pos.x += player->speed.x * dt;
	player->pos.y += player->speed.y * dt;
}

void	update_player_speed(t_player *player, double dt)
{
	double	friction_y;
	double	friction_x;

	if (player->is_grounded)
		friction_x = GROUND_FRICTION;
	else
		friction_x = AIR_FRICTION;
	if (player->is_walled)
		friction_y = WALL_FRICTION;
	else
		friction_y = AIR_FRICTION;
	player->speed.x = (player->speed.x + player->acc.x * dt)
		* pow(friction_x, dt);
	player->speed.y = (player->speed.y + player->acc.y * dt)
		* pow(friction_y, dt);
	if (fabs(player->speed.x) < 3)
		player->speed.x = 0;
	if (fabs(player->speed.y) < 3)
		player->speed.y = 0;
}

void	show_fps(double dt)
{
	static double	dt_array[100];
	static int		dt_index = 0;
	static bool		is_full = false;
	double			sum;
	int				i;

	dt_array[dt_index] = dt;
	dt_index = (dt_index + 1) % 100;
	if (dt_index == 0)
		is_full = true;
	if (is_full)
	{
		i = -1;
		sum = 0;
		while (++i < 100)
			sum += dt_array[i];
		printf("\rFPS: %.2f\n", (double)(1.0 / (sum / 100.0)));
	}
}

int	main_loop(t_game *game)
{
	const double	dt = wait_for_frame(&(game->last_time));

	move_player(game->map, game->player, dt);
	update_player_speed(game->player, dt);
	printf("====STATS====\n");
	printf("pos: %.3f:%.3f\n", game->player->pos.x, game->player->pos.y);
	show_fps(dt);
	draw_game(game);
	return (0);
}
