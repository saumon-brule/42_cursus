/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:27:19 by ebini             #+#    #+#             */
/*   Updated: 2025/01/11 17:13:47 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"
#include "libft.h"

t_list	*generate_node(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_node;
	void	*new_content;

	new_content = f(lst->content);
	result_node = ft_lstnew(new_content);
	if (!result_node)
	{
		del(new_content);
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
