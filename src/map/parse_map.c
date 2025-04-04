/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:09:16 by ebini             #+#    #+#             */
/*   Updated: 2025/02/19 20:09:16 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "so_long.h"
#include "libft.h"
#include "map_err_num.h"
#include "settings.h"

int	join_line_to_map(t_map *map, char *line)
{
	const size_t	line_len = ft_strlen(line);
	char			*new_data;

	if (!map->data)
	{
		map->data = ft_memdup(line, line_len);
		map->width = ft_strlen(line);
		if (map->width > INT_MAX)
			return (MAP_TOO_BIG_MAP);
		map->height = 1;
		return (MAP_SUCCESS);
	}
	new_data = malloc((map->height + 1) * map->width * sizeof(char));
	if (!new_data)
	{
		perror("join_line_to_map");
		return (-1);
	}
	ft_strncpy(map->data, new_data, map->height * map->width);
	ft_strncpy(line, new_data + map->height * map->width, map->width);
	free(map->data);
	map->data = new_data;
	if (++(map->height) > INT_MAX)
		return (MAP_TOO_BIG_MAP);
	return (MAP_SUCCESS);
}

int	fill_map_loop(t_map *map, char *line)
{
	int	join_result;

	convert_line_to_string(line);
	if (map->data && ft_strlen(line) != map->width)
	{
		free(line);
		free(map->data);
		return (MAP_INVALID_MAP_FORMAT);
	}
	join_result = join_line_to_map(map, line);
	free(line);
	if (join_result)
		free(map->data);
	return (join_result);
}

int	fill_map(t_map *map, int map_fd)
{
	char	*line;
	int		fill_result;

	map->data = NULL;
	errno = 0;
	line = get_next_line(map_fd);
	while (line)
	{
		fill_result = fill_map_loop(map, line);
		if (fill_result)
			return (fill_result);
		line = get_next_line(map_fd);
	}
	if (errno)
	{
		free(map->data);
		perror("get_next_line");
		return (-1);
	}
	return (MAP_SUCCESS);
}

int	parse_map(t_game *game, char *map_file)
{
	const int	map_fd = open(map_file, O_RDONLY);
	int			result;

	if (map_fd == -1)
	{
		ft_dprintf(2, "parse_map: %s: %s", strerror(errno), map_file);
		return (-1);
	}
	game->map.height = 0;
	result = fill_map(&(game->map), map_fd);
	close(map_fd);
	if (result)
		return (result);
	result = check_map(game);
	if (result)
		free(game->map.data);
	return (result);
}
