/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:58:01 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/20 17:09:31 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
