/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:41:31 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/17 20:47:36 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

// int main(void)
// {
//     char test[20] = "abcdefg";
//     char *p;

//     p = ft_strchr(test, 'b');
//     if (p != NULL)
//     {
//         printf("ans:%s\n", p);
//     }
//     else
//     {
//         printf("not found\n");
//     }

//     return (0);
// }