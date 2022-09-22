/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:42:11 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/22 19:11:06 by lgollong         ###   ########.fr       */
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

void	timing(long long time, t_n *r)
{
	long long	i;

	i = get_time();
	while (!(r->died))
	{
		if ((get_time() - i) >= time)
			break ;
		usleep(50);
	}
}

void	print_action(t_n *r, long long time, int id, char *action)
{
	pthread_mutex_lock(&(r->msg));
	if (!(r->died))
	{
		printf("%lld ", time);
		printf("%d ", id + 1);
		printf("%s\n", action);
	}
	pthread_mutex_unlock(&(r->msg));
}
