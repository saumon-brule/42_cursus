/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:04:31 by ebini             #+#    #+#             */
/*   Updated: 2025/03/01 15:56:38 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "libft.h"

char	*get_from_env(char *var, char **env)
{
	char			*var_pos;
	const size_t	var_len = ft_strlen(var);

	while (*env)
	{
		var_pos = ft_strstr(*env, var);
		if (var_pos == *env && (*env)[var_len] == '=')
			return (var_pos + var_len + 1);
		++env;
	}
	return ("");
}

int	find_command(char **folders, char *cmd, char **result)
{
	size_t	i;

	if (!ft_strlen(cmd))
	{
		ft_dprintf(2, "pipex: permission denied: %s\n", cmd);
		return (126);
	}
	i = -1;
	while (folders[++i])
	{
		*result = strjoinall(3, folders[i], "/", cmd);
		if (!*result)
		{
			perror("pipex");
			return (1);
		}
		if (!access(*result, X_OK | F_OK))
			return (0);
		free(*result);
	}
	ft_dprintf(2, "pipex: command not found: %s\n", cmd);
	return (127);
}

int	parse_command(char *cmd, char *path, char **result)
{
	char	**folders;
	int		status;

	if (ft_strchr(cmd, '/'))
	{
		*result = ft_strdup(cmd);
		return (0);
	}
	if (!path)
		return (1);
	folders = ft_split(path, ':');
	if (!folders)
		return (1);
	status = find_command(folders, cmd, result);
	free_split(folders);
	return (status);
}

bool	is_escaped(char *s, size_t pos)
{
	bool	escaped;

	escaped = false;
	while (pos && s[--pos] == '\\')
		escaped = !escaped;
	return (escaped);
}
