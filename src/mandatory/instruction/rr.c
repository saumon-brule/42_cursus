/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:48:32 by ebini             #+#    #+#             */
/*   Updated: 2025/03/06 02:20:35 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

static void	rr(t_ivector *stack)
{
	const int	tmp = ivec_get(stack, -1);

	ft_memmove(stack->data, stack->data + 1, (stack->len - 1) * sizeof(int));
	stack->data[0] = tmp;
}

void	rra(t_ivector *stack_a)
{
	rr(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_ivector *stack_b)
{
	rr(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_ivector *stack_a, t_ivector *stack_b)
{
	rr(stack_a);
	rr(stack_b);
	ft_printf("rrr\n");
}
