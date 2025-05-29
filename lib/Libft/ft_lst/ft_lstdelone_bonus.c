/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 22:22:52 by  ctokoyod         #+#    #+#             */
/*   Updated: 2023/12/25 23:11:46 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// void del_string(void *data)
// {
//     free(data);
// }

// int main(void)
// {
//     // テスト用のリストと要素の作成
//     t_list *node = malloc(sizeof(t_list));
//     node->content = strdup("Hello, World!");  // strdupは文字列の複製を行う関数
//     node->next = NULL;

//     // ft_lstdelone 関数を使用して要素を削除
//     ft_lstdelone(node, del_string);

//     return 0;
// }