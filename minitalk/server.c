/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkasmi <abkasmi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 09:55:57 by abkasmi           #+#    #+#             */
/*   Updated: 2022/01/11 16:42:44 by abkasmi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle(int n)
{
	static int	i = 128;
	static int	b = 0;

	if (n == 31)
		b = b + i;
	i = i / 2;
	if (i == 0)
	{
		ft_putchar_fd(b, 1);
		i = 128;
		b = 0;
	}
}

int	main(int ac, char **av)
{
	pid_t				pid;

	(void)av;
	pid = getpid();
	if (ac == 1)
	{
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
		signal(SIGUSR1, handle);
		signal(SIGUSR2, handle);
		while (1)
		{
			pause();
		}
	}
	else
		write(1, "use : ./server\n", 16);
	return (0);
}
