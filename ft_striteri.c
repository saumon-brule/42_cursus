/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:44:26 by ebini             #+#    #+#             */
/*   Updated: 2024/11/13 04:53:04 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}

// void	test(unsigned int i, char *c)
// {
// 	(void)i;
// 	*c = 'm' - (*c - 'n');
// }

// int	main(int ac, char **av)
// {
// 	if (ac > 1)
// 	{
// 		ft_striteri(av[1], &test);
// 		printf("%s\n", av[1]);
// 	}
// }
