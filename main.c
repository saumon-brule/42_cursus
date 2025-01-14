/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:24:32 by ebini             #+#    #+#             */
/*   Updated: 2025/01/14 02:44:56 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	main(int ac, char **av, char *env[])
{
	char	*strtmp;

	(void)env;
	if (ac == 5)
	{
		if (access(av[1], F_OK))
		{
			strtmp = strjoinfr(ft_strjoin("\"", av[1]), "\"", true, false);
			perror(strtmp);
			free(strtmp);
			return (1);
		}
		return (0);
	}
	else
	{
		ft_printf("This program expects 4 parameters.\n");
		return (1);
	}
}
