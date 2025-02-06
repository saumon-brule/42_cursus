/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:54:08 by ebini             #+#    #+#             */
/*   Updated: 2025/01/31 13:08:16 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "pipex_utils.h"

int	swap_fd(int pipe_fd[3])
{
	close(pipe_fd[2]);
	if (pipe_fd[0] >= 0)
		close(pipe_fd[0]);
	pipe_fd[0] = pipe_fd[1];
	return (pipe(pipe_fd + 1));
}

void	free_cmd(t_sh_cmd *cmd)
{
	free_split(cmd->arguments);
	free(cmd->path);
}
