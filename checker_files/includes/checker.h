/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 12:04:22 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/12 11:46:04 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../libft/libft.h"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_opt
{
	int				p;
	int				d;
	int				c;
	int				s;
	int				l;
	int				lc;
}					t_opt;

void				ft_swap(t_stack **a);
t_stack				*ft_node(t_stack *a, int n);
void				ft_append(t_stack **alst, t_stack *node);
void				ft_print(t_stack *a, t_stack *b);
void				ft_push(t_stack **src, t_stack **dest);
void				ft_rotate(t_stack **src);
void				ft_rev_rotate(t_stack **src);
void				ft_doargs(t_stack **a, t_stack **b, t_opt *opt);
void				ft_deletelist(t_stack **a);
void				ft_error(t_stack **a, t_stack **b);
void				ft_iscommand(char *str, t_stack **a, t_stack **b);
void				ft_checker(t_stack *a, t_stack *b, t_opt *opt);
int					ft_isok(t_stack **a, t_stack **b, char *str);
t_opt				*ft_opt(char **av, int ac, int *i);
void				ft_ko(t_opt *opt);
void				ft_help(void);
void				ft_print_c(t_stack *a, t_stack *b, char *str);

#endif
