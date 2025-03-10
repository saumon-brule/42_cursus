/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:57:19 by ebini             #+#    #+#             */
/*   Updated: 2025/03/10 14:13:39 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector.h"
#include "libft.h"
#include "push_swap_checker.h"

int	check_instruction(char *instruction, t_ivector *stack_a, t_ivector *stack_b)
{
	if (!ft_strcmp(instruction, "sa\n"))
		return (sa(stack_a));
	if (!ft_strcmp(instruction, "sb\n"))
		return (sb(stack_b));
	if (!ft_strcmp(instruction, "ss\n"))
		return (ss(stack_a, stack_b));
	if (!ft_strcmp(instruction, "pa\n"))
		return (pa(stack_a, stack_b));
	if (!ft_strcmp(instruction, "pb\n"))
		return (pb(stack_a, stack_b));
	if (!ft_strcmp(instruction, "ra\n"))
		return (ra(stack_a));
	if (!ft_strcmp(instruction, "rb\n"))
		return (rb(stack_b));
	if (!ft_strcmp(instruction, "rr\n"))
		return (rr(stack_a, stack_b));
	if (!ft_strcmp(instruction, "rra\n"))
		return (rra(stack_a));
	if (!ft_strcmp(instruction, "rrb\n"))
		return (rrb(stack_b));
	if (!ft_strcmp(instruction, "rrr\n"))
		return (rrr(stack_a, stack_b));
	return (1);
}

int	is_sorted(t_ivector *stack)
{
	int	i;
	int	old;
	int	new;

	i = 0;
	old = ivec_get(stack, 0);
	while (++i < (int)stack->len)
	{
		new = ivec_get(stack, i);
		if (old > new)
			return (1);
		old = new;
	}
	return (0);
}

int	check_push_swap(t_ivector *stack_a, t_ivector *stack_b)
{
	char	*line;
	int		check_result;

	if (!stack_a->len)
		return (0);
	line = get_next_line(0);
	while (line)
	{
		check_result = check_instruction(line, stack_a, stack_b);
		free(line);
		if (check_result)
			return (check_result);
		line = get_next_line(0);
	}
	return (!stack_b->len && is_sorted(stack_a));
}
