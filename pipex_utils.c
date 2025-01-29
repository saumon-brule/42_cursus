/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:54:08 by ebini             #+#    #+#             */
/*   Updated: 2025/01/19 20:18:57 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "pipex_utils.h"

int	write_file_fd(char *file_name, int fd)
{
	int		file_fd;
	char	buffer[4096];
	int		read_len;

	file_fd = (open(file_name, O_RDONLY));
	if (file_fd < 0)
		return (-1);
	read_len = read(file_fd, buffer, 4096);
	while (read_len)
	{
		if (read_len < 0)
			return (-2);
		if (write(fd, buffer, read_len) < 0)
			return (-3);
		read_len = read(file_fd, buffer, 4096);
	}
	return (0);
}

int	swap_fd(int pipe_fd[3])
{
	close(pipe_fd[2]);
	if (pipe_fd[0] >= 0)
		close(pipe_fd[0]);
	pipe_fd[0] = pipe_fd[1];
	pipe(pipe_fd + 1);
	return (0);
}

int	get_fd(char *file_path, bool here_doc)
{
	int	fd_out;

	if (here_doc)
		fd_out = open(file_path, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		fd_out = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out < 0)
		exit(-1);
	return (fd_out);
}

void	free_cmd(t_sh_cmd *cmd)
{
	free_split(cmd->arguments);
	free(cmd->path);
}
