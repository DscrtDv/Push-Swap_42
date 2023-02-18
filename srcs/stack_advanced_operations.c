#include "../includes/push_swap.h"
#include <stddef.h>

void	push_from_to(t_stack **s_from, t_stack **s_to)
{
	int value;
	t_stack *node;

	value = s_pop(s_from);
	if (!value)
		printf("Push from->to failed. Exiting...\n");
	node = create_stack(value);
	s_push(s_to, node);
}

void	rotate(t_stack **stack)
{
	t_stack	*HEAD;
	t_stack	*last;
	t_stack	*temp;

	if (!*stack)
		return ;
	else if (s_len(stack) == 2)
		s_swap(stack);
	else
	{
		HEAD = *stack;
		last = s_get_last(stack);
		
		last->next = HEAD;
		temp = HEAD->next;
		HEAD->next = NULL;
		*stack = temp;
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack *HEAD;
	t_stack *last;
	t_stack *temp;
	size_t	len;

	len = s_len(stack);
	if (!*stack)
		return ;
	else if (len == 2)
		s_swap(stack);
	else
	{
		HEAD = *stack;
		last = s_get_last(stack);
		last->next = HEAD;
		*stack = last;
		temp = *stack;
		while (len-- != 1)
			temp = temp->next;
		if (temp->next)
			temp->next = NULL;
	}
}
