/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:44:02 by aammirat          #+#    #+#             */
/*   Updated: 2023/06/19 10:45:02 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(unsigned char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int c)
{
	if (c < 10)
		ft_putchar(c + '0');
	else
	{
		ft_putnbr(c / 10);
		ft_putchar(c % 10 + '0');
	}
}

int	ft_atoi(char *PID)
{
	int	v;
	int	i;

	i = 0;
	while (PID[i])
		i++;
	v = 0;
	i = 0;
	while (PID[i])
	{
		v = v * 10 + (PID[i] - 48);
		i++;
	}
	return (v);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(unsigned char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
