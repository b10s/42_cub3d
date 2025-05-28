/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 17:24:31 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/24 22:14:16 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	s_len;
	int		i;

	s_len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (s_len + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
// int main()
// {
//     const char *original = "Hello, World!";
//     char *duplicate = ft_strdup(original);

//     if (duplicate != NULL)
//     {
//         printf("Original : %s\n", original);
//         printf("Duplicate: %s\n", duplicate);

//         // 使用が終わったらメモリを解放
//         free(duplicate);
//     }

//     return (0);
// }