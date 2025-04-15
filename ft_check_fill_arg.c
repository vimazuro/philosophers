/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fill_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:48:32 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:55:51 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_fill_arg(int argc, char **argv, t_data *data)
{
	if (argc < 5 || argc > 6)
	{
		printf("ERROR! The input must be: ./philo NP TD TE TS [NTE]\n\
NP - number_of_philosophers\nTD - time_to_die\n\
TE - time_to_eat\nTS - time_to_sleep\n\
NTE - number_of_times_each_philosopher_must_eat (optional)\n");
		return (-1);
	}
	else
	{
		data->num_philo = ft_atoi(argv[1]);
		data->time_die = ft_atoi(argv[2]);
		data->time_eat = ft_atoi(argv[3]);
		data->time_sleep = ft_atoi(argv[4]);
		if (argv[5])
			data->num_times_eat = ft_atoi(argv[5]);
		else
			data->num_times_eat = 0;
		if (data->num_philo < 1 || data->time_die < 1
			|| data->time_eat < 1 || data->time_sleep < 1
			|| data->num_times_eat < 0)
		{
			printf("ERROR! All arguments must be > 0\n");
			return (-1);
		}
	}
	return (0);
}
