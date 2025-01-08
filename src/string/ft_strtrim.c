/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:48:42 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 07:51:49 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

static char	*strrchr_len(const char *s, int c, size_t len)
{
	while (--len + 1)
		if (s[len] == (char)c)
			return ((char *)s + len);
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	result_len;
	size_t	i;

	while (*s1 && ft_strchr(set, *s1))
		s1++;
	result_len = ft_strlen(s1);
	if (result_len)
		while (strrchr_len(set, s1[result_len - 1], ft_strlen(set)))
			result_len--;
	result = malloc(result_len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < result_len)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

// int	main(int ac, char **av)
// {
// 	size_t	i;
// 	char	*result;
// 	char	*current_string;
// 	char	*current_set;
// 	char	*test_strings[12] = {
// 		"  aba",
// 		" ",
// 		"aba  ",
// 		" ",
// 		"  aba ",
// 		"   4897  ",
// 		"",
// 		"GAAA",
// 		"TEST",
// 		"",
// 		"",
// 		""
// 		};

// 	if (ac > 2)
// 	{
// 		i = -1;
// 		while (++i < ((size_t)ac - 1) / 2)
// 		{
// 			current_string = av[i * 2 + 1];
// 			current_set = av[i * 2 + 2];
// 			result = ft_strtrim(current_string, current_set);
// 			printf("%s\n", result);
// 			free(result);
// 		}
// 	}
// 	else
// 	{
// 		i = -1;
// 		while (++i < 6)
// 		{
// 			current_string = test_strings[i * 2];
// 			current_set = test_strings[i * 2 + 1];
// 			result = ft_strtrim(current_string, current_set);
// 			printf("string : \"%s\"\nset : \"%s\"\nresult : \"%s\"\n",
// 					current_string, current_set, result);
// 			free(result);
// 		}
// 	}
// 	return (0);
// }
