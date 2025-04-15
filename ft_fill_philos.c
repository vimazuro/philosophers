/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:54:08 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:55:56 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**ft_allocate_philos(int num_philo)
{
	t_philo	**philos;

	philos = malloc(sizeof(t_philo *) * num_philo);
	if (!philos)
	{
		printf("ERROR! malloc of philos not allocated\n");
		return (NULL);
	}
	return (philos);
}

pthread_mutex_t	*ft_allocate_forks(int num_philo)
{
	int				i;
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * num_philo);
	if (!forks)
	{
		printf("ERROR! malloc for forks not allocated\n");
		return (NULL);
	}
	i = 0;
	while (i < num_philo)
	{
		pthread_mutex_init(&(forks[i]), NULL);
		i++;
	}
	return (forks);
}

int	ft_init_philos(t_philo **philos, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		philos[i] = malloc(sizeof(t_philo));
		if (!philos[i])
		{
			printf("ERROR! malloc of philos not allocated\n");
			while (--i >= 0)
				free(philos[i]);
			free(philos);
			return (1);
		}
		philos[i]->id = i + 1;
		philos[i]->is_dead = 0;
		philos[i]->data = data;
		philos[i]->last_eat = data->time_start;
		philos[i]->num_eats = 0;
		pthread_mutex_init(&philos[i]->m_eat, NULL);
		i++;
	}
	return (0);
}

t_philo	**ft_fill_philos(t_data *data)
{
	t_philo	**philos;

	philos = ft_allocate_philos(data->num_philo);
	if (!philos)
		return (NULL);
	data->forks = ft_allocate_forks(data->num_philo);
	if (!data->forks)
	{
		free(philos);
		return (NULL);
	}
	if (ft_init_philos(philos, data) == 1)
		return (NULL);
	return (philos);
}
