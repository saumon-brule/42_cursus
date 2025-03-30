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

# include <time.h>
# include <sys/time.h>

# include "defs.h"
# include "mlx_defs.h"
# include "geometry.h"

typedef struct s_player
{
	t_point		pos;
	t_vec		speed;
	t_vec		acc;
	int			width;
	int			height;
	bool		is_grounded;
	bool		is_walled;
	t_img		*sprite;
}						t_player;

typedef struct s_map
{
	char	*data;
	int		width;
	int		height;
}						t_map;

typedef struct timeval	t_time;
typedef struct timespec	t_sleep;

typedef struct s_sprites
{
	t_img	*wall;
	t_img	*air;
	t_img	*coin;
}			t_sprites;

typedef struct s_input_map
{
	bool	k_f3;
}			t_input_map;

typedef struct s_settings
{
	bool	debug_enabled;
}			t_settings;

typedef struct s_debug
{
	t_segment	vertice_movements[4];
}			t_debug;

typedef void			t_mlx;
typedef void			t_win;

typedef struct s_game
{
	t_mlx		*mlx;
	t_win		*win;
	t_img		*displayed;
	t_img		*background;
	t_player	player;
	t_map		map;
	t_time		last_time;
	t_sprites	sprites;
	t_settings	settings;
	t_input_map	input_map;
	t_debug		debug;
	int			frames;
	double		dt;
	int			scale;
}						t_game;

typedef struct s_img_data
{
	int		bpp;
	int		endian;
	int		width;
	void	*data;
}						t_img_data;

#endif
