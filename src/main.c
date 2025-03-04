/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:30:31 by ebini            #+#    #+#             */
/*   Updated: 2025/03/04 08:45:59 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "vector.h"

int	main(int ac, char **av)
{
	t_ivector	stack_a;
	t_ivector	stack_b;

	if (parse_input(ac, av, &stack_a))
	{
		ft_dprintf(2, "Error\n");
		return (1);
	}
	ivec_init(&stack_b, NULL, stack_a.len);
	ivec_print(1, &stack_a);
	ivec_print(1, &stack_b);
	ivec_clear(&stack_a);
	ivec_clear(&stack_b);
}
