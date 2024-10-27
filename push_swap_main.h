#ifndef PUSH_SWAP_old_H
#define PUSH_SWAP_old_H

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
///test///
void print_stack(t_node_stack *stack); 
///test///
/////////////////////////////////////////////////////////
int main(int argc, char **argv);
//first
 int ft_printable(char *str);
 char **ft_spliter(char *str, char c);
 //second
 bool sorted_stack(t_node_stack *stack);
 t_node_stack *find_last_node(t_node_stack *stack);
 int ft_dup_err(t_node_stack *a, int num);
 void ft_stack_free(t_node_stack **stack);
 int ft_syntax_err(char *str);
 void stack_init(t_node_stack **a, char **argv);
//third
t_node_stack *find_next_bigboy(t_node_stack *stack, int currentMax);
t_node_stack *find_biggest(t_node_stack *stack);
t_node_stack *find_lowest(t_node_stack *stack);
size_t stack_len(t_node_stack *stack);
void   target_index(t_node_stack **a);
//forth
void ft_putstr(char *str);
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
//fifth
void three(t_node_stack **a);
void others(t_node_stack **a, t_node_stack **b);

//sixth
void assign_flag_to_node(t_node_stack *node, size_t min, size_t mid, size_t max);
void flag_stack_nodes(t_node_stack *stack, size_t min, size_t mid, size_t max);
void calculate_chunks(size_t stacklen, size_t *min, size_t *mid, size_t *max);
void set_price(t_node_stack *stack);
void actindex(t_node_stack *stack);
void flag_stack(t_node_stack *stack, size_t stacklen);
void default_flag(t_node_stack *stack);
void defaults(t_node_stack *stack);

//seventh
bool is_cheaper(t_node_stack *current_node, size_t *cheapest_index, t_node_stack *cheapest_node, size_t tmp_len);
size_t set_median(t_node_stack *stack, size_t flag);
void mark_as_cheapest(t_node_stack *cheapest_node);
t_node_stack *find_cheapest_node(t_node_stack *stack, size_t flag, size_t total_len);
size_t check_flag(t_node_stack *stack, size_t *flag);
void print_chunks(t_node_stack *stack, int *cx, int *co, int *ci);
void push_operation_ci(t_node_stack *cheapest_node, t_node_stack **a, t_node_stack **b, int *ci_iox, size_t *tmp_slen_a);
void rotate_operation_ci(t_node_stack **a, t_node_stack *cheapest, int *ci, size_t median);
t_node_stack *retrun_cheapest(t_node_stack *stack);
void set_cheapest(t_node_stack *stack, size_t total_len, size_t flag);
void update_chunk_index(t_node_stack *a, int **c_iox, size_t flag);
t_node_stack *process_iteration(t_node_stack **a, t_node_stack **b, int *c_iox, size_t *stack_len, size_t flag);
void handle_biggest(t_node_stack **a, t_node_stack *actual, t_node_stack *biggest);
void initialize_sorter(t_node_stack **a, size_t *stack_length, t_node_stack **actual, t_node_stack **biggest);
void sort_c_iox(t_node_stack **a, t_node_stack **b, int *c_iox, size_t *stack_len, size_t flag);
int first_sort(t_node_stack **a, t_node_stack **b);

//eight
//static void *set_target_node_b_test(t_node_stack *a, t_node_stack *b, size_t stack_len);
void median_flag(t_node_stack *stack, size_t median);
void reset_stack(t_node_stack *stack);
void set_total_price(t_node_stack **b);
void prepare_stack_b(t_node_stack **a, t_node_stack **b, size_t total_len);
void prepare_stack_a(t_node_stack **a);
void case_1_op(t_node_stack **b, t_node_stack *cheapest);
void case_2_op(t_node_stack **a, t_node_stack *target);
void case_3_op(t_node_stack **a, t_node_stack **b, t_node_stack *cheapest, t_node_stack *target);
void perform_operations(t_node_stack **a, t_node_stack **b, t_node_stack *cheapest, t_node_stack *target);
void psafch(t_node_stack **a, t_node_stack **b, size_t total_len, t_node_stack **cheapest, size_t flag);
void sort_blok(t_node_stack **a, t_node_stack **b, size_t total_len);
//nine
void mttp(t_node_stack **stack, t_node_stack *current, size_t median);
void chasfe(t_node_stack **stack, t_node_stack *current);
void process_stack(t_node_stack **stack, size_t median);
void initialize_sort(t_node_stack **stack, size_t *len, size_t *median, t_node_stack **current);
void final_sort(t_node_stack **stack);





#endif