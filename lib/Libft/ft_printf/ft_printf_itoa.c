/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 13:57:01 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/20 23:11:03 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	count_digit_decimal(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	set_number(unsigned int n, int sign, int n_len, char **n_str)
{
	if (sign)
		(*n_str)[0] = '-';
	(*n_str)[n_len + sign] = '\0';
	while (n_len > 0)
	{
		n_len--;
		(*n_str)[n_len + sign] = (n % 10) + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int				is_negative;
	int				n_len;
	char			*n_str;
	unsigned int	un;

	is_negative = 0;
	n_len = 0;
	if (n < 0)
	{
		is_negative = 1;
		un = (unsigned int)(n * -1);
	}
	else
		un = (unsigned int)n;
	n_len = count_digit_decimal(un);
	n_str = (char *)malloc(sizeof(char) * (is_negative + n_len + 1));
	if (n_str == NULL)
		return (NULL);
	set_number(un, is_negative, n_len, &n_str);
	return (n_str);
}
