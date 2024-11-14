/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:26:54 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 07:38:59 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <unistd.h>

static void	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n > -10)
			putchar_fd('0' - n, fd);
		else
		{
			ft_putnbr_fd(-(n / 10), fd);
			putchar_fd('0' - (n % 10), fd);
		}
	}
	else
	{
		if (n < 10)
			putchar_fd('0' + n, fd);
		else
		{
			ft_putnbr_fd(n / 10, fd);
			putchar_fd('0' + (n % 10), fd);
		}
	}
}

// int	main(int ac, char **av)
// {
// 	int	fd;

// 	if (ac > 2)
// 	{
// 		fd = open(av[2], O_WRONLY);
// 		ft_putnbr_fd(ft_atoi(av[1]), fd);
// 		close(fd);
// 	}
// }
