/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 00:53:53 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 01:24:18 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

// void	del(void *a)
// {
// 	free(a);
// }

// void	iter(void *a)
// {
// 	*(char *)a = '0';
// }

// int	main(void)
// {
// 	t_list	*lst;

// 	lst = ft_lstnew(malloc(1));
// 	*(char *)(lst->content) = 'C';
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(1)));
// 	*(char *)(lst->next->content) = 'o';
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(1)));
// 	*(char *)(lst->next->next->content) = 'o';
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(1)));
// 	*(char *)(lst->next->next->next->content) = 'l';
// 	ft_lstadd_back(&lst, ft_lstnew(malloc(1)));
// 	*(char *)(lst->next->next->next->next->content) = '\n';
// 	printf("%c", *(char *)(lst->content));
// 	printf("%c", *(char *)(lst->next->content));
// 	printf("%c", *(char *)(lst->next->next->content));
// 	printf("%c", *(char *)(lst->next->next->next->content));
// 	printf("%c", *(char *)(lst->next->next->next->next->content));
// 	ft_lstiter(lst, &iter);
// 	printf("%c", *(char *)(lst->content));
// 	printf("%c", *(char *)(lst->next->content));
// 	printf("%c", *(char *)(lst->next->next->content));
// 	printf("%c", *(char *)(lst->next->next->next->content));
// 	printf("%c", *(char *)(lst->next->next->next->next->content));
// 	ft_lstclear(&lst, &del);
// }
