/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_children.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:21:27 by ebini             #+#    #+#             */
/*   Updated: 2025/03/05 14:48:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	child_process(t_pipex_fd *pipe_fd, char *command, char **env)
{
	int	returned_value;

	close(pipe_fd->next_out);
	if (pipe_fd->out == -1)
	{
		close(pipe_fd->in);
		close(pipe_fd->out);
		free(pipe_fd);
		exit(1);
	}
	if (change_fd(STDIN_FILENO, pipe_fd->out) == -1)
	{
		free(pipe_fd);
		exit(1);
	}
	if (change_fd(1, pipe_fd->in) == -1)
	{
		free(pipe_fd);
		exit(1);
	}
	returned_value = exec_shell(command, env);
	close(pipe_fd->in);
	close(pipe_fd->out);
	free(pipe_fd);
	exit(returned_value);
}

void	handle_fds(int pc, int i, t_pipex_fd *pipe_fd)
{
	if (i == pc - 2)
	{
		close(pipe_fd->in);
		pipe_fd->in = pipe_fd->last_out;
	}
	else
		close(pipe_fd->last_out);
}

int	pipex_fork(t_pipex_fd *pipe_fd, int pc, char **pv, char **env)
{
	int	i;
	int	pid;

	i = 0;
	while (++i < pc - 1)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("pipex");
			return (-1);
		}
		if (pid == 0)
		{
			handle_fds(pc, i, pipe_fd);
			child_process(pipe_fd, pv[i], env);
		}
		else if (i < pc - 2 && swap_fd(pipe_fd) == -1)
			return (-1);
	}
	return (pid);
}
