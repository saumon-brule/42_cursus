/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:50:25 by aviscogl          #+#    #+#             */
/*   Updated: 2025/02/19 14:50:25 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

#include "libft.h"
#include "so_long.h"
#include "clean.h"

int	main(int ac, char **av)
{
	t_game	*game;
	int		parse_result;

	if (ac > 1)
	{
		if (init_game(ac, av, &game))
			return (EXIT_FAILURE);
		parse_result = parse_map(game, av[1]);
		if (parse_result)
		{
			if (parse_result > 0)
				ft_dprintf(2, "[\033[91mPARSING ERROR\033[0m] - %s\n",
					get_map_errors(parse_result));
			return (clean(game, STATE_PARSE));
		}
		if (setup_game(game))
			return (EXIT_FAILURE);
		ft_printf("%d\n", game->settings->debug_enabled);
		mlx_loop(game->mlx);
	}
	ft_dprintf(2, "Invalid number of parameters\n");
	return (EXIT_FAILURE);
}
