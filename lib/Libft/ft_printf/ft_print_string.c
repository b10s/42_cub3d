/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:41:28 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/02/04 13:33:19 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	count_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	print_char(char c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	write(1, &uc, 1);
	return (1);
}

int	print_string(char *str)
{
	int	len;

	if (str == NULL)
	{
		len = write(1, "(null)", 6);
	}
	else
	{
		len = count_strlen(str);
		write(1, str, len);
	}
	return (len);
}

int	print_d_i(int nbr)
{
	int		len;
	char	*str_n;

	str_n = ft_itoa(nbr);
	if (str_n == NULL)
		return (-1);
	len = count_strlen(str_n);
	write(1, str_n, len);
	free(str_n);
	return (len);
}

int	print_u(unsigned int nbr)
{
	char	*decimal_type;
	char	*decimal_digits;
	int		index;
	int		len;

	if (nbr == 0)
		return (print_char('0'));
	decimal_type = "0123456789";
	decimal_digits = (char *)malloc(11);
	if (decimal_digits == NULL)
		return (0);
	index = 10;
	while (nbr > 0 && index >= 0)
	{
		decimal_digits[index] = decimal_type[nbr % 10];
		nbr /= 10;
		index--;
	}
	len = print_string(&decimal_digits[index + 1]);
	free(decimal_digits);
	return (len);
}
