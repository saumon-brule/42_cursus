/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:06:26 by ebini             #+#    #+#             */
/*   Updated: 2025/03/10 14:15:47 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H
# include "vector.h"

int		sa(t_ivector *stack_a);
int		sb(t_ivector *stack_b);
int		ss(t_ivector *stack_a, t_ivector *stack_b);
int		pa(t_ivector *stack_a, t_ivector *stack_b);
int		pb(t_ivector *stack_a, t_ivector *stack_b);
int		ra(t_ivector *stack_a);
int		rb(t_ivector *stack_b);
int		rr(t_ivector *stack_a, t_ivector *stack_b);
int		rra(t_ivector *stack_a);
int		rrb(t_ivector *stack_b);
int		rrr(t_ivector *stack_a, t_ivector *stack_b);

int		parse_input(int ac, char **av, t_ivector *vector);
bool	is_int(char *s);
bool	is_number(char *s);

int		check_push_swap(t_ivector *stack_a, t_ivector *stack_b);

#endif