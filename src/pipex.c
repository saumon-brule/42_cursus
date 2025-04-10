/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:51:33 by ebini             #+#    #+#             */
/*   Updated: 2025/04/10 18:10:47 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>

#include "pipex_utils.h"
#include "here_doc.h"

int	init_input(char *param, bool here_doc)
{
	int	fd;

	if (here_doc)
		fd = tmp_here_doc(param);
	else
		fd = open(param, O_RDONLY);
	if (fd == -1)
	{
		if (here_doc)
			perror("pipex");
		else
			ft_dprintf(2, "pipex: %s: %s\n", strerror(errno), param);
		return (-1);
	}
	return (fd);
}

int	init_pipex(t_pipex_fd *pipe_fd, char *param, bool here_doc)
{
	int	tmp_fd[2];

	pipe_fd->in = init_input(param, here_doc);
	if (pipe(tmp_fd) == -1)
	{
		perror("pipex");
		if (pipe_fd->in > -1)
			close(pipe_fd->in);
		return (1);
	}
	pipe_fd->out = tmp_fd[1];
	pipe_fd->next_in = tmp_fd[0];
	return (0);
}

int	exit_pipex(t_pipex_fd *pipe_fd, pid_t last_pid, bool pipe_error)
{
	int	stat_loc;

	close(pipe_fd->out);
	close(pipe_fd->next_in);
	if (!pipe_error)
		close(pipe_fd->in);
	if (pipe_error)
		return (1);
	waitpid(last_pid, &stat_loc, 0);
	while (wait(NULL) >= 0)
		;
	if (WIFEXITED(stat_loc))
		return (WEXITSTATUS(stat_loc));
	else if (WIFSIGNALED(stat_loc))
		return (WTERMSIG(stat_loc) + 128);
	else
		return (1);
}

int	pipex(t_exec *args, bool here_doc)
{
	t_pipex_fd	pipe_fd;
	pid_t		last_pid;

	if (init_pipex(&pipe_fd, args->av[0], here_doc) == 1)
		return (1);
	last_pid = pipex_fork(&pipe_fd, args, here_doc);
	if (last_pid == -1)
		return (exit_pipex(&pipe_fd, last_pid, true));
	return (exit_pipex(&pipe_fd, last_pid, false));
}
