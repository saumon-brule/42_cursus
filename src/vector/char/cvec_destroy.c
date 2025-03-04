/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvec_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saumon <saumon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:40:02 by saumon            #+#    #+#             */
/*   Updated: 2025/03/03 16:41:25 by saumon           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "vector.h"

void	cvec_clear(t_cvector *vector)
{
	free(vector->data);
}

void	cvec_destroy(t_cvector *vector)
{
	free(vector->data);
	free(vector);
}
