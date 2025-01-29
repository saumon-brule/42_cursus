/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:04:31 by ebini             #+#    #+#             */
/*   Updated: 2025/01/28 06:23:52 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

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

char	*parse_command(char *cmd, char *path)
{
	char	**folders;
	char	*file_path;
	size_t	i;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	if (!path)
		return (NULL);
	i = 0;
	folders = ft_split(path, ':');
	while (folders[i])
	{
		file_path = strjoinall(3, folders[i], "/", cmd);
		if (!access(file_path, F_OK))
		{
			free_split(folders);
			return (file_path);
		}
		free(file_path);
		++i;
	}
	return (NULL);
}

bool	is_escaped(char *s, size_t pos)
{
	bool	escaped;

	escaped = false;
	while (pos && s[--pos] == '\\')
		escaped = !escaped;
	return (escaped);
}
