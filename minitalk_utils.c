/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhamel <malhamel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:53:48 by malhamel          #+#    #+#             */
/*   Updated: 2023/02/18 12:42:39 by malhamel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		if (str[i + 1] == '+')
			return (0);
		sign = -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	my_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		my_putchar('-');
		nbr = nbr * (-1);
	}
	if (nbr < 10)
	{
		my_putchar(nbr + '0');
	}
	else
	{
		my_putnbr(nbr / 10);
		my_putchar(nbr % 10 + '0');
	}
}

void	my_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}
