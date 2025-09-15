
#include "../push_swap.h"

void static	rotate(t_node **stack)
{
	*stack = (*stack)->next;
}

void	rotate_a(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_b);
	rotate(stack_a);
	ft_printf("rr\n");
}
