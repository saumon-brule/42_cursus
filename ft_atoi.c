/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:41:15 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 23:28:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	result;

	while (('\t' <= nptr[0] && nptr[0] <= '\r') || nptr[0] == ' ')
		nptr++;
	sign = 1;
	if (nptr[0] == '+')
		nptr++;
	else if (nptr[0] == '-')
	{
		nptr++;
		sign = -1;
	}
	result = 0;
	while (ft_isdigit(*nptr))
	{
		if (sign > 0 && (LLONG_MAX - (*nptr - 48)) / 10 < result)
			return ((int)LLONG_MAX);
		else if (sign < 0 && (LLONG_MIN + (*nptr - 48)) / 10 > result)
			return ((int)LLONG_MIN);
		result = result * 10 + (((*nptr++) - 48) * sign);
	}
	return (result);
}
