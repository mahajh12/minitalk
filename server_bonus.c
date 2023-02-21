/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:12:43 by malhamel          #+#    #+#             */
/*   Updated: 2023/02/18 12:36:27 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	recieve(int sig)
{
	static int	count = 0;
	static int	bit = 0;

	if (sig == SIGUSR1)
		bit += 1 << (7 - count);
	count++;
	if (count == 8)
	{
		my_putchar(bit);
		count = 0;
		bit = 0;
	}
}

int	main(void)
{
	int	pid_s;

	pid_s = getpid();
	my_putstr("The current pid of this process: ");
	my_putnbr(pid_s);
	my_putchar('\n');
	signal(SIGUSR1, recieve);
	signal(SIGUSR2, recieve);
	while (1)
		pause();
}
