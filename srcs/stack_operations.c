#include "../includes/push_swap.h"

t_stack	*create_stack(int value)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!new)
		return (NULL);
	new->content = value;
	new->next = NULL;
	return (new);
}

void	s_push(t_stack **HEAD, t_stack *new_stack)
{
	if (!new_stack)
		return ;
	if (!*HEAD)
	{
		*HEAD = new_stack;
		return ;
	}
	new_stack->next = *HEAD;
	*HEAD = new_stack;
}

int		s_pop(t_stack **stack)
{
	int		stack_val;
	t_stack	*ptr;
	t_stack *HEAD;

	HEAD = *stack;
	if (!HEAD)
		printf("Stack is empty, nothing to pop.");
	else
	{
		ptr = HEAD;
		stack_val = HEAD->content;
		HEAD = HEAD->next;
		*stack = HEAD;
		free(ptr);
		return (stack_val);
	}
	return (-1);
}

size_t	s_len(t_stack **stack)
{
	size_t	len;
	t_stack	*current;

	len = 0;
	current = *stack;
	while(current)
	{
		current = current->next;
		len++;
	}
	return (len);
}
void	s_visualize(t_stack **stack_a, char c)
{
	t_stack	*s_a;

	s_a = *stack_a;
	printf("____________________________\n");
	while (s_a)
	{
		printf("| %i |\n",s_a->content);
		s_a = s_a->next;
	}
	printf("|	%c	|\n", c);
	printf("____________________________\n");

}

t_stack	*s_get_last(t_stack **stack)
{
	t_stack	*current;
	size_t	len;

	len = s_len(stack);
	if (!*stack)
		return (NULL);
	else if (len <= 1)
		return (*stack);
	current = *stack;
	while (current->next)
		current = current->next;
	return (current);
}

void	s_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (s_len(stack) <= 1)
	{
		printf("Nothing to swap. Exiting..");
		return ;
	}
	first = *stack;
	printf("swapping %i with %i..\n", first->content, first->next->content);

	second = first->next;
	first->next = first->next->next;
	second->next = first;
	*stack = second;
}
