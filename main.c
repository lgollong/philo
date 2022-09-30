/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:58:01 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/30 17:49:26 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	str_is_digit(int argc, char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

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
		return (ft_error(1));
	if (str_is_digit(argc, argv))
		return (ft_error(4));
	parse = parse_args(&r, argc, argv);
	if (parse)
		return (ft_error(parse));
	init = init_all(&r);
	if (init)
		return (ft_error(init));
	exec = executer(&r);
	if (exec)
		return (ft_error(exec));
	return (0);
}
