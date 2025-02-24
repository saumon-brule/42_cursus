/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:26:39 by ebini             #+#    #+#             */
/*   Updated: 2025/02/20 09:13:49 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "so_long_defs.h"

int	on_destroy(t_game *game);
int	on_key_press(int keycode, t_game *game);
int	on_key_release(int keycode, t_game *game);

#endif