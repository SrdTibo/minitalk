/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:20:40 by tserdet           #+#    #+#             */
/*   Updated: 2023/01/15 12:25:05 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "../ft_printf/ft_printf.h"

void	descaling_bits(char character, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (character & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
}

int	ft_atoi(const char *thestring)
{
	int	i;
	int	valeur;
	int	moins;

	i = 0;
	valeur = 0;
	moins = 0;
	while ((thestring[i] >= 9 && thestring[i] <= 13) || thestring[i] == 32)
		i++;
	if (thestring[i] == 43 || thestring[i] == 45)
	{
		if (thestring[i] == 45)
			moins++;
		i++;
	}
	while (thestring[i] && (thestring[i] >= 48 && thestring[i] <= 57))
	{
		valeur = ((valeur * 10) + (thestring[i] - 48));
		i++;
	}
	if (moins)
		valeur = -valeur;
	if (!(thestring[i] >= 48 && thestring[i] <= 57) && valeur == 0)
		return (0);
	return (valeur);
}


int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			descaling_bits(argv[2][i], pid);
			i++;
		}
	}
	else
		ft_printf("parameters: <executable> <server> <string>\n");
	return (0);
}
