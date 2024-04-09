/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:40:49 by cgaratej          #+#    #+#             */
/*   Updated: 2024/01/29 19:03:33 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

/*#include <stdio.h>

int main(void)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    t_list *myList = node1;
    node1->next = node2;
    node2->next = node3;
	t_list *lastNode = ft_lstlast(myList);
	printf("Contenido del último nodo: %s\n", (char *)lastNode->content);
	free(node1);
	free(node2);
	free(node3);
	return (0);
}*/