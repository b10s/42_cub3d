/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:56:53 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/28 15:07:18 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_p;
	const unsigned char	*src_p;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (dst);
	dst_p = (unsigned char *)dst;
	src_p = (const unsigned char *)src;
	i = len;
	if (dst_p > src_p)
	{
		while (i > 0)
		{
			i--;
			dst_p[i] = src_p[i];
		}
		return (dst);
	}
	ft_memcpy(dst, src, len);
	return (dst);
}

// int	main(void)
// {
// 	char dst[20] = "abcde";
// 	char str1[] = "123";
// 	char str2[] = "abcdefghijk";
// 	char str3[] = "123 4 5";

// 	ft_memmove(dst, str1, strlen(str1));
// 	ft_memmove(dst, str2, 3);
// 	ft_memmove(dst, str3, sizeof(str3));

// 	printf("/*----- ft_memcpy -----*/\n");
// 	printf("str1 = %s\n", str1);
// 	printf("str2 = %s\n", str2);
// 	printf("str3 = %s\n", str3);

// 	return (0);
// }