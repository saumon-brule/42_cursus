/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:52:32 by ebini             #+#    #+#             */
/*   Updated: 2024/11/13 17:23:09 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

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

// int	main(void)
// {
// 	int	*a;

// 	a = ft_calloc(2147483648, 2);
// 	printf("%s\n", (char*)a);
// 	free(a);
// 	a = calloc(2147483648, 2);
// 	printf("%s\n", (char*)a);
// 	printf("%p\n", malloc(0));
// 	free(a);
// }
