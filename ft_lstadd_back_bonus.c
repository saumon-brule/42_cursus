/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:32:20 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 07:11:53 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		(lst) = &((*lst)->next);
	(*lst)->next = new;
}

// int	main(int ac, char **av)
// {
// 	t_list	*lst;

// 	if (ac > 1)
// 	{
// 		lst = ft_lstnew("FIRST");
// 		ft_lstadd_back(&lst, ft_lstnew(av[1]));
// 		printf("\"%s\" > ", (char *)(lst->content));
// 		printf("\"%s\"\n", (char *)(lst->next->content));
// 		free(lst->next);
// 		free(lst);
// 	}
// }
