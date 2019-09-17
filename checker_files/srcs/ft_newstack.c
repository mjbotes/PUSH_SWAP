/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:10:02 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/13 13:53:50 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack	*ft_node(t_stack *a, int n)
{
	t_stack	*node;

	if (n < -2147483648 || n > 2147483647)
		return (NULL);
	while (a)
	{
		if (a->num == n)
			return (NULL);
		a = a->next;
	}
	node = (t_stack *)malloc(sizeof(t_stack));
	node->num = n;
	node->next = NULL;
	return (node);
}

void	ft_append(t_stack **alst, t_stack *node)
{
	t_stack	*lst;

	lst = *alst;
	if (*alst == NULL)
	{
		*alst = node;
		return ;
	}
	else
	{
		while (lst->next)
			lst = lst->next;
	}
	lst->next = node;
}
