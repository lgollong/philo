/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:42:11 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/17 13:03:48 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *strn)
{
	int	i;
	int	nbr;
	int	sol;

	i = 0;
	nbr = 1;
	sol = 0;
	while (strn[i] == ' ' || strn[i] == '\t' || strn[i] == '\n'
		|| strn[i] == '\r' || strn[i] == '\f' || strn[i] == '\v')
		i++;
	if (strn[i] == '+' || strn[i] == '-')
	{
		if (strn[i] == '-')
			nbr *= -1;
		i++;
	}
	while (strn[i] > 47 && strn[i] < 58)
	{
		sol = sol * 10 + (strn[i] - '0');
		i++;
	}
	return (nbr * sol);
}

long long	get_time(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
