/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:45:21 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 07:32:53 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*child;

	if (!(*lst))
		return ;
	while (*lst)
	{
		child = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = child;
	}
	*lst = NULL;
}

// void	del(void *a)
// {
// 	free(a);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*lst_node;

// 	lst = ft_lstnew(malloc(1));
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(2)));
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(3)));
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(4)));
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(5)));
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(6)));
// 	lst_node = lst->next->next;
// 	ft_lstclear(&(lst_node->next), &del);
// 	printf("%p\n", lst_node->next);
// 	ft_lstclear(&lst, &del);
// }
