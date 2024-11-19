/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:14 by ebini             #+#    #+#             */
/*   Updated: 2024/11/19 02:06:59 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return ((size_t)0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strnlen_nl(const char *s, size_t n)
{
	size_t	i;

	if (!s)
		return ((size_t)0);
	i = 0;
	while (i < n && s[i] != '\n')
		i++;
	i += i < n && s[i] == '\n';
	return (i);
}
