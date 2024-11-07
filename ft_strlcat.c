/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:12:15 by ebini             #+#    #+#             */
/*   Updated: 2024/11/07 12:27:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	c;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	i = 0;
	c = dstlen;
	if (size <= dstlen)
		return (srclen + size);
	while (src[i] && i < size - dstlen - 1)
	{
		dest[c] = src[i];
		c++;
		i++;
	}
	dest[c] = '\0';
	return (dstlen + srclen);
}
