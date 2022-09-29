/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:42:11 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/29 17:10:25 by lgollong         ###   ########.fr       */
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

void	timing(long long time, t_n *r)
{
	long long	i;

	i = get_time();
	while (!(lock_died(r)))
	{
		if ((get_time() - i) >= time)
			break ;
	}
}

void	print_action(t_n *r, long long time, int id, char *action)
{
	pthread_mutex_lock(&(r->msg));
	if (!(lock_died(r)))
	{
		printf("%lld ", time);
		printf("%d ", id + 1);
		printf("%s\n", action);
	}
	pthread_mutex_unlock(&(r->msg));
}

int	lock_died(t_n *r)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(r->death));
	if (r->died == 1)
		i = 1;
	pthread_mutex_unlock(&(r->death));
	return (i);
}

int	lock_fed_up(t_n *r)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(r->fed));
	if (r->fed_up == 1)
		i = 1;
	pthread_mutex_unlock(&(r->fed));
	return (i);
}
