/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:24:32 by ebini             #+#    #+#             */
/*   Updated: 2025/01/28 15:24:11 by ebini            ###   ########lyon.fr   */
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
	if (ac >= 3)
	{
		if (*(av[ac - 1]) && access(av[ac - 1], F_OK) == 0
			&& access(av[ac - 1], W_OK) != 0)
		{
			ft_dprintf(2, "%s: %s: \"%s\"\n",
				av[0], strerror(errno), av[ac - 1]);
			return (3);
		}
		if (!strcmp(av[1], "here_doc"))
			return (pipex(ac - 2, av + 2, env, true));
		if (access(av[1], F_OK) < 0)
		{
			if (strncmp(av[1], "here_doc", 8))
				ft_dprintf(2, "%s: %s: \"%s\"\n",
					av[0], strerror(errno), av[1]);
			else
				ft_dprintf(2, "%s: %s: \"%s\"\nDid you mean \"here_doc\" ?\n",
					av[0], strerror(errno), av[1]);
			return (2);
		}
		return (pipex(ac - 1, av + 1, env, false));
	}
	ft_dprintf(2, "This program expects at least 3 parameters.\n");
	return (1);
}
