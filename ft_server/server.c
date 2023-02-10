/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:20:36 by tserdet           #+#    #+#             */
/*   Updated: 2023/01/16 10:05:26 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"

void	display(int sig)
{
	static char	cha = 0;
	static int	compt = 0;

	cha <<= 1;
	if (sig == SIGUSR1)
		cha += 1;
	compt++;
	if (compt == 8)
	{
		write(1, &cha, 1);
		cha = 0;
		compt = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server PID = %d\n", pid);
	ft_printf("waiting...\n");
	signal(SIGUSR1, display);
	signal(SIGUSR2, display);
	while (1)
		pause();
	return (0);
}
