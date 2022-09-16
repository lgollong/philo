/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:00:00 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/16 17:17:34 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> //threads mutex
# include <stdlib.h> //malloc free exit
# include <unistd.h> //write usleep
# include <string.h> //memset
# include <stdio.h> //printf
# include <sys/time.h> //gettimeofday

typedef struct s_ph
{
	int				ph_nb;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat_nb;
	pthread_mutex_t	forks;
	
}			t_ph;

int		error(int err);
int		parse_args(t_ph *p,int argc, char **argv);
int		ft_atoi(const char *strn);

#endif