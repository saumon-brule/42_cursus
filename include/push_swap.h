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

int		parse_input(int ac, char **av, t_ivector *vector);
bool	is_int(char *s);
bool	is_number(char *s);

int		get_push_pos(t_ivector *stack, int el);
void	push_swap(t_ivector *stack_a, t_ivector *stack_b);

#endif