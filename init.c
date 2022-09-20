/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:39:35 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/20 17:10:11 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(t_n *r, int argc, char **argv)
{
	r->ph_nb = ft_atoi(argv[1]);
	r->time_die = ft_atoi(argv[2]);
	r->time_eat = ft_atoi(argv[3]);
	r->time_sleep = ft_atoi(argv[4]);
	r->died = 0;
	r->fed_up = 0;
	if (argc == 6)
	{
		r->must_eat_nb = ft_atoi(argv[5]);
		if (r->must_eat_nb <= 0)
			return (4);
	}
	else
		r->must_eat_nb = -1;
	if (r->ph_nb < 2 || r->time_die < 0 || r->ph_nb >= 1024
		|| r->time_eat < 0 || r->time_sleep < 0)
		return (4);
	return (0);
}

void	init_philos(t_n *r)
{
	int	ph;

	ph = r->ph_nb;
	while (ph > 0)
	{
		r->philo[ph].id = ph;
		r->philo[ph].l_f = ph;
		r->philo[ph].r_f = (ph + 1) % r->ph_nb;
		r->philo[ph].ate = 0;
		r->philo[ph].l_meal = 0;
		r->philo[ph].r = r;
		ph--;
	}
}

int	init_mutex(t_n *r)
{
	int	f;
	int	mutex;

	f = r->ph_nb;
	while (f > 0)
	{
		mutex = pthread_mutex_init(&(r->forks[f]), NULL);
		if (mutex)
			return (1);
		f--;
	}
	if (pthread_mutex_init(&(r->msg), NULL))
		return (1);
	if (pthread_mutex_init(&(r->check_meal), NULL))
		return (1);
	return (0);
}

int	init_all(t_n *r)
{
	int	mutex;

	mutex = init_mutex(r);
	if (mutex)
		return (3);
	init_philos(r);
	return (0);
}
