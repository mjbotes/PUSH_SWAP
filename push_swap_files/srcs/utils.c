/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:39:57 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/11 12:03:27 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_next(t_stack *stack, int num)
{
	int	next;

	next = -1;
	while (stack->num <= num && stack->next)
		stack = stack->next;
	if (stack->num > num)
		next = stack->num;
	while (stack)
	{
		if (stack->num > num && stack->num < next)
			next = stack->num;
		stack = stack->next;
	}
	return (next);
}

int	ft_med(t_stack *stack)
{
	t_stack	*ptr;
	int		size;
	int		loop;
	int		med;

	ptr = stack;
	loop = 0;
	med = ft_find_m(stack, &size, &ft_acc);
	size = ft_get_size(stack);
	while (++loop < size / 2)
		med = ft_get_next(stack, med);
	return (med);
}

int	ft_find_m(t_stack *stack, int *place, int f(int a, int b))
{
	int		min_value;
	int		min_place;
	int		p;
	t_stack	*ptr;

	min_place = 0;
	p = 0;
	ptr = stack;
	min_value = ptr->num;
	while (ptr->next)
	{
		ptr = ptr->next;
		p++;
		if (f(min_value, ptr->num))
		{
			min_value = ptr->num;
			min_place = p;
		}
	}
	*place = min_place;
	return (min_value);
}

int	ft_get_size(t_stack *ptr)
{
	int	size;

	size = 1;
	if (ptr == NULL)
		return (0);
	while ((ptr = ptr->next) != NULL)
		size++;
	return (size);
}

int	ft_sum(t_stack *a)
{
	t_stack	*ptr;
	int		res;

	res = 0;
	ptr = a;
	while (ptr)
	{
		res = ptr->num;
		ptr = ptr->next;
	}
	return (res);
}
