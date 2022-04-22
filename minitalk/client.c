/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:36:54 by abkasmi           #+#    #+#             */
/*   Updated: 2022/01/11 11:22:28 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	convert(int pid, int x)
{
	int	bin;

	bin = 128;
	while (bin)
	{
		if (x / bin)
		{
			if (kill(pid, SIGUSR2) == -1)
				return (write(1, "Error!", 6));
			x -= bin;
		}
		else
			if (kill(pid, SIGUSR1) == -1)
				return (write(1, "Error!", 6));
		bin /= 2;
		usleep(250);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
		{
			convert(pid, av[2][i]);
			i++;
		}
	}
	else
		write(1, "use : ./client [PID][string to be transmitted]\n", 48);
	return (0);
}