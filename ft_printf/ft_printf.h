/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tserdet <tserdet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:45:57 by tserdet           #+#    #+#             */
/*   Updated: 2022/10/31 16:21:07 by tserdet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_strlen(char *c);
int				ft_nombre_chiffre(unsigned int n);
int				ft_nombre_chiffre_p(unsigned long long n);
int				verification_hexa(int *verification);
int				ft_print_c(char c, int *verification);
int				ft_print_s(char *c, int *verification);
int				ft_print_d(int nbr, int *verification);
int				ft_print_i(int nbr, int *verification);
unsigned int	ft_print_u(unsigned	int nb, int *verification);
int				ft_print_modulo(int *verification);
int				ft_print_x(unsigned int nb, int *verification);
int				ft_print_xbis(unsigned int nb, int *verification);
int				ft_print_p(unsigned long long nb, int *verification);
int				ft_printf(const char *str, ...);
#endif
