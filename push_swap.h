#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct s_node_stack
{
   
    int	value;
    size_t index;
    size_t tar_index;
    size_t node_tar_index;
    size_t cost;
    size_t flag_0_3;
    int cx;
    int co;
    int ci;
    bool max;
    bool mid;
    bool min;
    bool def;
    bool flag;
    bool abov_median;
    bool cheapest;
	struct s_node_stack *next;
	struct s_node_stack	*prev;
	struct s_node_stack	*target;

}	t_node_stack;

// Initialization and Memory Management
int stack_init(t_node_stack **a, char **argv);
void ft_stack_free(t_node_stack **stack);
void free_args(char **args);

// Error Checking
int ft_dup_err(t_node_stack *a, int num);
long ft_atol(const char *str);
int ft_syntax_err(char *str);

// Stack and Node Operations
bool sorted_stack(t_node_stack *stack);
size_t stack_len(t_node_stack *stack);
void add_node(t_node_stack **stack, int num);
void actindex(t_node_stack *stack);
t_node_stack *find_next_bigboy(t_node_stack *stack, int currentMax);
t_node_stack *find_biggest(t_node_stack *stack);
t_node_stack *find_lowest(t_node_stack *stack);
t_node_stack *find_last_node(t_node_stack *stack);

// Flagging and Indexing Operations
void assign_flag_to_node(t_node_stack *node, size_t min, size_t mid, size_t max);
void flag_stack_nodes(t_node_stack *stack, size_t min, size_t mid, size_t max);
void calculate_chunks(size_t stacklen, size_t *min, size_t *mid, size_t *max);
void set_price(t_node_stack *stack);
void default_flag(t_node_stack *stack);
void flag_stack(t_node_stack *stack, size_t stacklen);
void defaults(t_node_stack *stack);
void target_index(t_node_stack **a);

// Utility and Argument Parsing
char **get_arguments(int argc, char **argv);
char **ft_spliter(char *str, char c);
int ft_printable(char *str);
size_t word_counter(char *str, char c);
void ft_putstr_fd(char *s, int fd);

// Stack Operations
void sa(t_node_stack **a);
void sb(t_node_stack **b);
void ss(t_node_stack **a, t_node_stack **b);
void pa(t_node_stack **a, t_node_stack **b);
void pb(t_node_stack **b, t_node_stack **a);
void ra(t_node_stack **a);
void rb(t_node_stack **b);
void rr(t_node_stack **a, t_node_stack **b);
void rra(t_node_stack **a);
void rrb(t_node_stack **b);
void rrr(t_node_stack **a, t_node_stack **b);

// Additional Sorting and Processing
void others(t_node_stack **a, t_node_stack **b);
void three(t_node_stack **a);
void process_stack(t_node_stack **a, t_node_stack **b);

// Helper functions for target indexing
void initialize_target_indices(t_node_stack *a, size_t *min_index, size_t *max_index);
void assign_target_indices(t_node_stack *a, size_t *max_index, int currentMax);


#endif // PUSH_SWAP_H