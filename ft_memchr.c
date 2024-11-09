/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:02:43 by ebini             #+#    #+#             */
/*   Updated: 2024/11/07 21:11:23 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
	return (NULL);
}

// int	main(void)
// {
// 	char	c[] = {'a', 'b', 'c', 'q', 'O', '5', '\0'};

// 	printf("%s\n", (char *)ft_memchr(c, 'O', 8));
// }
