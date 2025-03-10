/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:48:32 by ebini             #+#    #+#             */
/*   Updated: 2025/03/10 14:16:10 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

static int	rr(t_ivector *stack)
{
	int	tmp;

	if (stack->len > 1)
	{
		tmp = ivec_get(stack, -1);
		ft_memmove(stack->data, stack->data + 1,
			(stack->len - 1) * sizeof(int));
		stack->data[0] = tmp;
	}
	return (0);
}

int	rra(t_ivector *stack_a)
{
	return (rr(stack_a));
}

int	rrb(t_ivector *stack_b)
{
	return (rr(stack_b));
}

int	rrr(t_ivector *stack_a, t_ivector *stack_b)
{
	return (rr(stack_a) || rr(stack_b));
}
