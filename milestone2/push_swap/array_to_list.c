
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
	int		i;
	t_node	*head;
	t_node	*current;

	if (argc <= 0)
		return (NULL);
	head = create_node(array[0]);
	if (!head)
		return (NULL);
	head->previous = NULL;
	current = head;
	i = 1;
	while (i < argc)
	{
		current->next = create_node(array[i]);
		if (!current->next)
			return (free_list(head), NULL);
		current->next->previous = current;
		current = current->next;
		i++;
	}
	current->next = head;
	head->previous = current;
	return (head);
}
