/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:41:57 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/01/15 21:22:38 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*node1;
// 	t_list	*current;
// 	t_list	*temp;

// 	head = ft_lstnew(" Christmas!!!");
// 	node1 = ft_lstnew("Merry");
// 	printf("*** before *** \n");
// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("%s -> ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// 	ft_lstadd_front(&head, node1);
// 	printf("*** after *** \n");
// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("%s -> ", (char *)current->content);
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// 	while (head != NULL)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// 	return (0);
// }
