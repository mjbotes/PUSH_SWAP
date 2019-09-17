/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbotes <mbotes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:21:07 by mbotes            #+#    #+#             */
/*   Updated: 2019/09/11 14:45:53 by mbotes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../../libft/libft.h"

typedef struct		s_stack
{
	int				num;
	int				n;
	struct s_stack	*next;
}					t_stack;

void				ft_error(t_stack **a, t_stack **b);
void				ft_swap(t_stack **a, char st);
t_stack				*ft_node(t_stack *a, int n);
void				ft_append(t_stack **alst, t_stack *node);
void				ft_push(t_stack **src, t_stack **dest, char st);
void				ft_rotate(t_stack **src, char st);
void				ft_rev_rotate(t_stack **src, char st);
void				ft_doargs(t_stack **a, t_stack **b);
int					ft_checker(t_stack *a, int f(int a, int b));
void				ft_sort1(t_stack **src, int f(int a, int b), char st);
void				ft_sort2(t_stack **a, t_stack **b,
		int f(int a, int b), char st);
void				ft_push_min(t_stack **a, t_stack **b,
		int f(int a, int b), char st);
int					ft_find_m(t_stack *stack, int *place, int f(int a, int b));
int					ft_get_size(t_stack *ptr);
int					ft_acc(int a, int b);
int					ft_dec(int a, int b);
int					ft_med(t_stack *stack);
void				ft_sort3(t_stack **a, t_stack **b);
int					ft_get_next(t_stack *stack, int num);
void				ft_deletelist(t_stack **a);
int					ft_sum(t_stack *a);
void				ft_sort4(t_stack **a, t_stack **b);
int					ft_dec(int a, int b);
int					ft_acc(int a, int b);
void				ft_norm(t_stack **a);

#endif
