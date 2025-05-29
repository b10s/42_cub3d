/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:42:14 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/14 22:11:43 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		count_digit_hex(unsigned long long n);
char	*get_hex_type(int lower_case);
int		convert_hex(unsigned long long input_nbr, int lower_case);
int		convert_pointer(void *ptr);
// int		count_digit_decimal(unsigned int n);
// void	set_number(unsigned int n, int sign, int n_len, char **n_str);
// char	*ft_itoa(int n);
int		print_d_i(int nbr);
int		print_u(unsigned int nbr);
int		count_strlen(const char *str);
int		print_char(char c);
int		print_string(char *str);
int		ft_printf(const char *format, ...);

#endif