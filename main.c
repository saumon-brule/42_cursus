/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 01:24:32 by ebini             #+#    #+#             */
/*   Updated: 2025/01/14 01:38:18 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "libft.h"

int	main(int ac, char **av, char *env[])
{
	(void)av;
	(void)env;
	if (ac == 4)
	{
		
		return (0);
	}
	else
	{
		ft_printf("This program expects 4 parameters.");
		return (1);
	}
}
