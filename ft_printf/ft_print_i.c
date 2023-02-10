/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:45:57 by tserdet           #+#    #+#             */
/*   Updated: 2022/10/31 16:21:07 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	convertion(int p, int *verification)
{
	char	n;

	n = 48 + p;
	ft_print_c(n, verification);
}

static	int	nbr_figure(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count++;
		n = n * -1;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_print_i(int nb, int *verification)
{
	int	o;
	int	p;
	int	nmbr_figure;

	nmbr_figure = nbr_figure(nb);
	if (nb == -2147483647 -1)
	{
		ft_print_s("-2147483648", verification);
		return (11);
	}
	if (nb < 0)
	{
		ft_print_c('-', verification);
		nb = nb * -1;
	}
	if ((nb > -1) && (nb < 10))
		convertion(nb, verification);
	else
	{
		o = nb / 10;
		p = nb % 10;
		ft_print_i(o, verification);
		convertion(p, verification);
	}
	return (nmbr_figure);
}
