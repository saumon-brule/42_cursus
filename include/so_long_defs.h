/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_defs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:39:25 by ebini             #+#    #+#             */
/*   Updated: 2025/02/19 22:39:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DEFS_H
# define SO_LONG_DEFS_H

# include "defs.h"
# include "mlx_defs.h"

typedef struct s_tuple
{
	size_t	x;
	size_t	y;
}			t_tuple;

typedef struct s_map
{
	char	*data;
	size_t	width;
	size_t	height;
}						t_map;

typedef struct s_sprites
{
	t_img	*wall;
	t_img	*air;
	t_img	*coin;
	t_img	*exit;
	t_img	*player;
}			t_sprites;

typedef void			t_mlx;
typedef void			t_win;

typedef struct s_game
{
	t_mlx		*mlx;
	t_win		*win;
	t_img		*displayed;
	t_sprites	sprites;
	int			action_count;
	int			scale;
	t_map		map;
	size_t		coins;
	t_tuple		player_pos;
}						t_game;

typedef struct s_img_data
{
	int		bpp;
	int		endian;
	int		width;
	void	*data;
}			t_img_data;

typedef struct s_map_checker
{
	ssize_t	p_pos;
	ssize_t	e_pos;
	size_t	c_count;
}			t_map_checker;

#endif
