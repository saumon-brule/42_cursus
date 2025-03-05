/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 06:29:08 by ebini             #+#    #+#             */
/*   Updated: 2025/03/05 08:19:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

int	get_push_pos(t_ivector *stack, int el)
{
	int	i;
	int	old;
	int	new;

	if (!stack->len)
		return (0);
	i = 0;
	old = ivec_get(stack, i);
	while (++i < (int)stack->len)
	{
		new = ivec_get(stack, i);
		if (old < new)
			break;
		old = new;
	}
	i *= i < (int)stack->len;
	while (i < (int)stack->len && el < ivec_get(stack, i))
		i = (i + 1) % stack->len;
	return (i);
}
