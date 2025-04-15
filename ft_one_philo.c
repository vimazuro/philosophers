/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:25:47 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:56:05 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_one_philo(t_philo *philo)
{
	time_t	now;
	time_t	time_print;

	now = ft_current_time_ms();
	time_print = now - philo->data->time_start;
	printf("%ld %d has taken a fork\n", time_print, philo->id);
	ft_safe_usleep(philo->data->time_die, philo);
}
