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

bool	init_game(int ac, char **av, t_game *game);
bool	init_sprites(t_game *game);

//        MAP         //

void	set_map(t_map *map, size_t x, size_t y, char value);
char	get_map(t_map *map, size_t x, size_t y);
int		parse_map(t_game *game, char *map_file);
char	*get_map_errors(int map_error_num);
int		check_map(t_game *game);
t_list	*flood_node_create(t_tuple pos);
void	flood_node_del_first(t_list **lst);
int		flood_map(t_map *map, t_tuple pos, t_map_checker *checker);
t_map	*duplicate_map(t_map *map);
void	clear_map(t_map *map);

//       UTILS        //

void	convert_line_to_string(char *line);

//       SETUP        //

int		setup_game(t_game *game);

//        DRAW        //

bool	draw_game(t_game *game);
void	draw_img_on_screen(t_img *img, t_game *game, t_tuple pos);
void	draw_map(t_game *game);
void	draw_tile(t_game *game, t_map *map, int x, int y);
void	draw_player(t_game *game);
void	flush_window(t_game *game);

//         MOVE       //

void	move_player(t_game *game, int dx, int dy);
bool	handle_tile(char tile, t_game *game, t_tuple new_pos);

//        CLEAN       //

void	clean_game_struct(t_game *game);
void	clean_sprites(t_game *game);
void	clean_mlx(t_mlx *mlx);

//        EXIT        //

void	exit_game(t_game *game);

#endif
