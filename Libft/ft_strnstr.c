/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:36:52 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/15 22:06:16 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (needle == NULL || needle_len == 0)
		return ((char *)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && haystack[i + j] != '\0' && needle[j] != '\0'
			&& haystack[i + j] == needle[j])
		{
			j++;
			if (j == needle_len)
				return ((char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	*haystack;
// 	const char	*needle1;
// 	const char	*needle2;
// 	size_t		len;
// 	char		*result1;
// 	char		*result2;

// 	haystack = "This is a simple example.";
// 	needle1 = "simple";
// 	needle2 = "not_found";
// 	len = 20;
// 	// needle1 を haystack で検索
// 	result1 = ft_strnstr(haystack, needle1, len);
// 	if (result1 != NULL)
// 	{
// 		printf("Needle1 found at position: %ld\n", result1 - haystack);
// 	}
// 	else
// 	{
// 		printf("Needle1 not found.\n");
// 	}
// 	// needle2 を haystack で検索
// 	result2 = ft_strnstr(haystack, needle2, len);
// 	if (result2 != NULL)
// 	{
// 		printf("Needle2 found at position: %ld\n", result2 - haystack);
// 	}
// 	else
// 	{
// 		printf("Needle2 not found.\n");
// 	}
// 	return (0);
// }
