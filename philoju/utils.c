/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmilesi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 20:34:06 by jmilesi           #+#    #+#             */
/*   Updated: 2024/04/23 20:37:10 by jmilesi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long    ft_atol(const char *s)
{
    int         i;
    int         sign;
    long    res;

    i = 0;
    sign = 1;
    res = 0;
    while (s[i] == ' ' || (s[i]) >= 9 && s[i] <= 13)
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + s[i] - '0';
        i++;
    }
    return (sign * res);
}

int ft_atoi(const char *s)
{
    int     i;
    int     sign;
    int     res;

    i = 0;
    sign = 1;
    res = 0;
    while (s[i] == ' ' || (s[i]) >= 9 && s[i] <= 13)
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')
            sign *= -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + s[i] - '0';
        i++;
    }
    return (sign * res);
}
