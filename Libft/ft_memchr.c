/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 18:56:01 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/25 21:47:34 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*su;
	size_t				i;

	su = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (su[i] == (unsigned char)c)
			return ((void *)(su + i));
		i++;
	}
	return (NULL);
}
// int	main(void)
// {
// 	const char str[] = "Hello, World!";
// 	char target_char = 'E';

// 	// ft_memchr 関数を使用して文字 'W' を検索
// 	void *result = ft_memchr(str, target_char, sizeof(str));

// 	if (result != NULL)
// 	{
// 		// 文字が見つかった場合
// 		printf("Character '%c' found at position: %ld\n", target_char,
// 			(char *)result - str);
// 	}
// 	else
// 	{
// 		// 文字が見つからなかった場合
// 		printf("Character '%c' not found.\n", target_char);
// 	}

// 	return (0);
// }