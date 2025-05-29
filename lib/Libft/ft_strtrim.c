/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:48:03 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/28 15:06:00 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static bool	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*s1_start;
	const char	*s1_end;
	size_t		total_len;
	char		*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	s1_start = s1;
	s1_end = s1 + ft_strlen(s1) - 1;
	while (*s1_start != '\0' && is_set(*s1_start, set))
		s1_start++;
	while (s1_end > s1_start && is_set(*s1_end, set))
		s1_end--;
	total_len = s1_end - s1_start + 1;
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1_start, total_len + 1);
	return (result);
}

//  int	main(void)
// {
// 	char s1[] = "1234+AAA_1234";
// 	char set[] = "1234";

// 	char *result = ft_strtrim(s1, set);
// 	if (result)

// 	{
// 		// 結果を出力するか、適切な処理を行います
// 		printf("結果: %s\n", result);
// 		free(result); // メモリを解放する
// 	}

// 	return (0);
// }