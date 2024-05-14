/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:58:31 by jmilesi           #+#    #+#             */
/*   Updated: 2024/04/23 12:05:05 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_message(char *message, int print_usage)
{
	put_string(message, STDOUT_FILENO);
	put_string("\n", STDOUT_FILENO);
	if (print_usage == 1)
	{
		printf("Usage: ./philo <number_of_philosophers> <time_to_die> ");
		printf("<time_to_eat> <time_to_sleep> ");
		printf("[number_of_times_each_philosopher_must_eat]\n");
	}
	return (EXIT_FAILURE);
}

int	error_message_args(t_data *data)
{
	if (table -> philos_num < 1)
		return (error_message("There has to be at least 1", 0));
	if (table -> time_to_die <= 0)
		return (error_message("The time_to_die has to be greater than 0", 0));
	if (table -> time_to_eat <= 0)
		return (error_message("The time_to_eat has to be greater than 0", 0));
	if (table -> time_to_sleep <= 0)
		return (error_message("The time_to_sleep has to be greater than 0", 0));
	return (0);
}

void	print_info(t_data_philo *philo, char *action)
{
	long int	time;

	pthread_mutex_lock(philo -> write_message);
	time = get_time_now() - *philo -> start_time;
	if (time >= 0 && time <= 2147483647 && alive_check(philo))
		printf("%d %d %s\n", (int)time, philo -> philo_id, action);
	pthread_mutex_unlock(philo -> write_message);
}
