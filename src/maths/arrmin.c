/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrmin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 20:22:34 by ebini             #+#    #+#             */
/*   Updated: 2025/01/11 16:11:40 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

int	arrmin(int *arr, size_t n)
{
	int		result;
	size_t	i;

	result = arr[i];
	while (++i < n)
		if (arr[i] < result)
			result = arr[i];
	return (result);
}
