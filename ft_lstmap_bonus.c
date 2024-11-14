/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:27:19 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 02:25:00 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*generate_node(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_node;
	void	*new_content;

	new_content = (*f)(lst->content);
	result_node = ft_lstnew(new_content);
	if (!result_node)
	{
		(*del)(new_content);
		return (NULL);
	}
	return (result_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_lst;
	t_list	*current_node;

	if (!lst)
		return (NULL);
	result_lst = generate_node(lst, f, del);
	if (!result_lst)
		return (NULL);
	lst = lst->next;
	current_node = result_lst;
	while (lst)
	{
		current_node->next = generate_node(lst, f, del);
		if (!current_node->next)
		{
			ft_lstclear(&result_lst, del);
			return (NULL);
		}
		lst = lst->next;
		current_node = current_node->next;
	}
	return (result_lst);
}

// void	del(void *a)
// {
// 	free(a);
// }

// void	*iter(void *a)
// {
// 	char	*aled;

// 	(void)a;
// 	aled = malloc(1);
// 	*aled = '0';
// 	return (aled);
// }

// int	main(void)
// {
// 	t_list	*lst;
// 	t_list	*lst2;

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
// 	lst2 = ft_lstmap(lst, &iter, &del);
// 	printf("%c", *(char *)(lst2->content));
// 	printf("%c", *(char *)(lst2->next->content));
// 	printf("%c", *(char *)(lst2->next->next->content));
// 	printf("%c", *(char *)(lst2->next->next->next->content));
// 	printf("%c", *(char *)(lst2->next->next->next->next->content));
// 	ft_lstclear(&lst, &del);
// 	ft_lstclear(&lst2, &del);
// }
