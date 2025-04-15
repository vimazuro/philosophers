/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:07:16 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:56:16 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_simulation(t_data *data)
{
	pthread_mutex_init(&data->m_simul_run, NULL);
	pthread_mutex_init(&data->m_print_status, NULL);
	data->simul_run = 1;
	data->time_start = (ft_current_time_ms() + (30 * data->num_philo));
	data->philos = ft_fill_philos(data);
	if (!data->philos)
	{
		pthread_mutex_destroy(&data->m_print_status);
		pthread_mutex_destroy(&data->m_simul_run);
		return (1);
	}
	return (0);
}

void	ft_manage_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_create(&(data->philos[i]->thread), NULL,
			ft_routine, data->philos[i]);
		i++;
	}
	pthread_create(&data->monitor, NULL, (void *)ft_check_death, (void *)data);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philos[i]->thread, NULL);
		i++;
	}
	pthread_join(data->monitor, NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_check_fill_arg(argc, argv, &data) == 0)
	{
		if (ft_init_simulation(&data) != 0)
			return (1);
		ft_manage_threads(&data);
		pthread_mutex_destroy(&data.m_print_status);
		pthread_mutex_destroy(&data.m_simul_run);
		ft_free_philos(&data);
	}
	return (0);
}
