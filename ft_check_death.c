/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:47:17 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:55:44 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_stop_simulation(t_data *data, int dead_id, time_t now_print)
{
	pthread_mutex_lock(&data->m_print_status);
	printf("%ld %d died\n", now_print, dead_id);
	pthread_mutex_lock(&data->m_simul_run);
	data->simul_run = 0;
	pthread_mutex_unlock(&data->m_simul_run);
	pthread_mutex_unlock(&data->m_print_status);
}

void	ft_check_death(t_data *data)
{
	int			i;
	time_t		now_print;
	time_t		time_diff;

	while (1)
	{
		if (!ft_monitoring(data))
			return ;
		i = 0;
		now_print = ft_current_time_ms();
		while (i < data->num_philo)
		{
			pthread_mutex_lock(&data->philos[i]->m_eat);
			time_diff = now_print - data->philos[i]->last_eat;
			pthread_mutex_unlock(&data->philos[i]->m_eat);
			if (time_diff >= data->time_die + 1)
			{
				ft_stop_simulation(data, data->philos[i]->id,
					now_print - data->time_start - 1);
				return ;
			}
			i++;
		}
		usleep(100);
	}
}
