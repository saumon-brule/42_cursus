/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:12:37 by ebini             #+#    #+#             */
/*   Updated: 2025/02/24 17:43:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_defs.h"
#include "stdlib.h"
#include "stddef.h"

void	set_map(t_map *map, size_t x, size_t y, char value)
{
	map->data[y * map->width + x] = value;
}

char	get_map(t_map *map, size_t x, size_t y)
{
	return (map->data[y * map->width + x]);
}
