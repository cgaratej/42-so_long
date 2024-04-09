/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:52:31 by cgaratej          #+#    #+#             */
/*   Updated: 2024/01/29 19:03:10 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst)
	{
		if (*lst)
			new->next = *lst;
		*lst = new;
	}
}
/*#include <stdio.h>

int	main(void)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    t_list *myList = NULL;
    ft_lstadd_front(&myList, node3);
    ft_lstadd_front(&myList, node2);
    ft_lstadd_front(&myList, node1);

    printf("Lista después de agregar nodos al frente:\n");
    while (myList)
	{
		printf("%s -> ", (char *)myList->content);
		myList = myList->next;
	}
	printf("NULL\n");

    free(node1);
    free(node2);
    free(node3);

    return (0);
}*/