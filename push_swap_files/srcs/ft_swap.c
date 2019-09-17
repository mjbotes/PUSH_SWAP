/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:16:28 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/09 11:18:12 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack **a, char st)
{
	t_stack	*tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		(*a) = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (st == 'a')
		ft_putendl("sa");
	else
		ft_putendl("sb");
}
