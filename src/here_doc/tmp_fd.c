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
#include <stdio.h>
#include <errno.h>
#include "libft.h"

char	*generate_random_string(void)
{
	const int	fd = open("/dev/urandom", O_RDONLY);
	char		*string;

	if (fd == -1)
	{
		perror("pipex: Couldn't open /dev/urandom");
		return (NULL);
	}
	string = malloc(11 * sizeof(char));
	if (!string)
	{
		perror("pipex");
		return (NULL);
	}
	if (read(fd, string, 10) != 10)
	{
		free(string);
		perror("pipex: Couldn't read in /dev/urandom");
		return (NULL);
	}
	string[10] = '\0';
	return (string);
}

char	*here_doc_path(void)
{
	char	*path;
	char	*random_string;

	while (true)
	{
		random_string = generate_random_string();
		if (!random_string)
			return (NULL);
		path = ft_strjoin("/tmp/pipex_here_doc_", random_string);
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

	*path = here_doc_path();
	if (!*path)
		return (-1);
	fd = open(*path, flags | O_CREAT, 0644);
	if (fd == -1)
	{
		free(*path);
		perror("pipex");
		return (-1);
	}
	return (fd);
}
