/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:50:57 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/05 13:53:23 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * s1_len + s2_len + 1);
	if (result == NULL)
		return (NULL);
	dest = result;
	ft_memcpy(dest, s1, s1_len);
	ft_memcpy(dest + s1_len, s2, s2_len);
	result[s1_len + s2_len] = '\0';
	return (result);
}

// int	main(void)
// {
// 	const char *s1 = "Hello, |";
// 	const char *s2 = "|World!";
// 	char *result = ft_strjoin(s1, s2);

// 	if (result != NULL)
// 	{
// 		// Output the joined string
// 		printf("Joined String: %s\n", result);

// 		// Don't forget to free the allocated memory
// 		free(result);
// 	}
// 	else
// 	{
// 		fprintf(stderr, "Memory allocation failed.\n");
// 	}

// 	return (0);
// }