/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_children.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:21:27 by ebini             #+#    #+#             */
/*   Updated: 2025/02/06 18:46:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "libft.h"
#include "pipex_utils.h"

void	child_process(int pipe_fd[3], char *command, char **env)
{
	int		returned_value;

	close(pipe_fd[1]);
	if (pipe_fd[0] == -1)
	{
		close(pipe_fd[2]);
		exit(1);
	}
	if (change_fd(0, pipe_fd[0]) == -1)
		exit(1);
	if (change_fd(1, pipe_fd[2]) == -1)
		exit(1);
	returned_value = exec_shell(command, env);
	close(pipe_fd[2]);
	close(pipe_fd[0]);
	if (returned_value != 0)
	{
		if (returned_value == -1)
			ft_dprintf(2, "pipex: %s: %s\n", strerror(errno), command);
		exit(returned_value);
	}
}
