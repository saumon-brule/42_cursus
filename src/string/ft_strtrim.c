/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:48:42 by ebini             #+#    #+#             */
/*   Updated: 2025/01/11 17:20:08 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*strrchr_len(const char *s, int c, size_t len)
{
	while (--len + 1)
		if (s[len] == (char)c)
			return ((char *)s + len);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	result_len;
	size_t	i;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	result_len = ft_strlen(s1);
	if (result_len)
		while (strrchr_len(set, s1[result_len - 1], ft_strlen(set)))
			result_len--;
	result = malloc(result_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < result_len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
