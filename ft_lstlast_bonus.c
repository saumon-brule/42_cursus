/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:08:18 by ebini             #+#    #+#             */
/*   Updated: 2024/11/14 07:33:36 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(int ac, char **av)
// {
// 	t_list	*lst;
// 	int		i;

// 	if (ac > 1)
// 	{
// 		i = ft_strlen(av[1]);
// 		printf("strlen : %d\n", i);
// 		lst = ft_lstnew(&i);
// 		while (i >= 0)
// 			ft_lstadd_front(&lst, ft_lstnew(&av[1][i--]));
// 		printf("last : %d\n", *(int *)(ft_lstlast(lst)->content));
// 	}
// }
