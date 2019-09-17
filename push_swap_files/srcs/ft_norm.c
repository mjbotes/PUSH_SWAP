/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:24:36 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/11 12:30:15 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_norm(t_stack **a)
{
	t_stack		*slow;
	t_stack		*fast;
	int			norm;

	slow = *a;
	while (slow)
	{
		norm = ft_get_size(*a);
		slow->n = norm;
		fast = *a;
		while (fast)
		{
			if (slow->num < fast->num)
				slow->n--;
			fast = fast->next;
		}
		slow = slow->next;
	}
}
