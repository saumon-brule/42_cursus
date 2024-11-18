/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:49:14 by ebini             #+#    #+#             */
/*   Updated: 2024/11/18 23:51:57 by ebini            ###   ########lyon.fr   */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	malloc_size;
	char	*result;

	if (size != 0 && nmemb > (__SIZE_MAX__ / size))
		return (NULL);
	malloc_size = nmemb * size;
	result = malloc(malloc_size);
	if (!result)
		return (NULL);
	while (malloc_size--)
		result[malloc_size] = 0;
	return (result);
}
