/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 23:06:38 by ebini             #+#    #+#             */
/*   Updated: 2025/03/10 13:59:49 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

static int	p(t_ivector *stack_src, t_ivector *stack_dest)
{
	if (!stack_src->len)
		return (1);
	if (stack_dest->len)
		ft_memmove(stack_dest->data, stack_dest->data + 1,
			stack_dest->len * sizeof(int));
	++stack_dest->len;
	ivec_set(stack_dest, 0, ivec_get(stack_src, 0));
	--stack_src->len;
	if (stack_src->len)
		ft_memmove(stack_src->data + 1, stack_src->data,
			stack_src->len * sizeof(int));
	return (0);
}

int	pa(t_ivector *stack_a, t_ivector *stack_b)
{
	return (p(stack_b, stack_a));
}

int	pb(t_ivector *stack_a, t_ivector *stack_b)
{
	return (p(stack_a, stack_b));
}
