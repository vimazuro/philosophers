/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:58:39 by vimazuro          #+#    #+#             */
/*   Updated: 2025/04/09 09:56:22 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				is_dead;
	int				num_eats;
	time_t			last_eat;
	pthread_t		thread;
	pthread_mutex_t	m_eat;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_times_eat;
	int				simul_run;
	time_t			time_start;
	t_philo			**philos;
	pthread_t		monitor;
	pthread_mutex_t	m_simul_run;
	pthread_mutex_t	m_print_status;
	pthread_mutex_t	*forks;
}	t_data;

int				main(int argc, char **argv);
int				ft_atoi(const char *nptr);
int				ft_check_fill_arg(int argc, char **argv, t_data *data);
int				ft_monitoring(t_data *data);
int				ft_init_philos(t_philo **philos, t_data *data);
int				ft_take_forks(t_philo *philo, int left, int right);
int				ft_init_simulation(t_data *data);
int				ft_check_eat_count(t_data *data);
void			*ft_routine(void *data);
void			ft_free_philos(t_data *data);
void			ft_philo_eat(t_philo *philo);
void			ft_check_death(t_data *data);
void			ft_safe_usleep(int time_ms, t_philo *philo);
void			ft_philo_sleep_think(t_philo *philo);
void			ft_stop_simulation(t_data *data, int dead_id, time_t now_print);
void			ft_manage_threads(t_data *data);
void			ft_one_philo(t_philo *philo);
void			ft_print_status(t_philo *philo, char status);
time_t			ft_current_time_ms(void);
t_philo			**ft_fill_philos(t_data *data);
t_philo			**ft_allocate_philos(int num_philo);
pthread_mutex_t	*ft_allocate_forks(int num_philo);

#endif
