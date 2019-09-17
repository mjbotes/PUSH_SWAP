/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 15:03:27 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/12 11:52:06 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_iscommand(char *str, t_stack **a, t_stack **b)
{
	if (!(ft_strequ(str, "sa") || ft_strequ(str, "ss") ||
			ft_strequ(str, "sb") ||
			ft_strequ(str, "ss") || ft_strequ(str, "pa") ||
			ft_strequ(str, "pb") || ft_strequ(str, "ra") ||
			ft_strequ(str, "rr") || ft_strequ(str, "rb") ||
			ft_strequ(str, "rr") || ft_strequ(str, "rra") ||
			ft_strequ(str, "rrr") || ft_strequ(str, "rrb") ||
			ft_strequ(str, "rrr")))
		ft_error(a, b);
}

void	ft_docommand(char *str, t_stack **a, t_stack **b, t_opt *opt)
{
	if (opt->l)
		opt->lc++;
	ft_iscommand(str, a, b);
	if (ft_strequ(str, "sa") || ft_strequ(str, "ss"))
		ft_swap(a);
	if (ft_strequ(str, "sb") || ft_strequ(str, "ss"))
		ft_swap(b);
	if (ft_strequ(str, "pa"))
		ft_push(b, a);
	if (ft_strequ(str, "pb"))
		ft_push(a, b);
	if (ft_strequ(str, "ra") || ft_strequ(str, "rr"))
		ft_rotate(a);
	if (ft_strequ(str, "rb") || ft_strequ(str, "rr"))
		ft_rotate(b);
	if (ft_strequ(str, "rra") || ft_strequ(str, "rrr"))
		ft_rev_rotate(a);
	if (ft_strequ(str, "rrb") || ft_strequ(str, "rrr"))
		ft_rev_rotate(b);
}

void	ft_doargs(t_stack **a, t_stack **b, t_opt *opt)
{
	char	*str;

	if (!opt->d)
		while (get_next_line(0, &str) > 0)
		{
			ft_docommand(str, a, b, opt);
			if (opt->s)
				ft_print_c(*a, *b, str);
			ft_strdel(&str);
		}
	else
		while (1)
		{
			ft_print(*a, *b);
			ft_putstr("Type Opperation or finish: ");
			get_next_line(0, &str);
			if (ft_strequ(str, "finish"))
				break ;
			ft_docommand(str, a, b, opt);
			ft_strdel(&str);
		}
	if (opt->p)
		ft_print(*a, *b);
	ft_checker(*a, *b, opt);
}
