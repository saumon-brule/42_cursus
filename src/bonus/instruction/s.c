/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:39:47 by ebini             #+#    #+#             */
/*   Updated: 2025/03/10 14:02:51 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

static int	s(t_ivector *stack)
{
	int	tmp;

	if (stack->len < 2)
		return (1);
	tmp = ivec_get(stack, 0);
	ivec_set(stack, 0, ivec_get(stack, 1));
	ivec_set(stack, 1, tmp);
	return (0);
}

int	sa(t_ivector *stack_a)
{
	return (s(stack_a));
}

int	sb(t_ivector *stack_b)
{
	return (s(stack_b));
}

int	ss(t_ivector *stack_a, t_ivector *stack_b)
{
	return (s(stack_a) || s(stack_b));
}
