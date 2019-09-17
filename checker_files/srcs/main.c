/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:37:45 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/12 11:56:13 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_print_l(t_opt *opt)
{
	if (opt->l)
	{
		ft_putstr("Number of steps: ");
		ft_putnbr(opt->lc);
		ft_putendl("");
	}
}

void	ft_checker(t_stack *a, t_stack *b, t_opt *opt)
{
	t_stack *ptr;

	if (b != NULL)
	{
		ft_ko(opt);
		return ;
	}
	ptr = a;
	while (ptr->next)
	{
		if (ptr->num > ptr->next->num)
		{
			ft_ko(opt);
			return ;
		}
		ptr = ptr->next;
	}
	if (opt->c)
		ft_putendl("\e[01;32mOK");
	else
		ft_putendl("OK");
	ft_print_l(opt);
}

void	ft_ko(t_opt *opt)
{
	if (opt->c)
		ft_putendl("\e[01;31mKO");
	else
		ft_putendl("KO");
}

int		ft_isok(t_stack **a, t_stack **b, char *str)
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

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack *new;
	int		i;
	t_opt	*opt;

	if (ac >= 2)
	{
		a = NULL;
		b = NULL;
		i = 0;
		opt = ft_opt(av, ac, &i);
		while (i < ac)
		{
			ft_isok(&a, &b, av[i]);
			i++;
		}
		if (!a || !a->next)
			exit(0);
		ft_doargs(&a, &b, opt);
		ft_deletelist(&a);
		ft_deletelist(&b);
	}
	return (0);
}
