/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:09:04 by cgaratej          #+#    #+#             */
/*   Updated: 2024/01/29 19:03:45 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

/*#include <stdio.h>

int main(void)
{

    t_list *newNode = ft_lstnew("Hello, World!");
    if (newNode == NULL)
        return (1);
    printf("Contenido del nuevo nodo: %s\n", (char *)newNode->content);
    free(newNode);

    return (0);
}*/