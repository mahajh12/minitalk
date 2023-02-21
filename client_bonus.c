/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:12:30 by malhamel          #+#    #+#             */
/*   Updated: 2023/02/20 13:32:24 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send(int pid, int decimal)
{
	int	i;

	i = 1 << 7;
	while (i > 0)
	{
		if (decimal & i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i = i / 2;
	}
}

int	main(int argc, char *argv[])
{
	int		pid_s;
	char	*str_to_send;
	int		i;

	if (argc > 3 || argc < 3)
	{
		my_putstr("Usage: ./client [server PID] [message]\n");
	}
	if (argc == 3)
	{
		pid_s = ft_atoi(argv[1]);
		if (pid_s < 0)
		{
			my_putstr("Invalid");
			exit(0);
		}
		str_to_send = argv[2];
		i = 0;
		while (str_to_send[i])
		{
			send(pid_s, str_to_send[i]);
			i++;
		}
	}
	return (0);
}
