/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 02:03:16 by ebini             #+#    #+#             */
/*   Updated: 2025/01/14 02:41:57 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"




char	*parse_command(char *cmd, char *path)
{
	if (!ft_strchr(cmd, "/"))
		return (ft_strdup(cmd));
	
	
}
