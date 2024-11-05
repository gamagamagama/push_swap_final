/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:03:17 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 09:07:20 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


typedef struct s_node_stack
{
    int value;
    size_t tar_index;
    size_t index;
    size_t cost;
    bool cheapest;
    bool def;
    bool min;
    bool mid;
    bool max;
    bool abov_median;
    size_t flag_0_3;
    struct s_node_stack *next;
    struct s_node_stack *prev;
    struct s_node_stack *target;
    int node_tar_index;
    int ci; 
    int co; 
    int cx; 
} t_node_stack;

// ---------------------- Group 1: Stack Manipulation ----------------------
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

// ---------------------- Group 2: Stack Initialization and Cleanup ----------------------
void stack_init(t_node_stack **a, char **argv);
void actindex(t_node_stack *stack);
//static void in_node(t_node_stack *node);
//static void add_node(t_node_stack **stack, int num);
//static long ft_atol(const char *str);
//------------------------ Erorr Handling ------------------------
void handle_error(t_node_stack **a);
int ft_dup_err(t_node_stack *a, int num);
void ft_stack_free(t_node_stack **stack);
int ft_syntax_err(char *str);
// ---------------------- Group 3: Sorting Utilities ----------------------
void three(t_node_stack **a);
void others(t_node_stack **a, t_node_stack **b);
void final_sort(t_node_stack **stack);
bool sorted_stack(t_node_stack *stack);
void initialize_sort(t_node_stack **stack, size_t *len, size_t *median, t_node_stack **current);
void prepare_stack_a(t_node_stack **a);
void prepare_stack_b(t_node_stack **a, t_node_stack **b, size_t total_len);
void sort_c_iox(t_node_stack **a, t_node_stack **b, size_t *stack_length, size_t flag);
void sort_blok(t_node_stack **a, t_node_stack **b, size_t total_len);
void initialize_sorter(t_node_stack **a, size_t *stack_length, t_node_stack **actual, t_node_stack **biggest);
int first_sort(t_node_stack **a, t_node_stack **b);
// static void set_target_node_b_test(t_node_stack *a, t_node_stack *b, size_t stack_len);
t_node_stack    *set_target_node_b_test(t_node_stack *a, t_node_stack *b, size_t stack_length);
void    update_node_tar_index(t_node_stack *b, t_node_stack *target_node);
t_node_stack    *find_target_node(t_node_stack *a, t_node_stack *b, size_t stack_length);



// ---------------------- Group 4: Target Index Management ----------------------
void target_index(t_node_stack **a);
void initialize_target_indices(t_node_stack *a, size_t *min_index, size_t *max_index);
void assign_target_indices(t_node_stack *a, size_t *max_index, int currentMax);
void assign_flag_to_node(t_node_stack *node, size_t min, size_t mid, size_t max);
void flag_stack(t_node_stack *stack, size_t stacklen);
void flag_stack_nodes(t_node_stack *stack, size_t min, size_t mid, size_t max);

// ---------------------- Group 5: Cost Calculations ----------------------
void set_price(t_node_stack *stack);
void set_total_price(t_node_stack **b);
void mark_as_cheapest(t_node_stack *cheapest_node);
void process_execution(t_node_stack **a, t_node_stack **b, t_node_stack *cheapest, size_t *stack_length);
t_node_stack *process_iteration(t_node_stack **a, size_t *stack_length, size_t flag);
void set_cheapest(t_node_stack *stack, size_t total_len, size_t flag);
void handle_biggest(t_node_stack **a, t_node_stack *actual, t_node_stack *biggest);

// ---------------------- Group 6: Operations and Helpers ----------------------
void mttp(t_node_stack **stack, t_node_stack *current, size_t median);
void case_1_op(t_node_stack **b, t_node_stack *cheapest);
void case_2_op(t_node_stack **a, t_node_stack *target);
void case_3_op(t_node_stack **a, t_node_stack **b, t_node_stack *cheapest, t_node_stack *target);
void perform_operations(t_node_stack **a, t_node_stack **b, t_node_stack *cheapest, t_node_stack *target);
void psafch(t_node_stack **a, t_node_stack **b, size_t total_len, size_t flag);
void process_stack(t_node_stack **stack, size_t median);
//-----------------------Missing Actions-----------------------
void rotate_operation_ci(t_node_stack **a, t_node_stack *cheapest, size_t median);
void push_operation_ci(t_node_stack *cheapest_node, t_node_stack **a, t_node_stack **b, size_t *tmp_slen_a);
size_t check_flag(t_node_stack *stack, size_t *flag);
void ft_putstr(char *str);
bool is_cheaper(t_node_stack *current_node, size_t *cheapest_index, t_node_stack *cheapest_node, size_t tmp_len);
void reset_stack(t_node_stack *stack);
void check_5con(t_node_stack **a, t_node_stack **b, size_t total_len);


// ---------------------- Group 7: Flag and Chunk Management ----------------------
void calculate_chunks(size_t stacklen, size_t *min, size_t *mid, size_t *max);
void median_flag(t_node_stack *stack, size_t median);
void default_flag(t_node_stack *stack);
void defaults(t_node_stack *stack);
void update_chunk_index(t_node_stack *a, int *c, size_t flag);
void print_chunks(t_node_stack *stack);

// ---------------------- Group 8: String and Parsing Utilities ----------------------
char **ft_spliter(char *str, char c);
bool ft_printable(char *str);
//static size_t word_counter(char *str, char c);
//staticchar *get_word(char *str, char c, bool yes);

// ---------------------- Group 9: Other Helpers ----------------------
size_t set_median(t_node_stack *stack, size_t flag);
size_t stack_len(t_node_stack *stack);
t_node_stack *find_cheapest_node(t_node_stack *stack, size_t flag, size_t total_len);
t_node_stack *retrun_cheapest(t_node_stack *stack);
t_node_stack *find_last_node(t_node_stack *stack);
t_node_stack *find_biggest(t_node_stack *stack);
t_node_stack *find_lowest(t_node_stack *stack);
t_node_stack *find_next_bigboy(t_node_stack *stack, int currentMax);

// ---------------------- Group 10: Main Function ----------------------
int main(int argc, char **argv);


int choose_wise(t_node_stack *actual, size_t flag);
int *create_c_iox();

#endif // PUSH_SWAP_H
