/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:58:01 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/16 17:46:38 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_ph	p;
	int		parse;
	//int		init;
	
	if (argc < 5 || argc > 6)
		return (error(1));
	parse = parse_args(&p, argc, argv);
	if (parse)
		return(error(parse));
	// if (init = create_all(&p))
	// 	return(error(init));
	
	return (0);
}