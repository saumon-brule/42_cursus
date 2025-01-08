/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:02:01 by ebini             #+#    #+#             */
/*   Updated: 2025/01/08 13:27:13 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *src, const void *dest, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	int	a[5] = {1, 2, 3, 4, 5};
// 	int	b[5];

// 	printf("%d:%d:%d:%d:%d\n", a[0], a[1], a[2], a[3], a[4]);
// 	printf("%d:%d:%d:%d:%d\n", b[0], b[1], b[2], b[3], b[4]);
// 	ft_memcpy((char *)0, (char *)0, 5 * 4);
// 	printf("%d:%d:%d:%d:%d\n", a[0], a[1], a[2], a[3], a[4]);
// 	printf("%d:%d:%d:%d:%d\n", b[0], b[1], b[2], b[3], b[4]);
// }
