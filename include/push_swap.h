/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:30:46 by ebini            #+#    #+#             */
/*   Updated: 2025/03/04 08:46:10 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "vector.h"

void	sa(t_ivector *stack_a);
void	sb(t_ivector *stack_b);
void	ss(t_ivector *stack_a, t_ivector *stack_b);
void	pa(t_ivector *stack_a, t_ivector *stack_b);
void	pb(t_ivector *stack_a, t_ivector *stack_b);
void	ra(t_ivector *stack_a);
void	rb(t_ivector *stack_b);
void	rr(t_ivector *stack_a, t_ivector *stack_b);
void	rra(t_ivector *stack_a);
void	rrb(t_ivector *stack_b);
void	rrr(t_ivector *stack_a, t_ivector *stack_b);

int		parse_input(int ac, char **av, t_ivector *vector);
bool	is_int(char *s);
bool	is_number(char *s);

void	rotate_to_top(t_ivector *stack);
int		get_push_pos(t_ivector *stack, int el);
void	merge_to_push(t_ivector *stack_a, t_ivector *stack_b, int to_top_a,
			int to_top_b);
void	rotate_n(t_ivector *stack, int n,
			void (*r)(t_ivector *), void (*rr)(t_ivector *));
void	push_swap(t_ivector *stack_a, t_ivector *stack_b);

#endif