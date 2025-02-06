/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 23:25:03 by ebini             #+#    #+#             */
/*   Updated: 2025/02/06 19:04:34 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_utils.h"

size_t	var_name_len(char *s)
{
	size_t	i;

	i = 0;
	while (is_var_name(s[i]))
		++i;
	return (i);
}

size_t	var_len(char *s)
{
	bool	is_isolated;

	is_isolated = *(s + 1) == '{';
	return (var_name_len(s + 1 + is_isolated) + 1 + is_isolated * 2);
}
