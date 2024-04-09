/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:18:28 by cgaratej          #+#    #+#             */
/*   Updated: 2024/01/29 19:03:49 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
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

	int len = ft_lstsize(myList);

    printf("size de lista: %d\n", len);

    free(node1);
    free(node2);
    free(node3);

    return (0);
}*/