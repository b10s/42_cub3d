/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 21:25:36 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/04 12:55:26 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int	main(void)
// {
// 	long	i;

// 	i = 0;
// 	ft_putchar_fd(i, 1);
// 	ft_putchar_fd('\n', 1);
// 	ft_putchar_fd('0', 1);
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }