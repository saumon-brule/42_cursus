/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 06:33:47 by ebini             #+#    #+#             */
/*   Updated: 2025/03/30 07:07:44 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>

#include "so_long_defs.h"
#include "settings.h"

#include <stdio.h>

t_time	init_last_time()
{
	t_time	current_time;
	
	gettimeofday(&current_time, NULL);
	return (current_time);
}

double	wait_for_frame(t_time *last_time)
{
	t_time	current_time;
	double	dt;
	double	time_to_sleep;
	t_sleep	sleep_time;

	current_time = init_last_time();
	dt = (current_time.tv_sec - last_time->tv_sec) * 1000000.0
		+ (current_time.tv_usec - last_time->tv_usec);
	time_to_sleep = (1000000.0 / FPS_CAP) - dt;
	if (time_to_sleep > 0)
	{
		sleep_time.tv_sec = (long)(time_to_sleep / 1000000.0);
		sleep_time.tv_nsec = (long)((time_to_sleep - sleep_time.tv_sec
					* 1000000.0) * 1000.0);
		nanosleep(&sleep_time, NULL);
		gettimeofday(&current_time, NULL);
		*last_time = current_time;
		return (1.0 / FPS_CAP);
	}
	*last_time = current_time;
	return (dt / 1000000.0);
}
