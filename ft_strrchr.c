/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:18:22 by ebini             #+#    #+#             */
/*   Updated: 2024/11/07 21:00:47 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) + 1;
	while (--i > -1)
		if (s[i] == (char)c)
			return ((char *)s + i);
	return (NULL);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	char	*result;

// 	if (ac >= 3)
// 		result = ft_strrchr(av[1], '\0');
// 	else
// 	{
// 		printf("Not enough parameters\n");
// 		return (1);
// 	}
// 	if (result)
// 		printf("%s\n", result);
// 	else
// 		printf("no \'%x\' in \"%s\"\n", '\0', av[1]);
// }
