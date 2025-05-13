/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:43:53 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/15 20:22:34 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last);
}
// int main(void)
// {
//     char test[20] = "abcdebg";
//     char *p;

//     p = ft_strrchr(test, 'b');
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
