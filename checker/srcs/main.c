#include "../includes/push_swap.h"

void    ft_checker(t_stack *a, t_stack *b)
{
    t_stack *ptr;
    if (b != NULL)
    {
        ft_putendl("KO");
        return ;
    }
    ptr = a;
    while (ptr->next)
    {
        if (ptr->num > ptr->next->num)
        {
            ft_putendl("KO");
            return ;
        }
        ptr = ptr->next;
    }
    ft_putendl("OK");
}
int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    int i;

    a=NULL;
    b=NULL;
    i = 0;
    while (++i < ac)
    ft_append(&a, ft_node(ft_atoi(av[i])));
    ft_doargs(&a, &b);
    ft_checker(a,b);
}