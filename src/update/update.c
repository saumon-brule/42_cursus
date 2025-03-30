/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 06:24:41 by ebini             #+#    #+#             */
/*   Updated: 2025/03/30 07:08:21 by ebini            ###   ########lyon.fr   */
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

void	stick_player(t_player *player, t_point hit, int vertice_index)
{
	if (vertice_index == 0)
		player->pos = hit;
	else if (vertice_index == 1)
		player->pos = (t_point){hit.x - player->width, hit.y};
	else if (vertice_index == 2)
		player->pos = (t_point){hit.x, hit.y - player->height};
	else
		player->pos = (t_point){hit.x - player->width, hit.y - player->height};
}

void	move_player(t_game *game, double dt, t_segment *vertice_movement_array)
{
	t_player			*player;
	const t_vec			movement = {
		game->player.speed.x * dt,
		game->player.speed.y * dt
	};
	const t_collision	collision = get_nearest_collision(game, movement,
		vertice_movement_array);

	player = &(game->player);
	if (collision.collides)
	{
		stick_player(player, collision.pos, collision.vertice_index);
		player->speed.x *= fabs((collision.pos.x / CELL_SIZE) - round(collision.pos.x / CELL_SIZE)) < fabs((collision.pos.y / CELL_SIZE) - round(collision.pos.y / CELL_SIZE));
		player->speed.y *= fabs((collision.pos.y / CELL_SIZE) - round(collision.pos.y / CELL_SIZE)) < fabs((collision.pos.x / CELL_SIZE) - round(collision.pos.x / CELL_SIZE));
	}
	else
	{
		player->pos.x += movement.x;
		player->pos.y += movement.y;
	}
	printf("%.3f;%.3f\n", player->speed.x, player->speed.y);
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
	if (fabs(player->speed.x) < 0.5)
		player->speed.x = 0;
	if (fabs(player->speed.y) < 0.5)
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
	game->dt = wait_for_frame(&(game->last_time));
	// if (game->frames)
	// 	exit_game(game);
	move_player(game, game->dt, game->debug.vertice_movements);
	update_player_speed(&(game->player), game->dt);
	// printf("====STATS====\n");
	// printf("pos: %.3f:%.3f\n", game->player->pos.x, game->player->pos.y);
	// show_fps(dt);
	draw_game(game);
	// ++(game->frames);
	return (0);
}
