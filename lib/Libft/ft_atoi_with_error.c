/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_with_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 22:42:33 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/09/14 17:32:22 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static bool	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v')
		return (TRUE);
	return (FALSE);
}

static const char	*move_to_digit(const char *str, int *sign)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		*sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	return (str);
}

bool	ft_atoi_with_error(const char *str, int *result)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	str = move_to_digit(str, &sign);
	if (!*str)
		return (FALSE);
	while (ft_isdigit(*str))
	{
		if (num > (LONG_MAX - (*str - '0')) / 10)
			return (false);
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (FALSE);
	if ((sign == 1 && num > INT_MAX) || (sign == -1 && num > -(long)INT_MIN))
		return (FALSE);
	*result = (int)(sign * num);
	return (TRUE);
}

// int	main(void)
// {
// 	const char *str = "-922337203685477581";

// 	printf("Result: %d\n", ft_atoi(str));
// 	printf("Result: %d\n", atoi(str));

// 	return (0);
// }