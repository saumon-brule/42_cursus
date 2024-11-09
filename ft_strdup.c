/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:18:34 by ebini             #+#    #+#             */
/*   Updated: 2024/11/09 14:42:16 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*o;

	o = malloc(ft_strlen(s) + 1);
	if (!o)
		return (NULL);
	i = -1;
	while (s[++i])
		o[i] = s[i];
	o[i] = 0;
	return (o);
}

// int	main(int ac, char **av)
// {
// 	char	*a;

// 	if (ac > 1)
// 	{
// 		a = ft_strdup(av[1]);
// 		printf("%s", a);
// 		free(a);
// 	}
// }
