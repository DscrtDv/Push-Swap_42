#include "includes/push_swap.h"
#include <stdarg.h>

int main(int argc, char **argv)
{
	t_stack **stack_a;
	t_stack **stack_b;
	t_stack *last_a;
	if (argc <= 2)
	{
		printf("Not enough arguments, quitting..\n");
		return (1);
	}

	stack_a = (t_stack**)malloc(sizeof(t_stack));
	stack_b = (t_stack**)malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (1);

	init_stack(stack_a, argc, argv);
//	size_t len = s_len(stack_a);
	s_visualize(stack_a, 'A');
	last_a = s_get_last(stack_a);
	printf("Last element in A is: %i\n", last_a->content);
	rotate(stack_a);
	s_visualize(stack_a, 'A');
	reverse_rotate(stack_a);
	s_visualize(stack_a, 'A');
	reverse_rotate(stack_a);
	s_visualize(stack_a, 'A');
	reverse_rotate(stack_a);
	s_visualize(stack_a, 'A');
	/*
	while(len--)
	{
		push_from_to(stack_a, stack_b);
		s_visualize(stack_a, 'A');
		s_visualize(stack_b, 'B');
	}
	*/
		return (0);
}
