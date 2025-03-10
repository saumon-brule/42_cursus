/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:39:47 by ebini             #+#    #+#             */
/*   Updated: 2025/03/08 09:21:25 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

static void	s(t_ivector *stack)
{
	const int	tmp = ivec_get(stack, 0);

	ivec_set(stack, 0, ivec_get(stack, 1));
	ivec_set(stack, 1, tmp);
}

void	sa(t_ivector *stack_a)
{
	s(stack_a);
	ft_printf("sa\n");
}

void	sb(t_ivector *stack_b)
{
	s(stack_b);
	ft_printf("sb\n");
}

void	ss(t_ivector *stack_a, t_ivector *stack_b)
{
	s(stack_a);
	s(stack_b);
	ft_printf("ss\n");
}
