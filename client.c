/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:08:43 by aammirat          #+#    #+#             */
/*   Updated: 2023/06/19 11:44:59 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(unsigned char c, int v)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c % 2)
			kill(v, SIGUSR1);
		else
			kill(v, SIGUSR2);
		usleep(50);
		c = c / 2;
		i--;
	}
}

void	send_int(int c, int v)
{
	int	i;

	i = 31;
	while (i > 0)
	{
		if (c % 2)
			kill(v, SIGUSR1);
		else
			kill(v, SIGUSR2);
		usleep(50);
		c = c / 2;
		i--;
	}
}

void	send_str(char *str, int v)
{
	int	i;

	i = 0;
	usleep(50);
	send_int(ft_strlen(str), v);
	while (str[i])
	{
		send_char(str[i], v);
		i++;
	}
	send_char('\0', v);
}

int	main(int argc, char *argv[])
{
	int	v;

	if (argc != 3)
		write (1, "invalid arg nbr\n", 16);
	else
	{
		v = ft_atoi(argv[1]);
		if (kill(v, SIGUSR1) == -1)
			write (1, "Invalid PID\n", 12);
		else
			send_str(argv[2], v);
	}
	return (0);
}
