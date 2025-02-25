/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:37:30 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/12 11:56:35 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_swap(t_stack **a)
{
	t_stack *tmp;

	if (*a && (*a)->next)
	{
		tmp = *a;
		(*a) = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
}
