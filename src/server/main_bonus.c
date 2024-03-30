/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:17:13 by romoreno          #+#    #+#             */
/*   Updated: 2023/10/29 17:45:04 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	ft_handler(int signal, siginfo_t *siginfo, void *context)
{
	static int	bit_number = 0;
	static char	c = 0;

	(void) context;
	if (signal == SIGUSR1 || signal == SIGUSR2)
	{
		if (signal == SIGUSR1)
			c = c << 1;
		if (signal == SIGUSR2)
			c = c << 1 | 1;
		bit_number++;
		if (bit_number == 8)
		{
			write(1, &c, 1);
			if (c == 0)
			{
				write (1, "\n", 1);
				kill(siginfo->si_pid, SIGUSR1);
			}
			bit_number = 0;
			c = 0;
		}
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_sigaction = ft_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("Server PID: %d \n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
