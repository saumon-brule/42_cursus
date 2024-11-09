/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:41:15 by ebini             #+#    #+#             */
/*   Updated: 2024/11/08 01:14:27 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

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
		result = result * 10 + (((*nptr++) - 48) * sign);
	return (result);
}
// int	main(void)
// {
// 	printf("%d", atoi("9999999999999999999"));
// }