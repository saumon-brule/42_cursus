/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 06:29:11 by ebini             #+#    #+#             */
/*   Updated: 2025/03/05 07:54:51 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include "push_swap.h"

void	sort_i(t_ivector *stack_a, t_ivector *stack_b, int i)
{
	int			to_top_a;
	int			to_top_b;

	if (i < (int)(stack_a->len / 2))
		to_top_a = i;
	else
		to_top_a = i - stack_a->len;
	to_top_b = get_push_pos(stack_b, ivec_get(stack_a, i));
	if (to_top_b >= (int)(stack_b->len / 2))
		to_top_b = to_top_b - stack_a->len;
	ft_printf("Move : %d (%d, %d)\n", i, to_top_a, to_top_b);
	ivec_pop(stack_a);
}

int	get_move_number(t_ivector *stack_a, t_ivector *stack_b, int i)
{
	int			to_top_a;
	int			to_top_b;

	if (i <= (int)(stack_a->len / 2))
		to_top_a = i;
	else
		to_top_a = i - stack_a->len;
	to_top_b = get_push_pos(stack_b, ivec_get(stack_a, i));
	if (to_top_b >= (int)(stack_b->len / 2))
		to_top_b = to_top_b - stack_b->len;
	ft_printf("%d:%d\n", to_top_a, to_top_b);
	if (to_top_a > 0 && to_top_b > 0)
		return (maxs(to_top_a, to_top_b));
	if (to_top_a < 0 && to_top_b < 0)
		return (-mins(to_top_a, to_top_b));
	if (to_top_a > 0)
		return (to_top_a - to_top_b);
	return (to_top_b - to_top_a);
}

void	sort_easiest(t_ivector *stack_a, t_ivector *stack_b)
{
	int	i;
	int	least_move;
	int	least_move_index;
	int	current_move;

	i = 0;
	least_move_index = 0;
	least_move = 0;
	while (++i < (int)stack_a->len)
	{
		current_move = get_move_number(stack_a, stack_b, i);
		ft_printf("move %d[%d] cost : %d\n", ivec_get(stack_a, i), i, current_move);
		if (current_move < least_move)
		{
			least_move_index = i;
			least_move = current_move;
		}
	}
	sort_i(stack_a, stack_b, least_move_index);
}

void	push_swap(t_ivector *stack_a, t_ivector *stack_b)
{
	while (stack_a->len > 3)
	{
		sort_easiest(stack_a, stack_b);
	}
}
