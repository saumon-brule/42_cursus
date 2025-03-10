/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:46:47 by ebini             #+#    #+#             */
/*   Updated: 2025/03/08 11:50:58 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "vector.h"
#include "push_swap.h"

int	handle_param(t_ivector *stack, char **splitted_param, int index)
{
	int	number;

	if (!is_number(splitted_param[index]) || !is_int(splitted_param[index]))
	{
		ivec_clear(stack);
		free_split(splitted_param);
		return (1);
	}
	number = ft_atoi(splitted_param[index]);
	if (ivec_includes(stack, number) || ivec_push(stack, number))
	{
		ivec_clear(stack);
		free_split(splitted_param);
		return (1);
	}
	return (0);
}

int	parse_input(int ac, char **av, t_ivector *stack)
{
	int		i;
	int		j;
	char	**splitted_param;

	if (ivec_init(stack, NULL, ac - 1))
		return (1);
	i = 0;
	while (++i < ac)
	{
		splitted_param = ft_split(av[i], ' ');
		if (!splitted_param)
		{
			ivec_clear(stack);
			return (1);
		}
		j = -1;
		while (splitted_param[++j])
			if (handle_param(stack, splitted_param, j))
				return (1);
		free_split(splitted_param);
	}
	return (0);
}
