/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:30:02 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 00:18:54 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(int ac, char **av)
// {
// 	t_list	*lst;

// 	if (ac > 1)
// 	{
// 		lst = ft_lstnew("FIRST");
// 		ft_lstadd_front(&lst, ft_lstnew(av[1]));
// 		printf("\"%s\" > ", (char *)(lst->content));
// 		printf("\"%s\"\n", (char *)(lst->next->content));
// 		free(lst->next);
// 		free(lst);
// 	}
// }
