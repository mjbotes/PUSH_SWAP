/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:10:17 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/12 11:23:22 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_print(t_stack *a, t_stack *b)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	ptr_a = a;
	ptr_b = b;
	while (ptr_a || ptr_b)
	{
		if (ptr_a)
		{
			ft_putnbr(ptr_a->num);
			ptr_a = ptr_a->next;
		}
		ft_putchar('\t');
		if (ptr_b)
		{
			ft_putnbr(ptr_b->num);
			ptr_b = ptr_b->next;
		}
		ft_putendl("");
	}
	ft_putendl("-\t-");
	ft_putendl("A\tB");
}

void	ft_print_c(t_stack *a, t_stack *b, char *str)
{
	t_stack	*ptr_a;
	t_stack	*ptr_b;

	ptr_a = a;
	ptr_b = b;
	while (ptr_a || ptr_b)
	{
		if (ptr_a)
		{
			ft_putnbr(ptr_a->num);
			ptr_a = ptr_a->next;
		}
		ft_putchar('\t');
		if (ptr_b)
		{
			ft_putnbr(ptr_b->num);
			ptr_b = ptr_b->next;
		}
		ft_putendl("");
	}
	ft_putendl("-\t-\nA\tB");
	ft_putendl("---------------------");
	ft_putstr("Last Move: ");
	ft_putendl(str);
	sleep(5);
}
