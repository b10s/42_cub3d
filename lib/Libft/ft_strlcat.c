/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 21:14:31 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/20 23:05:25 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// Add requirements not written in the specification
// dst == NULL && dstsize ==0

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	maxcpsize;
	size_t	i;

	dst_len = 0;
	if (dst != NULL)
		dst_len = ft_strlen(dst);
	src_len = ft_strlen((char *)src);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	maxcpsize = dstsize - dst_len - 1;
	i = 0;
	while (i < maxcpsize && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	const char	*src;
// 	size_t		dest_size;
// 	size_t		result;

// 	char dest[13] = "Hello, ";
// 	src = "world!";
// 	dest_size = sizeof(dest);
// 	printf("Before strlcat:\n");
// 	printf("dest: %s\n", dest);
// 	printf("src: %s\n", src);
// 	result = ft_strlcat(dest, src, 6);
// 	printf("\nAfter strlcat:\n");
// 	printf("dest: %s\n", dest);
// 	printf("Result: %zu\n", result);
// 	return (0);
// }
