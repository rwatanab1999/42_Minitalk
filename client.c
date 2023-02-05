/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwatanab <wtnbrn1999@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 07:57:28 by rwatanab          #+#    #+#             */
/*   Updated: 2023/02/05 13:33:34 by rwatanab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	a_to_l(const char *s)
{
	long	num;
	int		index;

	index = 0;
	num = 0;
	while ((s[index] >= '0') && (s[index] <= '9'))
	{
		if ((num != (num * 100) / 100))
		{
			num = num * 10;
			if (num <= LONG_MAX && s[index] - '0' < 7)
				return ((((num + (s[index] - '0')) * 10) / 10));
			else
				return ((int)LONG_MAX);
		}
		num = num * 10 + s[index++] - '0';
	}
	if (s[index] != '\0')
		return (-1);
	return ((int)num);
}

int	ft_atoi_mini(const char *string)
{
	int	num;

	num = a_to_l(string);
	return (num);
}

void	send_signal(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi_mini(argv[1]);
		if (pid < 100 || 99999 < pid)
			return (1);
		while (argv[2][i] != '\0')
		{
			send_signal(pid, argv[2][i]);
			i++;
		}
	}
	else
		return (1);
	return (0);
}
