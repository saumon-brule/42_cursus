/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:54:08 by ebini             #+#    #+#             */
/*   Updated: 2025/03/25 18:25:26 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "pipex_utils.h"

int	swap_fd(t_pipex_fd *pipe_fd, bool is_last)
{
	int	tmp_fd[2];

	close(pipe_fd->out);
	if (pipe_fd->in > -1)
		close(pipe_fd->in);
	pipe_fd->in = pipe_fd->next_in;
	if (is_last)
		return (0);
	if (pipe(tmp_fd) == -1)
		return (-1);
	pipe_fd->out = tmp_fd[1];
	pipe_fd->next_in = tmp_fd[0];
	return (0);
}

int	change_fd(int new, int old)
{
	if (new < 0)
		return (-1);
	if (dup2(new, old) == -1)
	{
		perror("pipex");
		return (-1);
	}
	close(new);
	return (0);
}
