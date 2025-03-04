/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:46:47 by ebini             #+#    #+#             */
/*   Updated: 2025/03/04 18:13:22 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "push_swap.h"

int	parse_input(int ac, char **av, t_ivector *vector)
{
	int	i;

	i = 0;
	while (++i < ac)
		if (!is_number(av[i]) || !is_int(av[i]))
			return (1);
	ivec_init(vector, NULL, ac - 1);
	i = 0;
	while (++i < ac)
		ivec_push(vector, ft_atoi(av[i]));
	return (0);
}
