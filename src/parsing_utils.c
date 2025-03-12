/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 22:04:31 by ebini             #+#    #+#             */
/*   Updated: 2025/03/10 20:17:47 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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

bool	is_escaped(char *s, size_t pos)
{
	bool	escaped;

	escaped = false;
	while (pos && s[--pos] == '\\')
		escaped = !escaped;
	return (escaped);
}
