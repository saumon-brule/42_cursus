/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:34:33 by ebini             #+#    #+#             */
/*   Updated: 2024/11/07 13:01:21 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

// int	main(int ac, char **av)
// {
// 	int	av_len;
// 	int	i;

// 	av_len = ft_strlen(av[1]);
// 	i = -1;
// 	while (++i < av_len)
// 		av[1][i] = ft_toupper(av[1][i]);
// 	printf("%s\n", av[1]);
// 	return (0);
// }
