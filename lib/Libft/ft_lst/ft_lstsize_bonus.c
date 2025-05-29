/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 20:56:48 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/02 19:03:10 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		node_counts;

	current = lst;
	node_counts = 0;
	while (current != NULL)
	{
		node_counts++;
		current = current->next;
	}
	return (node_counts);
}
