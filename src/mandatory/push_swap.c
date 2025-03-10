/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 06:29:11 by ebini             #+#    #+#             */
/*   Updated: 2025/03/10 13:56:37 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include "push_swap.h"

void	move_to_a(t_ivector *stack_a, t_ivector *stack_b)
{
	int			smallest;

	rotate_to_top(stack_b);
	if (stack_b->len && ivec_get(stack_b, 0) < ivec_get(stack_a, -1))
		rra(stack_a);
	while (stack_b->len)
	{
		while (ivec_get(stack_a, -1) > ivec_get(stack_b, 0)
			&& ivec_get(stack_a, -1) < ivec_get(stack_a, 0))
			rra(stack_a);
		pa(stack_a, stack_b);
	}
	if (stack_a->len < 2)
		return ;
	smallest = 0;
	while (++smallest < (int)stack_a->len
		&& ivec_get(stack_a, smallest) > ivec_get(stack_a, smallest - 1))
		;
	smallest *= smallest < (int)stack_a->len;
	if (smallest > (int)(stack_a->len / 2))
		smallest -= stack_a->len;
	rotate_n(stack_a, smallest, &ra, &rra);
}

void	sort_i(t_ivector *stack_a, t_ivector *stack_b, int index)
{
	int	to_top_a;
	int	to_top_b;

	if (index < (int)(stack_a->len / 2))
		to_top_a = index;
	else
		to_top_a = index - stack_a->len;
	to_top_b = get_push_pos(stack_b, ivec_get(stack_a, index));
	if (to_top_b > (int)(stack_b->len / 2))
		to_top_b -= stack_b->len;
	if (to_top_a > 0 && to_top_b < 0)
	{
		if ((int)stack_b->len + to_top_b - to_top_a < -to_top_b)
			to_top_b = stack_b->len + to_top_b;
	}
	else if (to_top_a < 0 && to_top_b > 0)
	{
		if (to_top_b - (int)stack_b->len - to_top_a > -to_top_b)
			to_top_b = to_top_b - stack_b->len;
	}
	merge_to_push(stack_a, stack_b, to_top_a, to_top_b);
	pb(stack_a, stack_b);
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
	if (to_top_b > (int)(stack_b->len / 2))
		to_top_b = to_top_b - stack_b->len;
	if (to_top_a >= 0 && to_top_b >= 0)
		return (max(to_top_a, to_top_b));
	if (to_top_a <= 0 && to_top_b <= 0)
		return (-min(to_top_a, to_top_b));
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
	least_move_index = i;
	least_move = get_move_number(stack_a, stack_b, i);
	while (++i < (int)stack_a->len)
	{
		current_move = get_move_number(stack_a, stack_b, i);
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
	if (stack_a->len < 2)
		return ;
	if (stack_a->len < 3)
	{
		if (ivec_get(stack_a, 0) > ivec_get(stack_a, 1))
			ra(stack_a);
		return ;
	}
	while (stack_a->len > 3)
		sort_easiest(stack_a, stack_b);
	if (ivec_get(stack_a, 0) > ivec_get(stack_a, 1)
		&& ivec_get(stack_a, 0) > ivec_get(stack_a, 2))
		ra(stack_a);
	else if (ivec_get(stack_a, 1) > ivec_get(stack_a, 0)
		&& ivec_get(stack_a, 1) > ivec_get(stack_a, 2))
		rra(stack_a);
	if (ivec_get(stack_a, 0) > ivec_get(stack_a, 1))
		sa(stack_a);
	move_to_a(stack_a, stack_b);
}
