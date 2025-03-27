/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_children.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:21:27 by ebini             #+#    #+#             */
/*   Updated: 2025/03/27 15:56:31 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

void	exit_child(t_pipex_fd *pipe_fd, int exit_code)
{
	if (pipe_fd->in > -1)
		close(pipe_fd->in);
	if (pipe_fd->out > -1)
		close(pipe_fd->out);
	free(pipe_fd);
	exit(exit_code);
}

// void	child_process(t_pipex_fd *pipe_fd, char *command, char **env)
void	child_process(t_pipex_fd *pipe_fd, t_exec *args, int index,
		bool here_doc)
{
	int	status;

	close(pipe_fd->next_in);
	if (index == args->ac - 2)
	{
		close(pipe_fd->out);
		pipe_fd->out = get_output(args->av[args->ac - 1], here_doc);
	}
	if (pipe_fd->out == -1)
		exit_child(pipe_fd, 1);
	if (change_fd(pipe_fd->in, STDIN_FILENO) == -1)
		exit_child(pipe_fd, 1);
	if (change_fd(pipe_fd->out, STDOUT_FILENO) == -1)
		exit_child(pipe_fd, 1);
	status = exec_shell(args->av[index], args->env);
	close(pipe_fd->out);
	close(pipe_fd->in);
	free(pipe_fd);
	exit(status);
}

int	pipex_fork(t_pipex_fd *pipe_fd, t_exec *args, bool here_doc)
{
	int		i;
	pid_t	pid;

	pid = -1;
	i = 0;
	while (++i < args->ac - 1)
	{
		if (pipe_fd->in > -1)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("pipex");
				return (-1);
			}
			if (pid == 0)
				child_process(pipe_fd, args, i, here_doc);
			else if (swap_fd(pipe_fd, i == args->ac - 2) == -1)
				return (-1);
		}
		else if (swap_fd(pipe_fd, i == args->ac - 2) == -1)
			return (-1);
	}
	return (pid);
}
