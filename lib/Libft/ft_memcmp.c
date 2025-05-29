/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:04:41 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/24 20:36:19 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (tmp1[i] != tmp2[i])
		{
			return (tmp1[i] - tmp2[i]);
		}
		i++;
	}
	return (0);
}

// int main(){
// 	size_t	size;
// 	int		result;

// 	// テスト用のデータ
// 	char str1[] = "Hello";
// 	char str2[] = "Hellp";
// 	size = 5;
// 	// memcmp 関数を使用して文字列の比較
// 	result = memcmp(str1, str2, size);
// 	// 結果の表示
// 	if (result == 0)
// 	{
// 		printf("The strings are equal.\n");
// 	}
// 	else if (result > 0)
// 	{
// 		printf("str1 > str2\n");
// 	}
// 	else
// 	{
// 		printf("str1 < str2\n");
// 	}
// 	return (0);
// }