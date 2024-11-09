/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:35:50 by ebini             #+#    #+#             */
/*   Updated: 2024/11/08 02:06:40 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	av = av + 1;
// 	av = av - 1;
// 	if (ac >= 4)
// 	{
// 		printf("abc\375xx = %d:%d\n", ft_strncmp("abcdef", "abc\375xx", 5),
// 			strncmp("abcdef", "abc\375xx", 5));
// 		return (0);
// 	}
// 	else
// 	{
// 		printf("Not enough parameters, %d (3 needed)", ac - 1);
// 		return (0);
// 	}
// }
