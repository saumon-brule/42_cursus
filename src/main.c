/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:24:32 by ebini             #+#    #+#             */
/*   Updated: 2025/03/25 14:59:58 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <errno.h>

#include "pipex_utils.h"

int	main(int ac, char **av, char *env[])
{
	t_exec	args;

	if (ac > 3)
	{
		if (!ft_strcmp(av[1], "here_doc"))
		{
			args.ac = ac - 2;
			args.av = av + 2;
			args.env = env;
			return (pipex(&args, true));
		}
		args.ac = ac - 1;
		args.av = av + 1;
		args.env = env;
		return (pipex(&args, false));
	}
	ft_dprintf(2, "This program expects at least 3 parameters.\n");
	return (-1);
}
