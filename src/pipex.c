/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:51:33 by ebini             #+#    #+#             */
/*   Updated: 2025/03/10 18:18:26 by ebini            ###   ########lyon.fr   */
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

int	get_output(char *file, bool here_doc)
{
	int	result;

	if (here_doc)
		result = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		result = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (result == -1)
		ft_dprintf(2, "pipex: %s: %s\n", strerror(errno), file);
	return (result);
}

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

int	init_pipex(t_pipex_fd **pipe_fd, char *param, bool here_doc)
{
	int	tmp_fd[2];

	*pipe_fd = malloc(sizeof(t_pipex_fd));
	if (!*pipe_fd)
	{
		perror("pipex");
		return (1);
	}
	(*pipe_fd)->out = init_input(param, here_doc);
	if ((*pipe_fd)->out == -1)
	{
		free(*pipe_fd);
		return (1);
	}
	if (pipe(tmp_fd) == -1)
	{
		perror("pipex");
		close((*pipe_fd)->out);
		free(*pipe_fd);
		return (1);
	}
	(*pipe_fd)->in = tmp_fd[1];
	(*pipe_fd)->next_out = tmp_fd[0];
	return (0);
}

int	exit_pipex(t_pipex_fd *pipe_fd, pid_t last_pid, bool pipe_error)
{
	int	stat_loc;

	close(pipe_fd->in);
	close(pipe_fd->next_out);
	close(pipe_fd->last_out);
	if (!pipe_error)
		close(pipe_fd->out);
	free(pipe_fd);
	if (pipe_error)
		return (1);
	waitpid(last_pid, &stat_loc, 0);
	while (wait(NULL) >= 0)
		;
	if (WIFEXITED(stat_loc))
		return (WEXITSTATUS(stat_loc));
	else if (WIFSIGNALED(stat_loc))
		return (WTERMSIG(stat_loc) + 128);
	else if (WIFSTOPPED(stat_loc))
		return (WSTOPSIG(stat_loc));
	else
		return (1);
}

int	pipex(int pc, char **pv, char **env, bool here_doc)
{
	t_pipex_fd	*pipe_fd;
	pid_t		last_pid;
	int			i;

	if (init_pipex(&pipe_fd, pv[0], here_doc) == 1)
		return (1);
	pipe_fd->last_out = get_output(pv[pc - 1], here_doc);
	i = 0;
	last_pid = pipex_fork(pipe_fd, pc, pv, env);
	if (last_pid == -1)
		return (exit_pipex(pipe_fd, last_pid, true));
	return (exit_pipex(pipe_fd, last_pid, false));
}
