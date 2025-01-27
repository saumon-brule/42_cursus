/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstpop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:51:33 by ebini             #+#    #+#             */
/*   Updated: 2025/01/27 03:53:47 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

#include "libft.h"

void	*lstpop(t_list *lst)
{
	void	*content;

	if (!lst)
		return (NULL);
	while (lst->next)
	{
		ft_dprintf(2, "%p -> %s -> %p\n", lst, lst->content, lst->next);
		lst = lst->next;
	}
	content = lst->content;
	free(lst);
	return (content);
}
