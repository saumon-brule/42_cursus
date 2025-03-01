/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:04 by ebini             #+#    #+#             */
/*   Updated: 2025/02/11 17:21:48 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#include "libft.h"
#include "here_doc.h"

bool	is_limiter(char *line, char *limiter)
{
	const size_t	limiter_len = ft_strlen(limiter);
	const size_t	line_len = ft_strlen(line);

	if (limiter_len != line_len - 1)
		return (false);
	if (ft_strncmp(limiter, line, limiter_len))
		return (false);
	if (line[limiter_len] != '\n')
		return (false);
	return (true);
}

int	write_line(int fd, char *line)
{
	const size_t	line_len = ft_strlen(line);

	if (write(fd, line, line_len) != (ssize_t)line_len)
	{
		close(fd);
		free(line);
		perror("pipex");
		return (-1);
	}
	return (0);
}

int	exit_here_doc(int fd, char *line, char *file)
{
	int	result_fd;

	free(line);
	close(fd);
	result_fd = open(file, O_RDONLY);
	unlink(file);
	free(file);
	if (result_fd == -1)
		perror("pipex");
	return (result_fd);
}

int	clear_here_doc(char *file)
{
	unlink(file);
	free(file);
	return (-1);
}

int	tmp_here_doc(char *limiter)
{
	char		*file;
	char		*line;
	const int	fd = tmp_fd(&file, O_WRONLY);

	if (fd == -1)
		return (-1);
	errno = 0;
	line = get_next_line(0);
	while (line && !is_limiter(line, limiter))
	{
		if (write_line(fd, line) == -1)
			return (clear_here_doc(file));
		free(line);
		line = get_next_line(0);
	}
	if (!line && errno)
	{
		perror("pipex: get_next_line");
		close(fd);
		return (clear_here_doc(file));
	}
	return (exit_here_doc(fd, line, file));
}
