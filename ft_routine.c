/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 12:38:01 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:56:10 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_sleep_think(t_philo *philo)
{
	ft_print_status(philo, 's');
	ft_safe_usleep(philo->data->time_sleep, philo);
	ft_print_status(philo, 't');
}

int	ft_take_forks(t_philo *philo, int left, int right)
{
	if (left < right)
	{
		pthread_mutex_lock(&(philo->data->forks[left]));
		pthread_mutex_lock(&(philo->data->forks[right]));
	}
	else
	{
		pthread_mutex_lock(&(philo->data->forks[right]));
		pthread_mutex_lock(&(philo->data->forks[left]));
	}
	if (philo->is_dead == 1)
	{
		pthread_mutex_unlock(&(philo->data->forks[left]));
		pthread_mutex_unlock(&(philo->data->forks[right]));
		return (0);
	}
	ft_print_status(philo, 'f');
	return (1);
}

void	ft_philo_eat(t_philo *philo)
{
	int	id_fork_left;
	int	id_fork_right;

	id_fork_left = (philo->id - 1);
	id_fork_right = (philo->id % philo->data->num_philo);
	while (1)
	{
		if (philo->is_dead == 1)
			return ;
		if (ft_take_forks(philo, id_fork_left, id_fork_right) == 1)
			break ;
	}
	ft_print_status(philo, 'e');
	pthread_mutex_lock(&(philo->m_eat));
	philo->num_eats++;
	philo->last_eat = ft_current_time_ms();
	pthread_mutex_unlock(&(philo->m_eat));
	ft_check_eat_count(philo->data);
	ft_safe_usleep(philo->data->time_eat, philo);
	pthread_mutex_unlock(&(philo->data->forks[id_fork_left]));
	pthread_mutex_unlock(&(philo->data->forks[id_fork_right]));
}

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (ft_current_time_ms() < philo->data->time_start)
		usleep(100);
	if (philo->data->num_philo == 1)
	{
		ft_one_philo(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0 && ft_monitoring(philo->data) == 1)
		ft_philo_sleep_think(philo);
	while (ft_monitoring(philo->data) == 1)
	{
		ft_philo_eat(philo);
		ft_philo_sleep_think(philo);
	}
	return (NULL);
}
