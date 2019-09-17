/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:14:11 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/11 14:07:10 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_acc(int a, int b)
{
	if (a > b)
		return (1);
	return (0);
}

int	ft_dec(int a, int b)
{
	if (b > a)
		return (1);
	return (0);
}

int	ft_isok(t_stack **a, t_stack **b, char *str)
{
	t_stack	*new;
	char	**ar;
	int		i;

	i = -1;
	ar = ft_strsplit(str, ' ');
	while (ar[++i] != NULL)
		if (ft_isnumber(ar[i]) && ft_atoi(ar[i]) >= -2147483648 &&
				ft_atoi(ar[i]) <= 2147483647)
		{
			if (!(new = ft_node(*a, ft_atoi(ar[i]))))
				ft_error(a, b);
			ft_append(a, new);
		}
		else
			ft_error(a, b);
	ft_free_her(ar);
	return (0);
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	int		i;

	if (ac >= 2)
	{
		a = NULL;
		b = NULL;
		i = 0;
		while (++i < ac)
			ft_isok(&a, &b, av[i]);
		ac = ft_get_size(a);
		if (ft_checker(a, &ft_acc))
		{
			if (ac <= 4)
				ft_sort1(&a, &ft_acc, 'a');
			else if (ac <= 100)
				ft_sort3(&a, &b);
			else
				ft_sort4(&a, &b);
		}
		ft_deletelist(&a);
		ft_deletelist(&b);
	}
	return (0);
}
