#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node_stack
{
    int value;
    int tar_index;
    int index;
    int cost;
    bool cheapest;
    bool min;
    bool mid;
    bool max;
    bool abov_median;
    int flag_0_3;
    struct s_node_stack *next;
    struct s_node_stack *prev;
    struct s_node_stack *target;
    int node_tar_index;
    int ci, co, cx; // Chunk flags, initialized elsewhere
} t_node_stack;

// Argument and Stack Initialization
int stack_init(t_node_stack **a, char **argv);
int ft_dup_err(t_node_stack *a, int num);
int ft_syntax_err(char *str);
char **get_arguments(int argc, char **argv);
char **ft_spliter(char *str, char c);
int ft_printable(char *str);
void free_args(char **args);

// Target Indexing and Sorting
void target_index(t_node_stack **a);
void three(t_node_stack **a);
void others(t_node_stack **a, t_node_stack **b);
void initialize_sort(t_node_stack **stack, size_t *len, size_t *median, t_node_stack **current);
void final_sort(t_node_stack **stack);
void process_stack(t_node_stack **stack, size_t median);

// Stack Manipulation Functions
void sa(t_node_stack **a);
void sb(t_node_stack **b);
void ss(t_node_stack **a, t_node_stack **b);
void pa(t_node_stack **b, t_node_stack **a);
void pb(t_node_stack **a, t_node_stack **b);
void ra(t_node_stack **a);
void rb(t_node_stack **b);
void rr(t_node_stack **a, t_node_stack **b);
void rra(t_node_stack **a);
void rrb(t_node_stack **b);
void rrr(t_node_stack **a, t_node_stack **b);

// Core Sorting Functions
bool sorted_stack(t_node_stack *stack);
void defaults(t_node_stack *stack);
void assign_target_indices(t_node_stack *a, size_t *max_index, int currentMax);
void process_execution(t_node_stack **a, t_node_stack **b, int *c_iox, t_node_stack *cheapest, size_t *stack_length);
void process_iteration(t_node_stack **a, t_node_stack **b, int *c_iox, size_t *stack_length, size_t flag);
void psafch(t_node_stack **a, t_node_stack **b, size_t total_len, t_node_stack **cheapest, size_t flag);
void sort_blok(t_node_stack **a, t_node_stack **b, size_t total_len);
void sort_c_iox(t_node_stack **a, t_node_stack **b, int *c_iox, size_t *stack_length, size_t flag);

// Utility Functions
void ft_stack_free(t_node_stack **stack);
void ft_putstr_fd(char *s, int fd);
void handle_error(void);
void print_chunks(t_node_stack *stack, int *cx, int *co, int *ci);

// Helper Functions
void assign_flag_to_node(t_node_stack *node, size_t min, size_t mid, size_t max);
void flag_stack_nodes(t_node_stack *stack, size_t min, size_t mid, size_t max);
void flag_stack(t_node_stack *stack, size_t stacklen);
void set_price(t_node_stack *stack);
void set_cheapest(t_node_stack *stack, size_t total_len, size_t flag);
void mark_as_cheapest(t_node_stack *cheapest_node);
void prepare_stack_a(t_node_stack **a);
void prepare_stack_b(t_node_stack **a, t_node_stack **b, size_t total_len);
void rotate_operation_ci(t_node_stack **a, t_node_stack *cheapest, int *ci, size_t median);
void update_chunk_index(t_node_stack *a, int **c_iox, size_t flag);

// Node and Index Helpers
size_t stack_len(t_node_stack *stack);
size_t set_median(t_node_stack *stack, size_t flag);
size_t check_flag(t_node_stack *stack, size_t *flag);
size_t word_counter(char *str, char c);
t_node_stack *find_next_bigboy(t_node_stack *stack, int currentMax);
t_node_stack *find_biggest(t_node_stack *stack);
t_node_stack *find_lowest(t_node_stack *stack);
t_node_stack *find_last_node(t_node_stack *stack);
t_node_stack *find_cheapest_node(t_node_stack *stack, size_t flag, size_t total_len);
t_node_stack *retrun_cheapest(t_node_stack *stack);
void actindex(t_node_stack *stack);

// Internal Manipulations (static functions in implementation files)
static void add_node(t_node_stack **stack, int num);
static long ft_atol(const char *str);
static void swap(t_node_stack **top);
static void push(t_node_stack **from, t_node_stack **to);
static void rot(t_node_stack **stack);
static void rev_rot(t_node_stack **stack);
static void *set_target_node_b_test(t_node_stack *a, t_node_stack *b, size_t stack_len);
void calculate_chunks(size_t stacklen, size_t *min, size_t *mid, size_t *max);

#endif // PUSH_SWAP_H
