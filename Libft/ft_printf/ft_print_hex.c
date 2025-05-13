/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 14:48:35 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/20 23:10:17 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	count_digit_hex(unsigned long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*get_hex_type(int lower_case)
{
	char	*hex_type;

	if (lower_case)
		hex_type = "0123456789abcdef";
	else
		hex_type = "0123456789ABCDEF";
	return (hex_type);
}

int	convert_hex(unsigned long long input_nbr, int lower_case)
{
	char	*hex_type;
	char	*hex_digits;
	int		index;
	int		len;
	int		size;

	if (input_nbr == 0)
		return (print_char('0'));
	hex_type = get_hex_type(lower_case);
	size = count_digit_hex(input_nbr);
	hex_digits = (char *)malloc(size + 1);
	if (hex_digits == NULL)
		return (0);
	index = size - 1;
	while (input_nbr > 0 && index >= 0)
	{
		hex_digits[index--] = hex_type[input_nbr % 16];
		input_nbr /= 16;
	}
	hex_digits[size] = '\0';
	len = print_string(hex_digits);
	free(hex_digits);
	return (len);
}

int	convert_pointer(void *ptr)
{
	uintptr_t	u_ptr;
	int			len;

	u_ptr = (uintptr_t)ptr;
	write(1, "0x", 2);
	len = convert_hex(u_ptr, 1);
	return (len + 2);
}
