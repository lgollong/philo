/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:39:35 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/16 17:45:50 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parse_args(t_ph *p,int argc, char **argv)
{
	p->ph_nb = ft_atoi(argv[1]);
	p->time_die = ft_atoi(argv[2]);
	p->time_eat = ft_atoi(argv[3]);
	p->time_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		p->must_eat_nb = ft_atoi(argv[5]);
		if (p->must_eat_nb <= 0)
			return (4);
	}
	else
		p->must_eat_nb = -1;
	if (p->ph_nb < 2 || p->time_die < 0
		|| p->time_eat < 0 || p->time_sleep < 0)
		return (4);
	return (0);
}

// int	create_all(t_ph *p)
// {
	
// }