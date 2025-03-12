/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:09:22 by ebini             #+#    #+#             */
/*   Updated: 2025/03/12 13:24:52 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"

int	find_command(char **folders, char *cmd, char **result)
{
	int		status;

	status = 0;
	while (*folders)
	{
		*result = strjoinall(3, *folders, "/", cmd);
		if (!*result)
		{
			perror("pipex");
			return (1);
		}
		if (access(*result, F_OK))
			status = 127 - (status == 126);
		else if (access(*result, X_OK))
			status = 126;
		else
			return (0);
		free(*result);
		++folders;
	}
	if (status == 126)
		ft_dprintf(2, "pipex: permission denied: %s\n", cmd);
	else if (status == 127)
		ft_dprintf(2, "pipex: command not found: %s\n", cmd);
	return (status);
}

int	handle_path(char *cmd, char **result)
{
	int	status;

	status = 0;
	if (access(cmd, F_OK))
	{
		ft_dprintf(2, "pipex: command not found: %s\n", cmd);
		status = 127;
	}
	else if (access(cmd, X_OK))
	{
		ft_dprintf(2, "pipex: permission denied: %s\n", cmd);
		status = 126;
	}
	if (!status)
		*result = ft_strdup(cmd);
	return (status);
}

int	parse_command(char *cmd, char *path, char **result)
{
	char	**folders;
	int		status;

	if (ft_strchr(cmd, '/'))
		return (handle_path(cmd, result));
	if (!path)
		return (1);
	folders = ft_split(path, ':');
	if (!folders)
		return (1);
	status = find_command(folders, cmd, result);
	free_split(folders);
	return (status);
}
