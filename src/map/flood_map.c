/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:51:09 by ebini             #+#    #+#             */
/*   Updated: 2025/04/04 10:54:19 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "so_long.h"
#include "map_err_num.h"

bool	add_to_flood_list(t_map *map, t_map *seen_map,
		t_list **flood_list, t_tuple pos)
{
	t_list	*flood_node;

	if (!get_map(seen_map, pos.x, pos.y)
		&& get_map(map, pos.x, pos.y) != '1'
		&& get_map(map, pos.x, pos.y) != 'P')
	{
		flood_node = flood_node_create(pos);
		if (!flood_node)
			return (-1);
		lstadd_back(flood_list, flood_node);
		set_map(seen_map, pos.x, pos.y, 1);
	}
	return (MAP_SUCCESS);
}

int	update_flood_list(t_map *map, t_map *seen_map,
		t_list **flood_list, t_tuple pos)
{
	if (add_to_flood_list(map, seen_map, flood_list,
			(t_tuple){pos.x + 1, pos.y}))
		return (-1);
	if (add_to_flood_list(map, seen_map, flood_list,
			(t_tuple){pos.x - 1, pos.y}))
		return (-1);
	if (add_to_flood_list(map, seen_map, flood_list,
			(t_tuple){pos.x, pos.y + 1}))
		return (-1);
	if (add_to_flood_list(map, seen_map, flood_list,
			(t_tuple){pos.x, pos.y - 1}))
		return (-1);
	return (MAP_SUCCESS);
}

int	check_flood_tile(t_map *map, t_map *seen_map,
		t_list **flood_list, t_map_checker *checker)
{
	const t_tuple	pos = *(t_tuple *)((*flood_list)->content);
	const char		tile = get_map(map, pos.x, pos.y);
	int				update_result;

	if (!pos.x || !pos.y || pos.x == map->width - 1 || pos.y == map->height - 1)
		return (MAP_OPEN_MAP);
	if (tile == 'C')
		checker->c_count--;
	if (tile == 'E')
		checker->e_pos = -1;
	update_result = update_flood_list(map, seen_map, flood_list, pos);
	flood_node_del_first(flood_list);
	return (update_result);
}

int	flood_map(t_map *map, t_tuple pos, t_map_checker *checker)
{
	t_map	*seen_map;
	t_list	*flood_list;
	int		flood_result;

	flood_list = flood_node_create(pos);
	if (!flood_list)
		return (-1);
	seen_map = duplicate_map(map);
	if (!seen_map)
	{
		flood_node_del_first(&flood_list);
		return (-1);
	}
	while (flood_list)
	{
		flood_result = check_flood_tile(map, seen_map, &flood_list, checker);
		if (flood_result)
		{
			lstclear(&flood_list, &free);
			clear_map(seen_map);
			return (flood_result);
		}
	}
	clear_map(seen_map);
	return (MAP_SUCCESS);
}
