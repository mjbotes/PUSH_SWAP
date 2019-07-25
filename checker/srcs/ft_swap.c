

#include "../includes/push_swap.h"

void    ft_swap(t_stack **a)
{
    t_stack *tmp;

    if (*a && (*a)->next)
    {
        tmp = *a;
        (*a) = (*a)->next;
        tmp->next = (*a)->next;
        (*a)->next = tmp;
    } 
}