#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
} t_node;

void    push_node(t_node **stack_a, t_node **stack_b)
{
    t_node *temp;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    temp = *stack_a;
    *stack_a = (*stack_a)->next;
    temp->next = *stack_b;
    *stack_b = temp;
}

void    ft_rotate(t_node **stack)
{
    if (!stack || !*stack )
        return ;
    t_node  *first_node;
    t_node  *current_node;

    first_node = *stack;
    current_node = *stack;
    *stack = (*stack)->next;
    while (current_node->next)
    {
        current_node = current_node->next;
    }
    current_node->next = first_node; 
    first_node-> next = NULL;
}

void    reverse_rotate(t_node **stack)
{
    t_node  *prev;
    t_node  *last_node;

    last_node = *stack;
    prev = NULL;
    if (!stack || !*stack || !(*stack)->next)
        return ;
    while (last_node->next)
    {
        prev = last_node;
        last_node = last_node->next;
    }
    prev->next = NULL;
    last_node->next = *stack;
    *stack = last_node;
}

int	ft_three_sort_algo(t_node **stack)
{
	int first;
	int middle;
	int last;
	int i;

	first = (*stack)->value;
	middle = (*stack)->next->value;
	last = (*stack)->next->next->value;
	i = 0;
	if (first > middle && middle < last && last > first)
		i += ft_swap_a(&stack);
	if (first > middle && middle > last && last < first)
	{
		i += ft_swap_a(&stack);
		i += ft_rev_rotate_a(&stack);
    }
	if (first > middle && middle < last && last < first)
		i += ft_rotate_a(&stack);
	if (first < middle && middle > last && last > first)
	{
		i += ft_swap_a(&stack);
		i += ft_rotate_a(&stack);
	}
	if (first < middle && middle > last && last < first)
		i += ft_rev_rotate_a(&stack);
	return (i);
}

t_node    *gen_node(int number, int index)
{
    t_node *node;

    node = (t_node*)malloc(sizeof(t_node));
    if (!node)
        return(NULL);
    node->value = number;
    node->index = index;
    node->next = NULL;
    return(node);
}

void    print_node(t_node *data)
{
    while(data)
    {
        printf("value: %d | index: %d\n", data->value, data->index);
        data = data->next;
    }
    printf("NULL\n");
}

void    free_node(t_node *stack)
{
    t_node *temp;
    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

int main(void)
{
    t_node  *stack_a;
    
    stack_a = gen_node(2,0);
    stack_a->next = gen_node(4,1);
    stack_a->next->next = gen_node(3,2);

    printf("Nó antes:\n");
    print_node(stack_a);
    
    three_sort_algo(&stack_a);

    printf("Nó após swap: \n");
    print_node(stack_a);
    
    free_node(stack_a);
    return (0);
}