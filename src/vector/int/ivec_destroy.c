/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ivec_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saumon <saumon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:40:02 by saumon            #+#    #+#             */
/*   Updated: 2025/03/03 16:51:44 by saumon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector.h"

void	ivec_clear(t_ivector *vector)
{
	free(vector->data);
}

void	ivec_destroy(t_ivector *vector)
{
	free(vector->data);
	free(vector);
}
