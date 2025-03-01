/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 06:34:01 by ebini             #+#    #+#             */
/*   Updated: 2025/01/29 07:43:27 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#include "here_doc.h"
#include "pipex_utils.h"

char	*generate_random_string(size_t n)
{
	const int	fd = open(RANDOM_FILE, O_RDONLY);
	char		*string;

	if (fd == -1)
	{
		ft_dprintf(2, "pipex: Can't open %s: %s", RANDOM_FILE, strerror(errno));
		return (NULL);
	}
	string = malloc((n + 1) * sizeof(char));
	if (!string)
	{
		perror("pipex");
		close(fd);
		return (NULL);
	}
	if (read(fd, string, n) != (ssize_t)n)
	{
		ft_dprintf(2, "pipex: Can't read %s: %s", RANDOM_FILE, strerror(errno));
		free(string);
		close(fd);
		return (NULL);
	}
	string[n] = '\0';
	close(fd);
	return (string);
}

char	*tmp_path(void)
{
	char	*path;
	char	*random_string;

	while (true)
	{
		random_string = generate_random_string(10);
		if (!random_string)
			return (NULL);
		path = ft_strjoin(PIPEX_TMP_PATH, random_string);
		free(random_string);
		if (!path)
		{
			perror("pipex");
			return (NULL);
		}
		if (access(path, F_OK) == -1 && errno == ENOENT)
			return (path);
		free(path);
	}
}

int	tmp_fd(char **path, int flags)
{
	int		fd;

	*path = tmp_path();
	if (!*path)
		return (-1);
	fd = open(*path, flags | O_CREAT, 0600);
	if (fd == -1)
	{
		free(*path);
		perror("pipex");
		return (-1);
	}
	return (fd);
}
