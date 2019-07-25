#include "../includes/push_swap.h"

void    ft_rotate(t_stack **src)
{
    t_stack *tmp;
    t_stack *ptr;

    tmp = *src;
    *src = (*src)->next;
    ptr = *src;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = tmp;
    ptr->next->next = NULL;
}

void    ft_rev_rotate(t_stack **src)
{
    t_stack *tmp;
    t_stack *ptr;

    ptr = *src;
    while (ptr->next->next != NULL)
        ptr = ptr->next;
    tmp = ptr->next;
    ptr->next = NULL;
    tmp->next = *src;
    *src = tmp;
}