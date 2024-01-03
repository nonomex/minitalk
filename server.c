/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:08:31 by aammirat          #+#    #+#             */
/*   Updated: 2023/06/19 13:49:07 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_step;

char	make_char(int sig, int i)
{
	unsigned char	c;
	static int		bol[8];

	c = 0;
	if (sig == SIGUSR1)
		bol[7 - i] = 1;
	else
		bol[7 - i] = 0;
	i++;
	if (i == 8)
	{
		i = 0;
		while (i < 8)
		{
			c = c * 2;
			if (bol[i])
				c++;
			i++;
		}
		return (c);
	}
	return (1);
}

int	make_int(int sig, int i)
{
	int			size;
	static int	buff[31];

	size = 0;
	if (sig == SIGUSR1)
		buff[30 - i] = 1;
	else
		buff[30 - i] = 0;
	i++;
	if (i == 31)
	{			
		i = 0;
		while (i < 31)
		{
			size = size * 2;
			if (buff[i])
				size++;
			i++;
		}
		return (size);
	}
	else
		return (i);
}

int	sig_completchar(int sig, unsigned char *ret, int i)
{
	if (i % 8 == 7)
	{
		ret[i / 8] = make_char(sig, 7);
		if (!ret[i / 8])
		{
			ft_putstr(ret);
			free(ret);
			g_step = 0;
			return (0);
		}
		else
			i++;
	}
	else
		i += make_char(sig, i % 8);
	return (i);
}

void	sig_receiv(int sig, siginfo_t *inf, void *gain)
{
	static int				i = 0;
	static unsigned char	*ret;

	(void)gain;
	(void)inf;
	if (g_step == 1)
	{
		i = make_int(sig, i);
		if (i == 30)
			g_step = 2;
	}
	else if (g_step == 2)
	{
		ret = malloc(make_int(sig, 30) * sizeof(unsigned char) + 1);
		if (!ret)
			exit(1);
		i = 0;
		g_step = 3;
	}
	else if (g_step == 3)
		i = sig_completchar(sig, ret, i);
	else
		g_step = 1;
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	g_step = 0;
	write(1, "serveur PID : ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sa.sa_sigaction = sig_receiv;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		;
	return (0);
}
