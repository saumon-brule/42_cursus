/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saumon <saumon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:35:43 by saumon            #+#    #+#             */
/*   Updated: 2025/03/03 18:10:20 by saumon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

char	cvec_get(t_cvector *vector, ssize_t index)
{
	if (index < 0)
		return (vector->data[vector->len + index]);
	return (vector->data[index]);
}
