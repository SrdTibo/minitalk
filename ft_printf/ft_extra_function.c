/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <thibault@42.fr>                     +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:47:53 by tserdet           #+#    #+#             */
/*   Updated: 2022/07/20 08:50:53 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

int	ft_nombre_chiffre(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

int	ft_nombre_chiffre_p(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		count++;
	while (n > 0)
	{
		count++;
		n = n / 16;
	}
	return (count + 2);
}

int	verification_hexa(int *verification)
{
	*verification = -1;
	return (0);
}
