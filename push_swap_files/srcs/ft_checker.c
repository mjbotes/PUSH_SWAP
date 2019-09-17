/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 09:11:36 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/11 12:45:19 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_checker(t_stack *a, int f(int a, int b))
{
	t_stack *ptr;

	ptr = a;
	while (ptr->next)
	{
		if (f(ptr->num, ptr->next->num))
		{
			return (1);
		}
		ptr = ptr->next;
	}
	return (0);
}
