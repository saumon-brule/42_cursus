/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 06:29:08 by ebini             #+#    #+#             */
/*   Updated: 2025/03/08 12:00:14 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include "push_swap.h"

int	get_push_pos(t_ivector *stack, int el)
{
	int	i;
	int	biggest;
	int	current;

	if (stack->len < 2)
		return (0);
	biggest = 0;
	while (++biggest < (int)stack->len
		&& ivec_get(stack, biggest - 1) > ivec_get(stack, biggest))
		;
	biggest *= biggest < (int)stack->len;
	i = -1;
	while (++i < (int)stack->len)
	{
		current = (biggest + i) % stack->len;
		if (el > ivec_get(stack, current))
			return (current);
	}
	return ((current + 1) % stack->len);
}

void	rotate_n(t_ivector *stack, int n,
	void (*r)(t_ivector *), void (*rr)(t_ivector *))
{
	if (n > 0)
	{
		while (n)
		{
			--n;
			r(stack);
		}
	}
	else
	{
		while (n)
		{
			++n;
			rr(stack);
		}
	}
}

void	rotate_double(t_ivector *stack_a, t_ivector *stack_b, int *to_top_a,
	int *to_top_b)
{
	if (*to_top_a > 0 && *to_top_b > 0)
	{
		while (*to_top_a && *to_top_b)
		{
			--*to_top_a;
			--*to_top_b;
			rr(stack_a, stack_b);
		}
	}
	else if (*to_top_a < 0 && *to_top_b < 0)
	{
		while (*to_top_a && *to_top_b)
		{
			++*to_top_a;
			++*to_top_b;
			rrr(stack_a, stack_b);
		}
	}
}

void	merge_to_push(t_ivector *stack_a, t_ivector *stack_b, int to_top_a,
	int to_top_b)
{
	rotate_double(stack_a, stack_b, &to_top_a, &to_top_b);
	rotate_n(stack_a, to_top_a, &ra, &rra);
	rotate_n(stack_b, to_top_b, &rb, &rrb);
}

void	rotate_to_top(t_ivector *stack)
{
	int	biggest;

	if (stack->len < 2)
		return ;
	biggest = 0;
	while (++biggest < (int)stack->len
		&& ivec_get(stack, biggest) < ivec_get(stack, biggest - 1))
		;
	biggest *= biggest < (int)stack->len;
	if (biggest > (int)(stack->len / 2))
		biggest -= stack->len;
	rotate_n(stack, biggest, &rb, &rrb);
}
