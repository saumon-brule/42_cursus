/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:02:16 by ebini             #+#    #+#             */
/*   Updated: 2024/11/07 20:54:12 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strchr(const char *s, int c)
{
	s--;
	while (*++s)
		if (*s == (char)c)
			return (((char *)s));
	if ((char)c == '\0')
		return (((char *)s));
	return (NULL);
}

// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	char	*result;

// 	if (ac >= 3)
// 		result = ft_strchr(av[1], av[2][0]);
// 	else
// 	{
// 		printf("Not enough parameters\n");
// 		return (1);
// 	}
// 	if (result)
// 		printf("%s\n", result);
// 	else
// 		printf("no \'%c\' in \"%s\"\n", av[2][0], av[1]);
// }
