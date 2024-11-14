/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 04:53:48 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 07:39:37 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	s_size;

	s_size = ft_strlen(s);
	write(fd, s, s_size);
}

// int	main(int ac, char **av)
// {
// 	int	fd;

// 	if (ac > 2)
// 	{
// 		fd = open(av[2], O_WRONLY);
// 		ft_putstr_fd(av[1], fd);
// 		close(fd);
// 	}
// }
