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

#include "so_long_defs.h"
#include "libft.h"
#include "map_err_num.h"
#include "settings.h"

int	join_line_to_map(t_map	*map, char *line)
{
	size_t	line_len;
	char	*new_data;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line[--line_len] = '\0';
	if (map->data)
	{
		if (line_len != (size_t)map->width)
			return (MAP_INVALID_MAP_FORMAT);
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
		++(map->height);
		return (MAP_SUCCESS);
	}
	map->data = ft_memdup(line, line_len);
	map->width = line_len;
	map->height = 1;
	return (MAP_SUCCESS);
}

int	fill_map(t_map *map, int map_fd)
{
	char	*line;
	int		join_result;

	map->data = NULL;
	errno = 0;
	line = get_next_line(map_fd);
	while (line)
	{
		join_result = join_line_to_map(map, line);
		free(line);
		if (join_result)
		{
			free(map->data);
			return (join_result);
		}
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
	int			i;

	if (map_fd == -1)
	{
		ft_dprintf(2, "parse_map: %s: %s", strerror(errno), map_file);
		return (-1);
	}
	game->map = malloc(sizeof(t_map));
	if (!game->map)
	{
		perror("parse_map");
		close(map_fd);
		return (-1);
	}
	game->map->height = 0;
	result = fill_map(game->map, map_fd);
	if (result)
		free(game->map);
	close(map_fd);
	i = 0;
	while (game->map->data[i] != 'P')
		++i;
	game->player->pos.x = (double)((i % game->map->width) * CELL_SIZE)
		+ ((double)CELL_SIZE - (double)game->player->width) / 2.0;
	game->player->pos.y = (double)((i / game->map->height - 1) * CELL_SIZE)
		+ ((double)CELL_SIZE - (double)game->player->height) / 2.0;
	return (result);
}
