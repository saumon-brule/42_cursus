/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:20:30 by saumon            #+#    #+#             */
/*   Updated: 2025/03/04 16:42:43 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector.h"
#include "libft.h"

int	cvec_push(t_cvector *vector, char element)
{
	char	*new_area;

	if (vector->capacity == vector->len)
	{
		new_area = malloc((vector->capacity << 1) * sizeof(char));
		if (!new_area)
			return (1);
		ft_memcpy(new_area, vector->data, vector->capacity * sizeof(char));
		free(vector->data);
		vector->capacity = vector->capacity << 1;
		vector->data = new_area;
	}
	vector->data[vector->len] = element;
	++(vector->len);
	return (0);
}
