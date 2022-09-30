/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgollong <lgollong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:35:23 by lgollong          #+#    #+#             */
/*   Updated: 2022/09/30 17:42:44 by lgollong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_error(char *str)
{
	int	i;

	i = 0;
	write(2, " * Error: ", 10);
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	ft_error(int err)
{
	if (err == 1)
		write_error("Wrong amount of arguments\n");
	if (err == 2)
		write_error("Failed to create threads\n");
	if (err == 3)
		write_error("Failed to create mutex\n");
	if (err == 4)
		write_error("At least one argument is wrong\n");
	return (0);
}
