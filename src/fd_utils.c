/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:54:08 by ebini             #+#    #+#             */
/*   Updated: 2025/02/06 19:02:15 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	swap_fd(int pipe_fd[3])
{
	close(pipe_fd[2]);
	if (pipe_fd[0] >= 0)
		close(pipe_fd[0]);
	pipe_fd[0] = pipe_fd[1];
	return (pipe(pipe_fd + 1));
}

int	change_fd(int old, int new)
{
	if (dup2(new, old) == -1)
	{
		perror("pipex");
		close(new);
		return (-1);
	}
	close(new);
	return (0);
}
