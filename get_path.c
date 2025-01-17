/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:37:28 by ebini             #+#    #+#             */
/*   Updated: 2025/01/16 18:46:50 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_path(char **env)
{
	char	*path_pos;

	while (*env)
	{
		path_pos = ft_strstr(*env, "PATH=");
		if (path_pos == *env)
			return (path_pos + 5);
		++env;
	}
	return (NULL);
}
