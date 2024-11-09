/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:36:25 by ebini             #+#    #+#             */
/*   Updated: 2024/11/07 23:36:43 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while ((--n) + 1 >= (size_t)(1))
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		i = -1;
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}

// int	main(void)
// {
// 	char	*src = "this is a good nyancat !\r\n";
// 	char	dst1[0xF0];
// 	char	dst2[0xF0];
// 	int		size;

// 	size = strlen(src);
// 	memmove(dst1, src, size);
//     ft_memmove(dst2, src, size);
// 	printf("%s\n", dst1);
// 	printf("%s\n", dst2);
// }
