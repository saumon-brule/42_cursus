/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:20:51 by ebini             #+#    #+#             */
/*   Updated: 2025/03/10 14:16:00 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

#include <stdio.h>

static int	r(t_ivector *stack)
{
	int	tmp;

	if (stack->len > 1)
	{
		tmp = ivec_get(stack, 0);
		ft_memmove(stack->data + 1, stack->data,
			(stack->len - 1) * sizeof(int));
		ivec_set(stack, -1, tmp);
	}
	return (0);
}

int	ra(t_ivector *stack_a)
{
	return (r(stack_a));
}

int	rb(t_ivector *stack_b)
{
	return (r(stack_b));
}

int	rr(t_ivector *stack_a, t_ivector *stack_b)
{
	return (r(stack_a) || r(stack_b));
}
