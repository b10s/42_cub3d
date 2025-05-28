/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:15:52 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/02 18:05:55 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	f_add1(void *content)
// {
// 	*(int *)content = *(int *)content + 1;
// }

// int	main(void)
// {
// 	t_list *node = malloc(sizeof(t_list));
// 	t_list *current = node;
// 	node->content = malloc(sizeof(int));
// 	*(int *)node->content = 42;
// 	node->next = NULL;

// 	while (current != NULL)
// 	{
// 		printf("%d - > ", *(int *)current->content);
// 		current = current->next;
// 	}
// 	printf("NULL\n");

// 	ft_lstiter(node, f_add1);

// 	current = node;
// 	while (current != NULL)
// 	{
// 		printf("%d - > ", *(int *)current->content);
// 		current = current->next;
// 	}
// 	printf("NULL\n");

// 	while (node != NULL)
// 	{
// 		t_list *tmp = node;
// 		node = node->next;
// 		free(tmp->content);
// 		free(tmp);
// 	}
// 	return (0);
// }