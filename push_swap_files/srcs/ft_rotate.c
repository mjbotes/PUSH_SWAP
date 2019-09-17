/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:36:32 by mbotes            #+#    #+#             */
/*   Updated: 2019/08/13 12:59:01 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate(t_stack **src, char st)
{
	t_stack *tmp;
	t_stack *ptr;

	if (!(*src) || !(*src)->next)
		return ;
	if (st == 'a')
		ft_putendl("ra");
	else
		ft_putendl("rb");
	tmp = *src;
	*src = (*src)->next;
	ptr = *src;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = tmp;
	ptr->next->next = NULL;
}

void	ft_rev_rotate(t_stack **src, char st)
{
	t_stack *tmp;
	t_stack *ptr;

	if (!(*src) || !(*src)->next)
		return ;
	if (st == 'a')
		ft_putendl("rra");
	else
		ft_putendl("rrb");
	ptr = *src;
	while (ptr->next->next != NULL)
		ptr = ptr->next;
	tmp = ptr->next;
	ptr->next = NULL;
	tmp->next = *src;
	*src = tmp;
}
