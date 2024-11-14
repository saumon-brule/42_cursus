/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:49:48 by ebini             #+#    #+#             */
/*   Updated: 2024/11/13 21:04:17 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int	main(int ac, char **av)
// {
// 	t_list	*lst;
// 	int		i;

// 	if (ac > 1)
// 	{
// 		i = ft_strlen(av[1]);
// 		printf("strlen : %d\n", i);
// 		lst = ft_lstnew(&av[1][i--]);
// 		while (i >= 0)
// 			ft_lstadd_front(&lst, ft_lstnew(&av[1][i--]));
// 		printf("size : %d\n", ft_lstsize(lst));
// 	}
// }
