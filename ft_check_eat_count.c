/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_eat_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:37:45 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:55:47 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_eat_count(t_data *data)
{
	int	i;
	int	all_ate;

	i = 0;
	all_ate = 1;
	if (data->num_times_eat == 0)
		return (0);
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->philos[i]->m_eat);
		if (data->philos[i]->num_eats < data->num_times_eat)
			all_ate = 0;
		pthread_mutex_unlock(&data->philos[i]->m_eat);
		i++;
	}
	if (all_ate == 1)
	{
		pthread_mutex_lock(&data->m_simul_run);
		data->simul_run = 0;
		pthread_mutex_unlock(&data->m_simul_run);
	}
	return (all_ate);
}
