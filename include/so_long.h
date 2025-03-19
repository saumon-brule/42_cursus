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

bool		init_mlx(t_game *game);
bool		init_sprites(t_game *game);
bool		init_player(t_game *game);
bool		init_input_map(t_game *game);
bool		init_game(int ac, char **av, t_game **game);

//        MAP         //

char		get_map(t_map *map, size_t x, size_t y);
int			parse_map(t_game *game, char *map_file);
char		*get_map_errors(int map_error_num);

//       MATHS        //

t_collision	check_segment_square_collision(t_segment *segment,
			t_square *square);
double		player_square_distance(t_player *player, t_index *square_position);

//       SETUP        //

int			setup_game(t_game *game);

//       UPDATE       //

void		calc_area(t_segment *segment, t_map *map,
			t_index *start, t_area *size);
t_collision	get_nearest_vertice_collision(t_game *game,
			t_segment *vertice_movement);
t_collision	get_nearest_collision(t_game *game, t_vec movement);
double		wait_for_frame(t_time *last_time);
int			main_loop(t_game *game);

//        DRAW        //

void		put_pixel_on_screen(t_game *game, char *pixel, t_point pos, int bpp);
bool		draw_game(t_game *game);
void		draw_img_on_screen(t_img *img, t_game *game, t_point pos);
void		draw_map(t_game *game);
void		draw_player(t_game *game);

//        CLEAN       //

void		clean_sprites(t_game *game);
int			clean_to_mlx(t_game *game);
int			clean_to_player(t_game *game);
int			clean_to_sprites(t_game *game);
int			clean_to_input(t_game *game);
int			clean_to_parse(t_game *game);
void		clean_mlx(t_mlx *mlx);
int			clean(t_game *game, unsigned int state);

//        EXIT        //

void		exit_game(t_game *game);

//        DEBUG       //

void		put_debug_pixel(t_game *game, t_point pos);
void		draw_line(t_game *game, t_segment *line);

#endif
