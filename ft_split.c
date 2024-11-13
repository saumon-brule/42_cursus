/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:15:30 by ebini             #+#    #+#             */
/*   Updated: 2024/11/13 18:32:26 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	count_split_len(char const *s, char c)
{
	size_t	count;

	count = *s && *s != c;
	while (*++s)
		if (*s != c && *(s - 1) == c)
			count++;
	return (count);
}

static size_t	strlenchr(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

/**will create a new string from the original s
 * with at most n characters (without null) in it
 * This function is only used by split this is why
 * it is not secure and it will not handle size
 * bigger than the original*/
static char	*split_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*result;

	result = malloc(n + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static void	nested_free(char **ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**splitted_str;
	size_t	substr_idx;
	size_t	substr_len;

	splitted_str = ft_calloc(count_split_len(s, c) + 1, sizeof(char *));
	if (!splitted_str)
		return (NULL);
	substr_idx = 0;
	while (*s)
	{
		if (*s != c)
		{
			substr_len = strlenchr(s, c);
			splitted_str[substr_idx++] = split_strndup(s, substr_len);
			if (!splitted_str[substr_idx - 1])
			{
				nested_free(splitted_str, substr_idx - 1);
				return (NULL);
			}
			s += substr_len;
		}
		else
			s++;
	}
	return (splitted_str);
}

// int	main(int ac, char **av)
// {
// 	char	**result;
// 	size_t	i;

// 	(void)av;
// 	if (ac > 2)
// 	{
// 		// result = ft_split(av[1], av[2][0]);
// 		result = ft_split("123456789q123456789", '\0');
// 		i = 0;
// 		while (result[i])
// 		{
// 			printf("%p : \"%s\"\n", result[i], result[i]);
// 			free(result[i++]);
// 		}
// 		free(result);
// 	}
// 	return (0);
// }
