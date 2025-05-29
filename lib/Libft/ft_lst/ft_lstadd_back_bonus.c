/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 21:24:07 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/15 21:22:48 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tail;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tail = ft_lstlast(*lst);
		tail->next = new;
	}
}
// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *new_node1 = ft_lstnew("Hello");
// 	t_list *new_node2 = ft_lstnew("World");

// 	// リストに要素を追加
// 	ft_lstadd_back(&head, new_node1);
// 	ft_lstadd_back(&head, new_node2);

// 	// リストの内容を表示
// 	t_list *current = head;
// 	while (current)
// 	{
// 		printf("%s -> ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("NULL\n");

// 	// リストの解放
// 	while (head)
// 	{
// 		t_list *tmp = head;
// 		head = head->next;
// 		free(tmp);
// 	}

// 	return (0);
// }