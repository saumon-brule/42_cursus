/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:51:33 by ebini             #+#    #+#             */
/*   Updated: 2025/01/28 15:31:43 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include "libft.h"
#include "pipex_utils.h"
#include <errno.h>

void	init_pipex(int pipe_fd[3], char *first_param, bool here_doc)
{
	pipe_fd[0] = -1;
	pipe(pipe_fd + 1);
	if (here_doc)
		ft_dprintf(pipe_fd[2], "%s", first_param);
	else
		write_file_fd(first_param, pipe_fd[2]);
}

void	child_proc(int pipe_fd[3], char *command, char **env)
{
	int		returned_value;

	if (dup2(pipe_fd[0], 0) == -1)
	{
		perror("pipex");
		exit(-1);
	}
	if (dup2(pipe_fd[2], 1) == -1)
	{
		perror("pipex");
		exit(-1);
	}
	returned_value = exec_shell(command, env);
	close(pipe_fd[2]);
	if (returned_value < 0)
	{
		ft_dprintf(2, "pipex: %s: \"%s\"\n", strerror(errno), command);
		exit(-1);
	}
}

int	pipex(int pc, char **pv, char **env, bool here_doc)
{
	const int	fd_out = get_fd(pv[pc - 1], here_doc);
	int			pipe_fd[3];
	int			i;
	pid_t		last_pid;

	init_pipex(pipe_fd, pv[0], here_doc);
	i = 0;
	while (++i < pc - 1)
	{
		if (i == pc - 2)
			pipe_fd[2] = fd_out;
		last_pid = fork();
		if (!last_pid)
			child_proc(pipe_fd, pv[i], env);
		else
			swap_fd(pipe_fd);
	}
	waitpid(last_pid, NULL, 0);
	return (0);
}
