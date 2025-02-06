/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:44:04 by ebini             #+#    #+#             */
/*   Updated: 2025/02/06 19:12:23 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

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

char	*tmp_here_doc(char *limiter)
{
	char		*file;
	const int	fd = tmp_fd(&file, O_WRONLY);
	char		*line;
	size_t		line_len;

	if (fd == -1)
		return (NULL);
	while (true)
	{
		line = get_next_line(0);
		if (!line || is_limiter(line, limiter))
			break ;
		line_len = ft_strlen(line);
		if (write(fd, line, line_len) != (ssize_t)line_len)
		{
			close(fd);
			unlink(file);
			free(line);
			return (NULL);
		}
		free(line);
	}
	free(line);
	close(fd);
	return (file);
}
