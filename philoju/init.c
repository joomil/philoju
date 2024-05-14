/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:56:03 by jmilesi           #+#    #+#             */
/*   Updated: 2024/04/23 23:25:49 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int		i;

	i = -1;
	data->forks = malloc(data->nb_philo * sizeof(pthread_mutex_t));
	if (!data -> forks)
		return (free_all(data), -1);
	data -> priv_lock = malloc(data -> nb_philo * sizeof(pthread_mutex_t));
	if (!data -> priv_lock)
		return (free_all(data), -1);
	while (++i < data -> nb_philo)
	{
		pthread_mutex_init(&data -> forks[i], NULL);
		pthread_mutex_init(&data -> priv_lock[i], NULL);
	}
	pthread_mutex_init(&data -> main_lock, NULL);
	pthread_mutex_init(&data -> write_message, NULL);
	return (0);
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < data->nb_philo)
	{
		philo[i].philo_id = i + 1;
		philo[i].start_time = &data -> start_time;
		philo[i].left_fork = &data -> forks[i];
		if (data -> nb_philo > 1)
			philo[i].right_fork = &data -> forks[(i + 1)
				% data -> nb_philo];
		else
			philo[i].right_fork = NULL;
		philo[i].ate_x_times = 0;
		philo[i].eat_x_times = data -> eat_x_times;
		philo[i].last_meal_time = get_time_now();
		philo[i].stop = 0;
		philo[i].time_die = data->time_die;
		philo[i].time_eat = data -> time_eat;
		philo[i].time_sleep = data -> time_sleep;
		philo[i].already_ate_max = &data -> already_ate_max;
		philo[i].main_lock = &data -> main_lock;
		philo[i].priv_lock = &data -> priv_lock[i];
		philo[i].write_message = &data -> write_message;
	}
}

int	init_threads(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_time_now();
	while (++i < data -> nb_philo)
		pthread_create(&data -> threads[i], NULL,
			&philo_routine, &data -> philos[i]);
	return (1);
}

int	init_all(t_data *data)
{
	data->philos = malloc(sizeof(t_data) * data -> nb_philo);
	if (!data->philos)
		return (free_all(data), -1);
	data -> threads = malloc(sizeof(pthread_t) * data -> nb_philo);
	if (!data -> threads)
		return (free_all(data), -1);
	if (init_mutex(data) == -1)
		return (-1);
	data -> already_ate_max = 0;
	init_philo(data, data -> philos);
	init_threads(data);
	return (0);
}
