/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:00:00 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/17 15:43:06 by lgollong         ###   ########.fr       */
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
	int			id;
	int			l_f;
	int			r_f;
	
}				t_ph;

typedef struct s_n
{
	int				ph_nb;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat_nb;
	t_ph			*philo;
	pthread_mutex_t	*forks;
	
}			t_n;

int		error(int err);
int		parse_args(t_n *r,int argc, char **argv);
int		ft_atoi(const char *strn);
long long	get_time(void);

#endif