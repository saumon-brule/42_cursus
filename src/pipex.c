/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:51:33 by ebini             #+#    #+#             */
/*   Updated: 2025/02/06 19:13:35 by ebini            ###   ########lyon.fr   */
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

char	*init_input(int pipe_fd[3], char *param, bool here_doc)
{
	char	*input_file;

	input_file = param;
	if (here_doc)
	{
		input_file = tmp_here_doc(param);
		if (!input_file)
			return (NULL);
	}
	pipe_fd[0] = open(input_file, O_RDONLY);
	if (pipe_fd[0] == -1)
	{
		if (here_doc)
		{
			perror("pipex");
			free(input_file);
			return (NULL);
		}
		ft_dprintf(2, "pipex: %s: %s\n", strerror(errno), param);
	}
	return (input_file);
}

char	*init_pipex(int pipe_fd[3], char *param, bool here_doc)
{
	char	*input_file;

	input_file = init_input(pipe_fd, param, here_doc);
	if (!input_file)
		return (NULL);
	if (pipe(pipe_fd + 1) == -1)
	{
		perror("pipex");
		if (here_doc)
			free(input_file);
		return (NULL);
	}
	return (input_file);
}

int	exit_pipex(char *input_file, bool here_doc, pid_t last_pid)
{
	int	stat_loc;

	if (here_doc)
	{
		unlink(input_file);
		free(input_file);
	}
	(void)stat_loc;
	(void)last_pid;
	waitpid(last_pid, &stat_loc, 0);
	while (wait(NULL) >= 0)
		;
	if (WIFEXITED(stat_loc))
		return (WEXITSTATUS(stat_loc));
	else if (WIFSIGNALED(stat_loc))
		return (WTERMSIG(stat_loc));
	else if (WIFSTOPPED(stat_loc))
		return (WSTOPSIG(stat_loc));
	else
		return (-1);
}

pid_t	pipex(int pc, char **pv, char **env, bool here_doc)
{
	const int	fd_out = get_output(pv[pc - 1], here_doc);
	int			pipe_fd[3];
	pid_t		last_pid;
	char		*input_file;
	int			i;

	input_file = init_pipex(pipe_fd, pv[0], here_doc);
	if (here_doc && !input_file)
		return (-1);
	i = 0;
	while (++i < pc - 1)
	{
		last_pid = fork();
		if (!last_pid)
		{
			if (i == pc - 2)
				pipe_fd[2] = fd_out;
			else
				close(fd_out);
			child_process(pipe_fd, pv[i], env);
		}
		else
			swap_fd(pipe_fd);
	}
	return (exit_pipex(input_file, here_doc, last_pid));
}
