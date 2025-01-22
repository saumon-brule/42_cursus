/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstpop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:51:33 by ebini             #+#    #+#             */
/*   Updated: 2025/01/22 18:54:02 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

void	*lstpop(t_list *lst)
{
	void	*content;

	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	content = lst->content;
	free(lst);
	return (content);
}
