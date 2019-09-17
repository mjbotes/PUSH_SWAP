/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 08:53:06 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/11 12:57:47 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort1(t_stack **a, int f(int a, int b), char st)
{
	t_stack	*src;

	src = *a;
	if ((*a)->next != NULL)
		if (f(src->num, src->next->num))
			ft_swap(a, st);
	if ((*a)->next->next != NULL)
	{
		if (ft_checker(*a, f))
			ft_rev_rotate(a, st);
		if (ft_checker(*a, f))
			ft_swap(a, st);
	}
}

void	ft_sort2(t_stack **a, t_stack **b, int f(int a, int b), char st)
{
	int		temp;
	t_stack	*last;
	int		i;

	temp = ft_get_size(*a) - 3;
	i = 0;
	while (i < temp)
	{
		ft_push_min(a, b, f, st);
		i++;
	}
	ft_sort1(a, f, st);
	last = *a;
	while (i-- > 0 && st == 'a')
		ft_push(b, a, st + 1);
}

void	ft_push_min(t_stack **a, t_stack **b, int f(int a, int b), char st)
{
	int	min_value;
	int	min_place;
	int	place;

	min_place = 1;
	place = ft_get_size(*a);
	min_value = ft_find_m(*a, &min_place, f);
	if (min_place <= place / 2)
		while (min_place-- > 0)
			ft_rotate(a, st);
	else
		while (min_place++ < place)
			ft_rev_rotate(a, st);
	ft_push(a, b, st);
}

void	ft_sort3(t_stack **a, t_stack **b)
{
	int	size;
	int med;

	size = ft_get_size(*a);
	med = ft_med(*a);
	while (ft_get_size(*b) < size / 2)
		if ((*a)->num <= med)
			ft_push(a, b, 'a');
		else
			ft_rotate(a, 'a');
	ft_sort2(a, b, &ft_acc, 'a');
	ft_sort2(b, a, &ft_dec, 'b');
	while (*b)
	{
		ft_push(b, a, 'b');
	}
}

void	ft_sort4(t_stack **a, t_stack **b)
{
	int	r_max;
	int	i;

	r_max = 0;
	i = 1;
	ft_norm(a);
	while (*a)
	{
		r_max += 44;
		while (i < r_max)
		{
			if (!*a)
				break ;
			if ((*a)->n <= r_max)
			{
				i++;
				ft_push(a, b, 'a');
			}
			else
				ft_rotate(a, 'a');
		}
	}
	while (*b)
		ft_push_min(b, a, ft_dec, 'b');
}
