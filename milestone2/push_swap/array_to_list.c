
#include "push_swap.h"

static void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

t_node	*array_to_list(int *array, int argc)
{
	int	i;
	t_node	*head;
	t_node	*current;

	if (argc <= 0)
		return (NULL);
	head = create_node(array[0]);
	if (!head)
		return (NULL);
	current = head;
	i = 1;
	while (i < argc)
	{
		current->next = create_node(array[i]);
		if (!current->next)
		{
			free_list(head);
			return (NULL);
		}
		current = current->next;
		i++;
	}
	return (head);
}
