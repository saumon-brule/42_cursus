/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:19:33 by ebini             #+#    #+#             */
/*   Updated: 2024/11/13 16:42:41 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	s_size;

	s_size = ft_strlen(s);
	write(fd, s, s_size);
	write(fd, "\n", 1);
}

// int	main(int ac, char **av)
// {
// 	int	fd;

// 	if (ac > 2)
// 	{
// 		fd = open(av[2], O_WRONLY);
// 		ft_putendl_fd(av[1], fd);
// 		close(fd);
// 	}
// }
