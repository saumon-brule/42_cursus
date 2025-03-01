/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:54:08 by ebini             #+#    #+#             */
/*   Updated: 2025/02/11 17:57:20 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "pipex_utils.h"

int	swap_fd(t_pipex_fd *pipe_fd)
{
	int	tmp_fd[2];

	close(pipe_fd->in);
	if (pipe_fd->out >= 0)
		close(pipe_fd->out);
	pipe_fd->out = pipe_fd->next_out;
	if (pipe(tmp_fd) == -1)
		return (-1);
	pipe_fd->in = tmp_fd[1];
	pipe_fd->next_out = tmp_fd[0];
	return (0);
}

int	change_fd(int old, int new)
{
	if (new < 0)
		return (-1);
	if (dup2(new, old) == -1)
	{
		perror("pipex");
		close(new);
		return (-1);
	}
	close(new);
	return (0);
}
