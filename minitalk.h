/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aammirat <aammirat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 14:15:51 by aammirat          #+#    #+#             */
/*   Updated: 2023/06/19 10:45:08 by aammirat         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(unsigned char c);
void	ft_putnbr(int c);
int		ft_atoi(char *PID);
void	ft_putstr(unsigned char *str);
int		ft_strlen(char *str);

#endif