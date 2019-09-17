/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:23:34 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/12 11:59:38 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	ft_init_opt(t_opt *opt)
{
	opt->p = 0;
	opt->d = 0;
	opt->c = 0;
	opt->s = 0;
	opt->l = 0;
	opt->lc = 0;
}

t_opt		*ft_opt(char **av, int ac, int *i)
{
	t_opt	*opt;
	int		l;

	opt = malloc(sizeof(t_opt));
	ft_init_opt(opt);
	while (++(*i) < ac && av[*i][0] == '-')
	{
		l = 0;
		while (av[*i][++l])
			if (av[*i][l] == 'p')
				opt->p = 1;
			else if (av[*i][l] == 'd')
				opt->d = 1;
			else if (av[*i][l] == 'c')
				opt->c = 1;
			else if (av[*i][l] == 's')
				opt->s = 1;
			else if (av[*i][l] == 'l')
				opt->l = 1;
			else if (av[*i][l] == 'h')
				ft_help();
	}
	return (opt);
}

void		ft_help(void)
{
	ft_putendl("usage: ./checker [-pdcsh] [Numbers...]");
	ft_putendl("Options:");
	ft_putendl("\t-p: prints the numbers when operations are complete.");
	ft_putstr("\t-d: Debugger mode you can go step by step and prints out ");
	ft_putendl("the stacks as you go on");
	ft_putendl("\t-c: Enables colour");
	ft_putendl("\t-s: Slow mode");
	exit(0);
}
