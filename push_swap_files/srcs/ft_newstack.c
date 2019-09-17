/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:06:46 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/11 12:49:04 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	node->n = -1;
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
