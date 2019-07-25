#include "../includes/push_swap.h"

void    ft_push(t_stack **src, t_stack **dest)
{
    t_stack *tmp;
    if (src)
    {
        tmp = *src;
        *src = (*src)->next;
        tmp->next = *dest;
        *dest = tmp;
    }
}