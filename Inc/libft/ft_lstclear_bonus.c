/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:28:03 by cgaratej          #+#    #+#             */
/*   Updated: 2024/01/29 19:03:20 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/*#include <stdio.h>

void	delete_content(void *content)
{
	free(content);
}

int main(void) 
{
    t_list *node1 = ft_lstnew(ft_strdup("node 1"));
    t_list *node2 = ft_lstnew(ft_strdup("node 2"));
	ft_lstadd_back(&node1, node2);
	ft_lstclear(&node1, delete_content);
    return (0);
}*/
