/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:41:53 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/16 21:31:59 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_words(char const *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			words++;
		while (s[i] != c && s[i] != '\0')
			i++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (words);
}

static char	*make_malloc_s_split(char const *s, int word_length)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * (word_length + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < word_length)
	{
		word[i] = s[i];
		i++;
	}
	word[word_length] = '\0';
	return (word);
}

static void	*free_words(char **words_array, int i)
{
	while (i >= 0)
	{
		free(words_array[i]);
		i--;
	}
	free(words_array);
	return (NULL);
}

static char	**set_word(char const *s, char c, char **words_array, int s_words)
{
	int	word_length;
	int	j;
	int	i;

	j = 0;
	i = 0;
	word_length = 0;
	while (i < s_words)
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		word_length = 0;
		while (s[j] != c && s[j] != '\0')
		{
			word_length++;
			j++;
		}
		words_array[i] = make_malloc_s_split(&s[j - word_length], word_length);
		if (words_array[i] == NULL)
			free_words(words_array, i - 1);
		i++;
	}
	return (words_array);
}

char	**ft_split(char const *s, char c)
{
	char	**words_array;
	int		s_words;

	if (s == NULL)
		return (NULL);
	s_words = count_words(s, c);
	words_array = (char **)malloc(sizeof(char *) * (s_words + 1));
	if (words_array == NULL)
		return (NULL);
	set_word(s, c, words_array, s_words);
	words_array[s_words] = NULL;
	return (words_array);
}

// int	main(void)
// {
// 	char const *str = "&&&5*4*7*76&*aaa";
// 	char charset = '*';
// 	char **result;
// 	int words;
// 	int i;

// 	printf("str[%s]charset[%c]\n", str, charset);
// 	result = ft_split(str, charset);
// 	words = count_words(str, charset);
// 	printf("words : %d\n", words);

// 	i = 0;

// 	while (result[i] != NULL)
// 	{
// 		printf("split[%d]:[%s]\n", i, result[i]);
// 		i++;
// 	}
// 	free_words(result, words - 1);
// 	return (0);
// }