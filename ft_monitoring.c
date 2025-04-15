/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_monitoring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:22:33 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:56:02 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_monitoring(t_data *data)
{
	int	run;

	pthread_mutex_lock(&data->m_simul_run);
	run = data->simul_run;
	pthread_mutex_unlock(&data->m_simul_run);
	return (run);
}
