/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:03:16 by ebini             #+#    #+#             */
/*   Updated: 2025/01/17 00:57:56 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

char	*parse_command(char *cmd, char *path)
{
	char	**folders;
	char	*file_path;
	size_t	i;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	i = 0;
	folders = ft_split(path, ':');
	while (folders[i])
	{
		file_path = strjoinall(3, folders[i], "/", cmd);
		if (!access(file_path, F_OK))
			return (file_path);
		free(file_path);
		++i;
	}
	return (NULL);
}
