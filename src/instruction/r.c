/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:20:51 by ebini             #+#    #+#             */
/*   Updated: 2025/03/05 17:33:51 by ebini            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

void	r(t_ivector *stack)
{
	const int	temp = ivec_get(stack, 0);

	ft_memmove(stack->data, stack->data + 1, stack->len - 1);
	stack->data[stack->len - 1] = temp;
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
