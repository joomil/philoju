/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:55:25 by jmilesi           #+#    #+#             */
/*   Updated: 2024/05/06 15:55:27 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philo_routine(void *arg)
{
    t_data	*philo;

	philo = (t_data *)arg;
	if (philo->id % 2 == 0)
		new_sleep(philo->time_eat * 0.9);
	while (alive_check(philo))
	{
		if (meal(philo) == -1)
			return (NULL);
		if (!alive_check(philo))
			return (NULL);
		print_info(philo, "is sleeping");
		new_sleep(philo->time_sleep);
		print_info(philo, "is thinking");
	}
	return (NULL);
}

void	update_meal_status(t_philo *philo)
{
	pthread_mutex_lock(philo -> priv_lock);
	philo -> last_meal_time = get_time_now();
	pthread_mutex_unlock(philo -> priv_lock);
	if (philo -> eat_x_times != 0)
	{
		if (++philo -> ate_x_times == philo -> eat_x_times)
		{
			pthread_mutex_lock(philo -> main_lock);
			*philo -> already_ate_max += 1;
			pthread_mutex_unlock(philo -> main_lock);
		}
	}
}

int	meal(t_philo *philo)
{
	if (!alive_check(philo))
		return (-1);
	pthread_mutex_lock(philo -> left_fork);
	print_info(philo, "has taken a fork");
	if (!alive_check(philo))
		return (pthread_mutex_unlock(philo -> left_fork), -1);
	if (philo -> right_fork == NULL)
		return (pthread_mutex_unlock(philo -> left_fork),
			new_sleep(philo -> time_to_die * 1.1), -1);
	pthread_mutex_lock(philo -> right_fork);
	print_info(philo, "has taken a fork");
	print_info(philo, "is eating");
	if (!alive_check(philo))
		return (pthread_mutex_unlock(philo -> left_fork),
			pthread_mutex_unlock(philo -> right_fork), -1);
	update_meal_status(philo);
	if (!alive_check(philo))
		return (pthread_mutex_unlock(philo -> left_fork),
			pthread_mutex_unlock(philo -> right_fork), -1);
	new_sleep(philo -> time_to_eat);
	pthread_mutex_unlock(philo -> right_fork);
	pthread_mutex_unlock(philo -> left_fork);
	return (0);
}

int	alive_check(t_philo *philo)
{
	pthread_mutex_lock(philo -> main_lock);
	if (!philo -> stop)
	{
		pthread_mutex_unlock(philo -> main_lock);
		return (1);
	}
	pthread_mutex_unlock(philo -> main_lock);
	return (0);
}
