
#include "../includes/push_swap.h"

t_stack  *ft_node(int n)
{
   t_stack *node;
   node = (t_stack *)malloc(sizeof(t_stack));
   node->num = n;
   node->next = NULL;
   return (node);
}
void    ft_append(t_stack **alst, t_stack *node)
{
   t_stack *lst;
   lst = *alst;
   if (*alst == NULL)
   {
       *alst = node;
       return ;
   }
   else
   {
       while (lst->next)
           lst = lst->next;
   }
   lst->next = node;
}