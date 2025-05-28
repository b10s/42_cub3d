/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 18:13:30 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/15 21:44:57 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	s_len;
	size_t	i;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	result = (char *)malloc(s_len + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[s_len] = '\0';
	return (result);
}

// char	f_tolower(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'A' && c <= 'Z')
// 		c = c + ('a' - 'A');
// 	return (c);
// }

// int	main(void)
// {
// 	char const	*str;
// 	char		*result;

// 	str = "ABCDE";
// 	result = ft_strmapi(str, f_tolower);
// 	printf("%s\n", result);
// 	return (0);
// }
