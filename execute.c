/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:52:51 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/30 17:48:48 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	plump_up(t_ph *p, t_n *r)
{
	pthread_mutex_lock(&(r->forks[p->l_f]));
	print_action(r, (get_time() - r->f_time), p->id, "has taken a fork");
	pthread_mutex_lock(&(r->forks[p->r_f]));
	print_action(r, (get_time() - r->f_time), p->id, "has taken a fork");
	pthread_mutex_lock(&(r->check_meal));
	print_action(r, (get_time() - r->f_time), p->id, "is eating");
	p->l_meal = get_time();
	(p->ate)++;
	pthread_mutex_unlock(&(r->check_meal));
	timing(r->time_eat, r);
	pthread_mutex_unlock(&(r->forks[p->l_f]));
	pthread_mutex_unlock(&(r->forks[p->r_f]));
}

void	*routine(void *phs)
{
	int		i;
	t_ph	*p;
	t_n		*r;

	i = 0;
	p = (t_ph *)phs;
	r = p->r;
	if (p->id % 2)
		usleep(20000);
	while (!(lock_died(r)))
	{
		plump_up(p, r);
		if (lock_fed_up(r))
			break ;
		print_action(r, (get_time() - r->f_time), p->id, "is sleeping");
		timing(r->time_sleep, r);
		print_action(r, (get_time() - r->f_time), p->id, "is thinking");
		i++;
	}
	return (0);
}

void	fed_up_yet(t_n *r, t_ph *p)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&(r->check_meal));
	while (r->must_eat_nb != -1 && i < r->ph_nb
		&& p[i].ate >= r->must_eat_nb)
		i++;
	if (i == r->ph_nb)
	{
		pthread_mutex_lock(&(r->fed));
		r->fed_up = 1;
		pthread_mutex_unlock(&(r->fed));
	}
	pthread_mutex_unlock(&(r->check_meal));
}

void	dead_yet(t_n *r, t_ph *p)
{
	int	i;

	while (!(r->fed_up))
	{
		i = -1;
		while (++i < r->ph_nb && !(r->died))
		{
			pthread_mutex_lock(&(r->check_meal));
			if ((get_time() - p[i].l_meal) > r->time_die)
			{
				print_action(r, (get_time() - r->f_time), i, "died");
				pthread_mutex_lock(&(r->death));
				r->died = 1;
				pthread_mutex_unlock(&(r->death));
			}
			pthread_mutex_unlock(&(r->check_meal));
		}
		if (lock_died(r))
		{
			if (r->ph_nb == 1)
				pthread_mutex_unlock(&(r->forks[p->l_f]));
			break ;
		}
		fed_up_yet(r, p);
	}
}

int	executer(t_n *r)
{
	int		i;
	t_ph	*p;

	i = 0;
	p = r->philo;
	r->f_time = get_time();
	while (i < r->ph_nb)
	{
		if (pthread_create(&(p[i].t_id), NULL, routine, &(p[i])))
			return (2);
		pthread_mutex_lock(&(r->check_meal));
		p[i].l_meal = get_time();
		pthread_mutex_unlock(&(r->check_meal));
		i++;
	}
	dead_yet(r, p);
	exit_programm(r, p);
	return (0);
}
