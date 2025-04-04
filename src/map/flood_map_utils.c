/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:17:54 by ebini             #+#    #+#             */
/*   Updated: 2025/04/03 12:49:23 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "so_long_defs.h"

t_list	*flood_node_create(t_tuple pos)
{
	t_tuple	*data;
	t_list	*node;

	data = malloc(sizeof(t_tuple));
	if (!data)
		return (NULL);
	*data = pos;
	node = malloc(sizeof(t_list));
	if (!node)
	{
		free(data);
		return (NULL);
	}
	node->content = data;
	node->next = NULL;
	return (node);
}

void	flood_node_del_first(t_list **lst)
{
	t_list	*tmp_lst;

	tmp_lst = (*lst)->next;
	free((*lst)->content);
	free(*lst);
	*lst = tmp_lst;
}

t_map	*duplicate_map(t_map *map)
{
	t_map	*new_map;

	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->width = map->width;
	new_map->height = map->height;
	new_map->data = malloc(new_map->width * new_map->height * sizeof(char));
	if (!new_map->data)
	{
		free(new_map);
		return (NULL);
	}
	ft_memset(new_map->data, 0, new_map->width * new_map->height);
	return (new_map);
}

void	clear_map(t_map *map)
{
	free(map->data);
	free(map);
}
