/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:52:32 by ebini             #+#    #+#             */
/*   Updated: 2024/11/09 14:26:18 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	malloc_size;
	char	*result;

	malloc_size = nmemb * size;
	result = malloc(malloc_size);
	if (!result)
		return (result);
	while (malloc_size--)
	{
		result[malloc_size] = 0;
	}
	return (result);
}

// int	main(void)
// {
// 	int	*a;

// 	a = ft_calloc(69000, 4);
// 	printf("%p\n", a);
// 	free(a);
// 	a = calloc(69000, 4);
// 	printf("%p\n", a);
// 	free(a);
// }
