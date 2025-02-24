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

int	join_line_to_map(t_map	*map, char *line)
{
	size_t	line_len;
	char	*new_data;

	line_len = ft_strlen(line);
	if (line[line_len - 1] == '\n')
		line[--line_len] = '\0';
	if (map->data)
	{
		printf("line: %zu\nmap: %zu\n", line_len, map->width);
		if (line_len != map->width)
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
	map->data = ft_strdup(line);
	map->width = line_len;
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

int	parse_map(t_map **map_ptr, char *map_file)
{
	int			map_fd;
	int			result;

	map_fd = open(map_file, O_RDONLY);
	if (map_fd == -1)
	{
		ft_dprintf(2, "parse_map: %s: %s", strerror(errno), map_file);
		return (-1);
	}
	*map_ptr = malloc(sizeof(t_map));
	if (!*map_ptr)
	{
		perror("parse_map");
		close(map_fd);
		return (-1);
	}
	(*map_ptr)->height = 0;
	result = fill_map(*map_ptr, map_fd);
	if (result)
		free(*map_ptr);
	close(map_fd);
	return (result);
}
