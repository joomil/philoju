/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:54:16 by jmilesi           #+#    #+#             */
/*   Updated: 2024/04/23 20:53:41 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_inputs(int ac, char **av)
{
	int	i;
	int	j;

	if (ac < 5 || ac > 6)
		return (error_message("./philo takes 4 or 5 args\n"));
	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (!ft_isdigit(av[i][j]))
			return (error_message("Only numbers"));
		if ()
	}
}

void	set_args(t_data *data, int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (check_inputs(av[i]) != 0)
			return ();
	}
	data->nb_philo = atol(av[1]);
	if (data->nb_philo > 200)
	{
		printf("Max 200 philos\n");
		exit(EXIT_FAILURE);
	}
	data->time_die = atol(av[2]);
	data->time_eat = atol(av[3]);
	data->time_sleep = atol(av[4]);
	if (data->time_die < 60 || data->time_eat < 60 ||data->time_sleep < 60)
		error_message("Use time stamps greater than 60 ms\n");
	if (av[5])
		data->nb_meals = atol(av[5]);
	else
		data->nb_meals = -1;
}
