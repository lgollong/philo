/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:00:00 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/29 18:07:01 by lgollong         ###   ########.fr       */
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
	int			ate;
	long long	l_meal;
	struct s_n	*r;
	pthread_t	t_id;
}				t_ph;

typedef struct s_n
{
	int				ph_nb;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat_nb;
	int				fed_up;
	int				died;
	long long		f_time;
	t_ph			philo[1024];
	pthread_mutex_t	forks[1024];
	pthread_mutex_t	msg;
	pthread_mutex_t	check_meal;
	pthread_mutex_t	death;
	pthread_mutex_t	fed;
}			t_n;

int			error(int err);
int			parse_args(t_n *r, int argc, char **argv);
int			ft_atoi(const char *strn);
long long	get_time(void);
void		print_action(t_n *r, long long time, int id, char *action);
int			init_all(t_n *r);
int			executer(t_n *r);
void		timing(long long time, t_n *r);
int			lock_died(t_n *r);
void		exit_programm(t_n *r, t_ph *p);
int			lock_fed_up(t_n *r);

#endif