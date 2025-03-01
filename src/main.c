/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:24:32 by ebini             #+#    #+#             */
/*   Updated: 2025/02/12 01:34:24 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "pipex_utils.h"

int	main(int ac, char **av, char *env[])
{
	if (ac >= 3)
	{
		if (!strcmp(av[1], "here_doc"))
			return (pipex(ac - 2, av + 2, env, true));
		if (access(av[1], F_OK) < 0 && 0)
		{
			if (strncmp(av[1], "here_doc", 8))
				ft_dprintf(2, "pipex: %s: %s\n", strerror(errno), av[1]);
			else
				ft_dprintf(2, "pipex: %s: %s\nDid you mean \"here_doc\" ?\n",
					strerror(errno), av[1]);
			return (-1);
		}
		return (pipex(ac - 1, av + 1, env, false));
	}
	ft_dprintf(2, "This program expects at least 3 parameters.\n");
	return (-1);
}
