/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:57:43 by jmilesi           #+#    #+#             */
/*   Updated: 2024/05/06 15:57:47 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_fork(int philo_id)
{
    pthread_mutex_lock(&mutex);
    state[philo_id] = HUNGRY;
    printf("Philosopher %d is hungry\n", philo_id + 1);
    test(philo_id);
    pthread_mutex_unlock(&mutex);
}

void    put_fork(int philo_id)
{
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    printf("Philosopher %d is thinking\n", i + 1);
    test(phil[i - 1]);
    test(phil[i]);
    pthread_mutex_unlock(&mutex);
}
