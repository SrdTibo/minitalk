/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:45:57 by tserdet           #+#    #+#             */
/*   Updated: 2022/12/16 13:58:02 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	verification_end(int *verification, int value)
{
	if (*verification == -1)
		return (-1);
	return (value);
}

int	launch_function(va_list args, char str, int *verification)
{
	int	value;

	value = 0;
	if (str == 'c')
		value = (ft_print_c(va_arg(args, int), verification));
	else if (str == 's')
		value = (ft_print_s(va_arg(args, char *), verification));
	else if (str == 'p')
		value = (ft_print_p(va_arg(args, unsigned long long), verification));
	else if (str == 'd')
		value = (ft_print_d(va_arg(args, int), verification));
	else if (str == 'i')
		value = (ft_print_i(va_arg(args, int), verification));
	else if (str == 'u')
		value = (ft_print_u(va_arg(args, unsigned int), verification));
	else if (str == 'x')
		value = (ft_print_x(va_arg(args, int), verification));
	else if (str == 'X')
		value = (ft_print_xbis(va_arg(args, int), verification));
	else if (str == '%')
		value = (ft_print_modulo(verification));
	return (value);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		value;
	int		verification;

	i = 0;
	value = 0;
	verification = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			value += launch_function(args, str[i], &verification);
		}
		else
			value += ft_print_c(str[i], &verification);
		i++;
	}
	va_end(args);
	return (verification_end(&verification, value));
}
