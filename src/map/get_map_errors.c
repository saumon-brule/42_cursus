/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 02:25:27 by ebini             #+#    #+#             */
/*   Updated: 2025/02/20 03:50:49 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*get_map_errors(int map_error_num)
{
	static char	*errors[] = {
		"",
		"Map format is invalid",
		"Unexpected character in map file",
		"The map isn't closed",
		"The map doesn't contain start",
		"The map doesn't contain exit",
		"The map doesn't contain any coin",
		"One or more coin are unreachable in the map",
	};

	return (errors[map_error_num]);
}
