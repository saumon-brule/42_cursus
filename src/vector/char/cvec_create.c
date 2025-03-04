/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:48:43 by saumon            #+#    #+#             */
/*   Updated: 2025/03/04 23:38:09 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector.h"
#include "libft.h"

int	cvec_init(t_cvector *vector, char *array, size_t len)
{
	size_t	elem_capacity;

	elem_capacity = (MEMORY_SIZE / 64) / sizeof(char);
	while (elem_capacity < len)
		elem_capacity <<= 1;
	vector->data = malloc(elem_capacity * sizeof(char));
	if (!vector->data)
		return (1);
	vector->capacity = elem_capacity;
	if (array)
	{
		vector->len = len;
		ft_memcpy(vector->data, array, len * sizeof(char));
	}
	else
		vector->len = 0;
	return (0);
}

t_cvector	*cvec_create(char *array, size_t len)
{
	t_cvector	*vector;

	vector = malloc(sizeof(t_cvector));
	if (!vector)
		return (NULL);
	if (cvec_init(vector, array, len))
	{
		free(vector);
		return (NULL);
	}
	return (vector);
}
