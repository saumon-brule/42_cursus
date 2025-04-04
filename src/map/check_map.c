/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 06:46:35 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 13:01:41 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "so_long.h"
#include "map_err_num.h"

int	check_tile(char tile, size_t i, t_map_checker *checker)
{
	if (tile == 'C')
		checker->c_count++;
	else if (tile == 'P')
	{
		if (checker->p_pos > -1)
			return (MAP_TOO_MUCH_START);
		checker->p_pos = i;
	}
	else if (tile == 'E')
	{
		if (checker->e_pos > -1)
			return (MAP_TOO_MUCH_EXIT);
		checker->e_pos = i;
	}
	else if (tile != '0' && tile != '1')
		return (MAP_UNEXPECTED_TOKEN);
	return (MAP_SUCCESS);
}

int	iterate_map(t_map *map, t_map_checker *checker)
{
	size_t			i;
	int				index_result;

	i = 0;
	while (i < map->width * map->height)
	{
		index_result = check_tile(map->data[i], i, checker);
		if (index_result)
			return (index_result);
		++i;
	}
	if (checker->e_pos < 0)
		return (MAP_NO_EXIT);
	if (checker->p_pos < 0)
		return (MAP_NO_START);
	if (!checker->c_count)
		return (MAP_NO_COIN);
	return (MAP_SUCCESS);
}

int	check_map(t_game *game)
{
	t_map_checker	checker;
	int				check_result;

	checker.p_pos = -1;
	checker.e_pos = -1;
	checker.c_count = 0;
	check_result = iterate_map(&(game->map), &checker);
	if (check_result)
		return (check_result);
	game->coins = checker.c_count;
	game->player_pos.x = checker.p_pos % game->map.width;
	game->player_pos.y = checker.p_pos / game->map.width;
	check_result = flood_map(&(game->map), game->player_pos, &checker);
	if (check_result)
		return (check_result);
	if (checker.c_count)
		return (MAP_COIN_OOB);
	if (checker.e_pos > -1)
		return (MAP_EXIT_OOB);
	return (MAP_SUCCESS);
}
