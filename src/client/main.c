/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreno <romoreno@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:21:49 by romoreno          #+#    #+#             */
/*   Updated: 2023/10/31 09:21:49 by romoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <signal.h>

void	ft_send_char(int pid, char c)
{
	int	i;

	i = 1;
	while (i <= 8)
	{
		if ((c >> (8 - i)) & 1)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		i++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid && argv[2])
		{
			while (*argv[2] != '\0')
			{
				ft_send_char(pid, *argv[2]);
				argv[2]++;
			}
			ft_send_char(pid, '\0');
		}
	}
	return (0);
}
