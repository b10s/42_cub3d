/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 14:21:39 by  ctokoyod         #+#    #+#             */
/*   Updated: 2025/05/27 23:34:22 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);

// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	*ft_strdup(const char *s1);
// size_t	ft_strlen(const char *s);
// char	*ft_strchr(const char *s, int c);
// char	*ft_strjoin(char *s1, char *s2);

#endif