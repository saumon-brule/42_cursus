/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:20:51 by ebini             #+#    #+#             */
/*   Updated: 2025/03/08 11:37:33 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

#include <stdio.h>

static void	r(t_ivector *stack)
{
	const int	tmp = ivec_get(stack, 0);

	ft_memmove(stack->data + 1, stack->data, (stack->len - 1) * sizeof(int));
	ivec_set(stack, -1, tmp);
}

void	ra(t_ivector *stack_a)
{
	r(stack_a);
	ft_printf("ra\n");
}

void	rb(t_ivector *stack_b)
{
	r(stack_b);
	ft_printf("rb\n");
}

void	rr(t_ivector *stack_a, t_ivector *stack_b)
{
	r(stack_a);
	r(stack_b);
	ft_printf("rr\n");
}
