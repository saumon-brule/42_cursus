/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:28:32 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 07:47:14 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*mapped_str;

	mapped_str = malloc(ft_strlen(s) + 1);
	if (!mapped_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapped_str[i] = (*f)(i, s[i]);
		i++;
	}
	mapped_str[i] = '\0';
	return (mapped_str);
}

// char	test(unsigned int i, char c)
// {
// 	return (c + 1 - i + i);
// }

// int	main(int ac, char **av)
// {
// 	char	*result;

// 	if (ac > 1)
// 	{
// 		result = ft_strmapi(av[1], &test);
// 		printf("\"%s\" => \"%s\"", av[1], result);
// 		free(result);
// 	}
// }
