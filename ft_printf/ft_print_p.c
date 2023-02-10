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

int	ft_print_p(unsigned long long nb, int *verification)
{
	int		resultat;
	char	*str;
	int		i;
	char	*base;

	base = "0123456789abcdef";
	i = ft_nombre_chiffre_p(nb);
	resultat = 0;
	str = NULL;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (verification_hexa(verification));
	str[i] = 0;
	while (i > 2)
	{
		resultat = nb % 16;
		nb = nb / 16;
		str[--i] = base[resultat];
	}
	str[0] = '0';
	str[1] = 'x';
	i = ft_print_s(str, verification);
	free(str);
	return (i);
}
