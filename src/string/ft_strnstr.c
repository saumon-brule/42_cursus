/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:28:57 by ebini             #+#    #+#             */
/*   Updated: 2025/01/11 16:20:59 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*strnrchr(const char *s, int c, size_t n)
{
	while ((int)(--n) > -1)
		if (s[n] == (char)c)
			return ((char *)s + n);
	return (NULL);
}

/**Boyer Moore algorithm (not horsepool version meaning, the position of a
 * character in little is recalculated each time)*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lil_size;
	char	*last_position;
	char	*little_end;
	int		offset;

	len = min(len, ft_strlen(big));
	lil_size = ft_strlen(little);
	little_end = (char *)little + lil_size - 1;
	while (len >= lil_size)
	{
		if (!ft_strncmp((char *)big, (char *)little, lil_size))
			return ((char *)big);
		last_position = strnrchr(little, big[lil_size - 1], lil_size - 1);
		if (!last_position)
			offset = lil_size;
		else
			offset = lil_size - (last_position - little) - 1;
		big += offset;
		len -= offset;
	}
	return (NULL);
}
