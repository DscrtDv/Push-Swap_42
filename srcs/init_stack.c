#include "../includes/push_swap.h"

void	init_stack(t_stack **stack, int argc, char **argv)
{
	t_stack	*new;

	while (argc-- != 1)
	{
		new = create_stack(ft_atoi(argv[argc]));
		s_push(stack, new);
	}
}
