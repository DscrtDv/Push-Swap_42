#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct s_stack{
	int				content;
	struct s_stack 	*next;
}					t_stack;

//stack basic Operations
t_stack		*create_stack(int value);
void		s_push(t_stack **HEAD, t_stack *new_stack);
int			s_pop(t_stack **stack);
size_t		s_len(t_stack **stack);	
void		s_swap(t_stack **stack);
t_stack		*s_get_last(t_stack **stack);

//stack advanced Operations
void		push_from_to(t_stack **s_from, t_stack **s_to);
void		rotate(t_stack **stack);
void		reverse_rotate(t_stack **stack);
//graphics
void		s_visualize(t_stack **stack_a, char c);

//stack innit
void		init_stack(t_stack **stack, int argc, char **argv);

#endif
