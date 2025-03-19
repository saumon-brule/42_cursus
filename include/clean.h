/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 09:16:15 by ebini             #+#    #+#             */
/*   Updated: 2025/03/18 23:06:46 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H

enum e_crash_state
{
	STATE_MLX = 0,
	STATE_PLAYER,
	STATE_SPRITES,
	STATE_INPUT,
	STATE_PARSE,
};

#endif
