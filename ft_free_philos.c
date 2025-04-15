/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:33:23 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:55:59 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->philos[i]->m_eat);
		free(data->philos[i]);
		i++;
	}
	free(data->philos);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&(data->forks[i]));
		i++;
	}
	free(data->forks);
}
