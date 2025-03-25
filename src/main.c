/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:24:32 by ebini             #+#    #+#             */
/*   Updated: 2025/03/25 14:34:43 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "pipex_utils.h"

int	main(int ac, char **av, char *env[])
{
	if (ac > 3)
	{
		if (!ft_strcmp(av[1], "here_doc"))
			return (pipex(ac - 2, av + 2, env, true));
		return (pipex(ac - 1, av + 1, env, false));
	}
	ft_dprintf(2, "This program expects at least 3 parameters.\n");
	return (-1);
}
