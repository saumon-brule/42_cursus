/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:24:32 by ebini             #+#    #+#             */
/*   Updated: 2025/01/17 14:36:29 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include "libft.h"
#include "pipex_utils.h"

int	main(int ac, char **av, char *env[])
{
	if (ac == 5)
	{
		if (!strncmp(av[1], "here_doc", 8))
			return ((ac, av, env));
		if (access(av[1], F_OK) < 0)
		{
			ft_fprintf(2, "pipex: %s: \"%s\"\n", strerror(errno), av[1]);
			return (2);
		}
	}
	else if (ac == 6)
	{

	}
	else
	{
		ft_fprintf(2, "This program expects 4 or 5 parameters.\n");
		return (1);
	}
}
