/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:48:29 by jmilesi           #+#    #+#             */
/*   Updated: 2024/04/23 23:25:15 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct	s_philo
{
	t_data	*data;
	int		id;
	long	meals_counter;
	int		count_eat;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;

}				t_philo;

typedef struct	s_data
{
	long		nb_philo;
	long		time_die;
	long		time_eat;
	long		time_sleep;
	long		nb_meals;
	long long	start_time;
	t_fork		*forks;
}				t_data;

typedef struct	s_fork
{
	pthread_mutex_t	fork;
}		t_fork;

int	init_all(t_data *data);

/* Utils */

long    ft_atol(const char *s);
int		ft_atoi(const char *s);

#endif
