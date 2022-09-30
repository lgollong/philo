/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:58:01 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/30 16:08:38 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_programm(t_n *r, t_ph *p)
{
	int	i;

	i = 0;
	while (i < r->ph_nb)
	{
		pthread_join(p[i].t_id, NULL);
		i++;
	}
	i = 0;
	while (i < r->ph_nb)
	{
		pthread_mutex_destroy(&(r->forks[i]));
		i++;
	}
	pthread_mutex_destroy(&(r->msg));
	pthread_mutex_destroy(&(r->check_meal));
	pthread_mutex_destroy(&(r->death));
	pthread_mutex_destroy(&(r->fed));
}

int	main(int argc, char **argv)
{
	t_n		r;
	int		parse;
	int		init;
	int		exec;

	if (argc < 5 || argc > 6)
		return (error(1));
	parse = parse_args(&r, argc, argv);
	if (parse)
		return (error(parse));
	init = init_all(&r);
	if (init)
		return (error(init));
	exec = executer(&r);
	if (exec)
		return (error(exec));
	return (0);
}
