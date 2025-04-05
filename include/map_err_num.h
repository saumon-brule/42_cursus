/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_err_num.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:28:10 by ebini             #+#    #+#             */
/*   Updated: 2025/04/05 18:05:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ERR_NUM_H
# define MAP_ERR_NUM_H

enum e_map_errors
{
	MAP_SUCCESS = 0,
	MAP_EMPTY_FILE,
	MAP_INVALID_MAP_FORMAT,
	MAP_UNEXPECTED_TOKEN,
	MAP_OPEN_MAP,
	MAP_NO_START,
	MAP_NO_EXIT,
	MAP_TOO_MUCH_START,
	MAP_TOO_MUCH_EXIT,
	MAP_NO_COIN,
	MAP_COIN_OOB,
	MAP_EXIT_OOB,
	MAP_TOO_BIG_MAP,
};

#endif
