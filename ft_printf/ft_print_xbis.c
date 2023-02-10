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

int	ft_print_xbis(unsigned int nb, int *verification)
{
	int		resultat;
	char	*str;
	int		i;
	char	*base;

	base = "0123456789ABCDEF";
	i = ft_nombre_chiffre(nb);
	resultat = 0;
	str = NULL;
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (verification_hexa(verification));
	str[i] = 0;
	while (i > 0)
	{
		resultat = nb % 16;
		nb = nb / 16;
		str[--i] = base[resultat];
	}
	i = ft_print_s(str, verification);
	free(str);
	return (i);
}
