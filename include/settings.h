/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 01:47:36 by ebini             #+#    #+#             */
/*   Updated: 2025/04/02 13:19:01 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include <X11/keysym.h>

# define CELL_SIZE 25

# define GAME_TITLE "So Long | By ebini"
# define WINDOW_WIDTH 2200
# define WINDOW_HEIGHT 1200
# define FPS_CAP 100

// KEYS //

# define SET_AZERTY_MAPPING

# ifdef SET_AZERTY_MAPPING
#  define GAME_KEY_LEFT XK_q
#  define GAME_KEY_UP XK_z
# else
#  define GAME_KEY_LEFT XK_a
#  define GAME_KEY_UP XK_w
# endif

# define GAME_KEY_DOWN XK_s
# define GAME_KEY_RIGHT XK_d
# define GAME_KEY_EXIT XK_Escape

#endif
