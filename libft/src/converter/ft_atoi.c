/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:41:15 by ebini             #+#    #+#             */
/*   Updated: 2025/01/11 16:21:30 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	while (('\t' <= nptr[0] && nptr[0] <= '\r') || nptr[0] == ' ')
		nptr++;
	if (nptr[0] == '+')
	{
		nptr++;
		sign = 1;
	}
	else if (nptr[0] == '-')
	{
		nptr++;
		sign = -1;
	}
	result = 0;
	while (ft_isdigit(*nptr))
	{
		result *= 10;
		result += *nptr - '0';
		++nptr;
	}
	return (sign * result);
}
