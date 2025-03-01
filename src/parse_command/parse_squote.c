/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_squote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:30:32 by ebini             #+#    #+#             */
/*   Updated: 2025/03/01 12:26:52 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*parse_squote(char **s)
{
	size_t	arg_size;
	char	*result;

	++*s;
	arg_size = 0;
	while ((*s)[arg_size] != '\'' && (*s)[arg_size])
		++arg_size;
	result = ft_strndup(*s, arg_size);
	ft_dprintf(2, "%s\n", result);
	if (!result)
		return (NULL);
	*s += arg_size;
	if (**(s))
		++*s;
	return (result);
}
