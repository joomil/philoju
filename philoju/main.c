/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:57:28 by jmilesi           #+#    #+#             */
/*   Updated: 2024/05/06 15:57:30 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac < 5 || ac > 6)
		return (error_message("./philo takes 4 or 5 args\n"));
	data = malloc(sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	set_args(table, ac, av);

}
