/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:39:35 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/17 16:59:40 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(t_n *r,int argc, char **argv)
{
	r->ph_nb = ft_atoi(argv[1]);
	r->time_die = ft_atoi(argv[2]);
	r->time_eat = ft_atoi(argv[3]);
	r->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		r->must_eat_nb = ft_atoi(argv[5]);
		if (r->must_eat_nb <= 0)
			return (4);
	}
	else
		r->must_eat_nb = -1;
	if (r->ph_nb < 2 || r->time_die < 0
		|| r->time_eat < 0 || r->time_sleep < 0)
		return (4);
	return (0);
}

void	init_philos(t_n *r)
{
	int	ph;

	ph = r->ph_nb;
	r->philo = malloc(r->ph_nb);
	while (ph)
	{
		r->philo[ph].id = ph;
		r->philo[ph].l_f = ph;
		r->philo[ph].r_f = (ph + 1) % r->ph_nb;
	}
}

int	init_mutex(t_n *r)
{
	int	f;
	int	mutex;

	f = r->ph_nb;
	r->forks = malloc(r->ph_nb);
	while (f)
	{
		mutex = pthread_mutex_init(&(r->forks[f]), NULL);
		if (mutex)
			return (1);
	}
	return (0);
}

int	init_all(t_n *r)
{
	int	mutex;
	int	philo;

	mutex = init_mutex(r);
	if (mutex)
		return (3);
	init_philos(r);
	return (0);
}