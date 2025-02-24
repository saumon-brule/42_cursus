/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:53:18 by aviscogl          #+#    #+#             */
/*   Updated: 2025/02/19 14:53:18 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long_defs.h"

//        INIT        //

t_game		*init_game(int ac, char **av);

//        MAP         //
char		get_map(t_map *map, size_t x, size_t y);
int			parse_map(t_map **map, char *map_file);
char		*get_map_errors(int map_error_num);

//       MATHS        //

double		player_square_distance(t_player *player, t_index square_position);

//       SETUP        //

int			setup_game(t_game *game);

//       UPDATE       //

bool	check_player_movement_square(t_player *player, t_vec movement,
	int x, int y);
t_index		get_nearest_collision(t_map *map, t_player *player, t_vec movement);
double		wait_for_frame(t_time *last_time);
int			main_loop(t_game *game);

//        DRAW        //

bool		draw_game(t_game *game);
void		draw_img_on_screen(t_img *img, t_game *game, t_point pos);
void		draw_map(t_game *game);
void		draw_player(t_game *game);

//        CLEAN       //

int			clean_sprites(t_game *game);
void		clean_mlx(t_mlx *mlx);
int			clean(t_game *game, unsigned int state);

//        EXIT        //

void		exit_game(t_game *game);

#endif
