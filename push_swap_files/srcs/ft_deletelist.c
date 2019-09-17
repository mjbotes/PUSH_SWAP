/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletelist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 11:30:45 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/12 12:45:23 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_deletelist(t_stack **a)
{
	t_stack	*next;
	t_stack	*ptr;

	next = *a;
	while (next)
	{
		ptr = next;
		next = next->next;
		free(ptr);
	}
	a = NULL;
}
