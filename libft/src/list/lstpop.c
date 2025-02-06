/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstpop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:51:33 by ebini             #+#    #+#             */
/*   Updated: 2025/01/27 04:08:26 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "defs.h"

#include "libft.h"

void	*lstpop(t_list **lst)
{
	void	*content;
	t_list	*lst_parent;
	t_list	*local_lst;

	local_lst = *lst;
	if (!local_lst)
		return (NULL);
	lst_parent = NULL;
	while (local_lst->next)
	{
		lst_parent = local_lst;
		local_lst = local_lst->next;
	}
	content = local_lst->content;
	if (lst_parent)
		lst_parent->next = NULL;
	free(local_lst);
	return (content);
}
