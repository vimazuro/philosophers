/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:22:52 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:56:07 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_status(t_philo *philo, char status)
{
	time_t	now;
	time_t	time_print;

	pthread_mutex_lock(&(philo->data->m_print_status));
	if (ft_monitoring(philo->data) == 0 || ft_check_eat_count(philo->data) == 1)
	{
		pthread_mutex_unlock(&(philo->data->m_print_status));
		return ;
	}
	now = ft_current_time_ms();
	time_print = now - philo->data->time_start;
	if (status == 's')
		printf("%ld %d is sleeping\n", time_print, philo->id);
	else if (status == 't')
		printf("%ld %d is thinking\n", time_print, philo->id);
	else if (status == 'f')
		printf("%ld %d has taken a fork\n%ld %d has taken a fork\n",
			time_print, philo->id, time_print, philo->id);
	else if (status == 'e')
		printf("%ld %d is eating\n", time_print, philo->id);
	pthread_mutex_unlock(&(philo->data->m_print_status));
}
