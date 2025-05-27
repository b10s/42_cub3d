/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:36:26 by  ctokoyod         #+#    #+#             */
/*   Updated: 2025/05/27 23:13:08 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*trim_s;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len >= s_len - start)
		len = s_len - start;
	trim_s = (char *)malloc(sizeof(char) * len + 1);
	if (trim_s == NULL)
		return (NULL);
	while (i < len)
	{
		trim_s[i] = s[start + i];
		i++;
	}
	trim_s[len] = '\0';
	return (trim_s);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	s_len;
	int		i;

	if (s1 == NULL)
		return (NULL);
	s_len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*joined;
	char	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (joined == NULL)
		return (NULL);
	tmp = joined;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (joined);
}
