/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_safe_usleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:45:07 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:56:13 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_safe_usleep(int time_ms, t_philo *philo)
{
	time_t	start;

	start = ft_current_time_ms();
	while (ft_current_time_ms() - start < time_ms)
	{
		if (ft_monitoring(philo->data) == 0)
			return ;
		usleep(50);
	}
}
