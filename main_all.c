/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 16:05:39 by matus             #+#    #+#             */
/*   Updated: 2024/11/05 10:13:07 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"
int counter = 0;
//test///
// void print_stack(t_node_stack *stack) {
//     t_node_stack *current = stack;
//     while (current != NULL) {
//         printf("VALUE:%d %ld\n", current->value, current->flag_0_3);
//         printf("CurrentIndex:%ld \n", current->index);
//         printf("TargetIndex:%ld \n", current->tar_index);
//         printf("COST: %ld \n", current->cost);
//         printf("CHEAPEST: %d \n", current->cheapest);
//         printf("TARGET NODE TARINDEX: %ld \n", current->node_tar_index);
//          printf("COUNTER: %d \n", counter);
//         printf("========================================== \n");
//         current = current->next;
		
//     }
//     current = NULL;
//     printf("\n");
// }

//nine
void mttp(t_node_stack **stack, t_node_stack *current, size_t median)
{
	while (current->index != current->tar_index)
	{
		if (current->index > median)
		{
			rra(stack);
		}
		else
		{
			ra(stack);
		}
		actindex(*stack);
	}
}


void process_stack(t_node_stack **stack, size_t median)
{
	t_node_stack *current = *stack;
	while (current)
	{
		
		if (current->tar_index == 0)
		{
			mttp(stack, current, median);
			if (current->index == current->tar_index)
			{
				break;
			}
		}
		current = current->next;
	}
}

void initialize_sort(t_node_stack **stack, size_t *len, size_t *median, t_node_stack **current)
{
	*len = stack_len(*stack);
	*median = *len / 2;
	*current = *stack;
	actindex(*stack);
}

void final_sort(t_node_stack **stack)
{
	size_t len;
	size_t median;
	t_node_stack *current;
	
	initialize_sort(stack, &len, &median, &current);
	process_stack(stack, median);
}


//eight

t_node_stack    *find_target_node(t_node_stack *a, t_node_stack *b, size_t stack_length)
{
		t_node_stack    *current_a;
		t_node_stack    *target_node;
		size_t          best_index;

		target_node = NULL;
		best_index = stack_length;
		current_a = a;
		while (current_a)
		{
			if (current_a->tar_index > b->tar_index
				&& current_a->tar_index < best_index)
			{
				best_index = current_a->tar_index;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		return (target_node);
	}



void    update_node_tar_index(t_node_stack *b, t_node_stack *target_node)
	{
		if (target_node != NULL)
		{
			b->node_tar_index = target_node->tar_index;
			b->target = target_node;
		}
	}



t_node_stack    *set_target_node_b_test(t_node_stack *a, t_node_stack *b, size_t stack_length)
	{
		t_node_stack    *target_node;

		while (b != NULL)
		{
			target_node = find_target_node(a, b, stack_length);
			update_node_tar_index(b, target_node);
			b = b->next;
		}
		return (target_node);
	}



// static void *set_target_node_b_test(t_node_stack *a, t_node_stack *b, size_t stack_len)
// {
//     t_node_stack *current_a;
//     t_node_stack *target_node;
//     size_t    best_index;
	 
//     target_node = NULL;
//     while (b != NULL)
//     {
//         best_index = stack_len;
//         current_a = a;
//         while (current_a)
//         {
//             if ((*current_a).tar_index > (*b).tar_index 
//                 && (*current_a).tar_index < best_index)
//             {
//                 best_index = (*current_a).tar_index;
//                 target_node = current_a;
//             }
//             current_a = (*current_a).next;
//         }
//         if(target_node != NULL)
//         {
//             (*b).node_tar_index = (*target_node).tar_index;
//             (*b).target = (target_node);
//         }
//         b = (*b).next;
//     }
//     return target_node;
// }

void median_flag(t_node_stack *stack, size_t median)
{
	while (stack)
	{
		if (stack->index >= median)  //>=
		{
			stack->abov_median = false;
		}
		else
		{
			stack->abov_median = true;
		}
		stack = stack->next;
	}
}

void reset_stack(t_node_stack *stack)
{
	while (stack != NULL)
	{
		if ((*stack).cheapest == true)
		{
			(*stack).cheapest = false;
		}
		stack = (*stack).next;
	}
}

void set_total_price(t_node_stack **b)
{
	size_t total_price;
	t_node_stack *actual;

	
	actual = *b;
	while (actual != NULL)
	{
		total_price = actual->cost + actual->target->cost;
		actual->cost = total_price;
		actual = actual->next;
	}
}

void prepare_stack_b(t_node_stack **a, t_node_stack **b, size_t total_len)
{
	size_t median;
	size_t temp_len;

	temp_len = stack_len(*b);
	reset_stack(*b);
	actindex(*b);
	median = temp_len / 2;
	set_price(*b);
	median_flag(*b, median);
	set_target_node_b_test(*a, *b, total_len);
}

void prepare_stack_a(t_node_stack **a)
{
	size_t len_of_a;
	size_t median;

	len_of_a = stack_len(*a);
	median = len_of_a / 2;
	default_flag(*a);
	reset_stack(*a);
	actindex(*a);
	median_flag(*a, median);
	set_price(*a);
}

void case_1_op(t_node_stack **b, t_node_stack *cheapest)
{
	if (cheapest->abov_median)
		{
			rb(b);
		}
	else
		{
			rrb(b);
		}
}

void case_2_op(t_node_stack **a, t_node_stack *target)
{
	if (target->abov_median)
	{
		ra(a);
	}
	else
	{
		rra(a);
	}
}

void case_3_op(t_node_stack **a, t_node_stack **b, t_node_stack *cheapest, t_node_stack *target)
{
	if (cheapest->abov_median && target->abov_median)
		{
			rr(a, b);
		}
		else if (!cheapest->abov_median && !target->abov_median)
		{
			rrr(a, b);
		}
		else if ((!cheapest->abov_median) && target->abov_median)
		{
			rrb(b);
			ra(a);
		}
		else
		{
			rra(a);
			rb(b);
		}
}

void perform_operations(t_node_stack **a, t_node_stack **b, t_node_stack *cheapest, t_node_stack *target)
{

	while (cheapest->index != 0 || target->index != 0)
	{
		if (cheapest->index != 0 && target->index == 0)
		{
			case_1_op(b, cheapest);
		}
		else if (cheapest->index == 0 && target->index != 0)
		{
			case_2_op(a, target);
		}
		else if (cheapest->index != 0 && target->index != 0)
		{
			case_3_op(a, b, cheapest, target);
		}
		actindex(*a);
		actindex(*b);
	}
}

void psafch(t_node_stack **a, t_node_stack **b, size_t total_len, size_t flag)
{
	prepare_stack_a(a);
	prepare_stack_b(a, b, total_len);
	set_total_price(b);
	set_cheapest(*b, total_len, flag);
	
}
void check_5con(t_node_stack **a, t_node_stack **b, size_t total_len)
{
	if (!((a)||(b)))
	{
		handle_error(a);
		handle_error(b);
	}
	if (stack_len(*a) == 3 && stack_len(*b) < 3)
	{
		while (*b)
		{
			pa(b, a);
		}
		*b = NULL;
		if (total_len <= 5)
		{
			if ((*a)->tar_index > (*a)->next->tar_index)
			{
				sa(a);
			}
		}
	}
}
// void check_test(t_node_stack **b)
// {
//     if ((*b)->tar_index < (*b)->next->tar_index)
//     {
//         sb(b);
//     }
	
// }
void sort_blok(t_node_stack **a, t_node_stack **b, size_t total_len)
{
	t_node_stack *target;
	t_node_stack *cheapest;
	//size_t tmp_len;
	size_t flag;
	
   // tmp_len = stack_len(*b);
	flag = 3;
	while ((*b) != NULL)
	{
		check_5con(a, b, total_len);
	//    check_test(b);
		psafch(a, b, total_len, flag);
		cheapest = retrun_cheapest(*b);
		if (cheapest == NULL)
			return;
		target = cheapest->target;
		perform_operations(a, b, cheapest, target);
		if(target->index == 0 && cheapest->index == 0)
		{
			pa(b, a);
		}
		//tmp_len--;
		flag = check_flag(*b, &flag);
	}
}

//seventh
bool is_cheaper(t_node_stack *current_node, size_t *cheapest_index, t_node_stack *cheapest_node, size_t tmp_len)
{
	
	if (current_node->cost < *cheapest_index)
	{
		return true;
	}
	else if (current_node->cost == *cheapest_index)
	{
		if (current_node->tar_index > cheapest_node->tar_index)
		{
			return (true);
		}
		else
		{
			return (false);
		}
	}
	return false;
}


size_t set_median(t_node_stack *stack, size_t flag )
{
	size_t sum;
	size_t median;
	size_t counter;
	t_node_stack *current;

	current = stack;
	counter = 0;
	sum = 0;
	while(current != NULL)
	{
		if ((*current).flag_0_3 == flag)
		{
			sum = sum + (*current).tar_index;
			counter++;
		}
		current = current->next;
	}
	median = sum / counter;
	return(median);
}

void mark_as_cheapest(t_node_stack *cheapest_node)
{
	if (cheapest_node)
	{
		cheapest_node->cheapest = true;
	}
}

t_node_stack *find_cheapest_node(t_node_stack *stack, size_t flag, size_t total_len)
{
	size_t cheapest_index;
	size_t tmp_len;
	t_node_stack *cheapest_node;
	
	cheapest_index = total_len;
	tmp_len = stack_len(stack);
	cheapest_node = NULL;
	while (stack)
	{
		if (stack->flag_0_3 == flag)
		{
			if (is_cheaper(stack, &cheapest_index, cheapest_node, tmp_len))
			{
				cheapest_index = stack->cost;
				cheapest_node = stack;
			}
		}
		stack = stack->next;
	}
	return cheapest_node;
}

size_t check_flag(t_node_stack *stack, size_t *flag)
{
	t_node_stack *current; 
   while (*flag > 0) 
	{
		current = stack; 
		while (current)
		{
			if (current->flag_0_3 == *flag)
			{
				return *flag;
			}
			current = current->next;
		}
		(*flag)--;
	}
	return *flag;
}

void print_chunks(t_node_stack *stack)
{
	t_node_stack *current;
	
	stack->cx = 0;
	stack->co = 0;
	stack->ci = 0;
  
	current = stack;
	while (current != NULL)
	{
		if (current->min == true)
		{
			((*stack).ci)++;
		}
		else if (current->mid == true)
		{
			((*stack).co)++;
		}
		else if (current->max == true)
		{
			((*stack).cx)++;
		}
		current = current->next;
	}
}

void push_operation_ci(t_node_stack *cheapest_node, t_node_stack **a, t_node_stack **b, size_t *tmp_slen_a)
{
	t_node_stack *stack;
	static size_t chunk_median;
	static size_t flag;
   
	stack = *a;
	if(!chunk_median || flag != stack->flag_0_3)
	{
		flag = (stack)->flag_0_3;
		chunk_median = set_median(stack, (stack)->flag_0_3);
	}   
	if ((*stack).cheapest)// && ci_iox != 0)
			{
				if((*cheapest_node).tar_index >= chunk_median) //lol
				{
					pb(a,b);
					 (*tmp_slen_a)--;   
				}
				else if ((*cheapest_node).tar_index < chunk_median)
				{
					pb(a,b);
					rb(b);
					(*tmp_slen_a)--;
				}
			}
}

void rotate_operation_ci(t_node_stack **a, t_node_stack *cheapest, size_t median)
{
	t_node_stack *actual;
  //  int *c_iox;
   // int initial_value;

	
	actual = *a;
	//initial_value = choose_wise(actual, actual->flag_0_3);
   // *c_iox = initial_value;
	while (!(*actual).cheapest)//  && *c_iox != 0)
	{
		if ((*cheapest).index < median)
		{
			while ((!(*actual).cheapest))
			{
				ra(a);
				actual = *a;
			}
		}
		else if ((*cheapest).index >= median)
		{
			while (!(*actual).cheapest )//&& *c_iox != 0)
			{
				rra(a);
				actual = *a;
			}
		}
		//update_chunk_index(*a, &c_iox, actual->flag_0_3);
		actual = *a; 
	}
}

t_node_stack *retrun_cheapest(t_node_stack *stack)
{
	if(stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
		{
			return(stack);
		}
		stack = (*stack).next;
	}
	return(NULL);
}

void set_cheapest(t_node_stack *stack, size_t total_len, size_t flag)
{
	t_node_stack *cheapest_node; 

	if (!stack)
		return;
	flag = check_flag(stack, &flag);
	cheapest_node = find_cheapest_node(stack, flag, total_len);
	mark_as_cheapest(cheapest_node);
}

void update_chunk_index(t_node_stack *a, int *c, size_t flag)
{
	if (flag == 1)
	{
		*c = a->ci;
	}
	else if (flag == 2)
	{
		*c = a->co;
	}
	else if (flag == 3)
	{
		*c = a->cx;
	}
}
void process_execution(t_node_stack **a, t_node_stack **b, /*int *c_iox,*/ t_node_stack *cheapest, size_t *stack_length)
{

	size_t median;
	median = *stack_length / 2;
	rotate_operation_ci(a, cheapest, /*c_iox*/ median);
	push_operation_ci(cheapest, a, b, /*c_iox,*/ stack_length);
	print_chunks(*a);
}

t_node_stack *process_iteration(t_node_stack **a, size_t *stack_length, size_t flag)
{
	t_node_stack *cheapest;
	
	actindex(*a);
	set_price(*a);
	set_cheapest(*a, *stack_length, flag);
	cheapest = retrun_cheapest(*a);

   return(cheapest); 
}

void handle_biggest(t_node_stack **a, t_node_stack *actual, t_node_stack *biggest)
{
	if (actual->tar_index == biggest->tar_index)
	{
		ra(a);
		actual = *a;
	}
}

void initialize_sorter(t_node_stack **a, size_t *stack_length, t_node_stack **actual, t_node_stack **biggest)
{
	*biggest = find_biggest(*a);
	(*biggest)->flag_0_3 = 0;
	*actual = *a;
	*stack_length = stack_len(*a);
}

int choose_wise(t_node_stack *actual, size_t flag)
{
	if (flag == 1)
	{
		return(actual->ci);
	}
	else if (flag == 2)
	{
		return(actual->co);
	}
	else if (flag == 3)
	{
		return(actual->cx);
	}
	return(0);
}

int *create_c_iox()
{
	int *c_iox;

	c_iox = malloc(sizeof(int));
	if (!c_iox)
	{
		return(NULL);
	}
	return(c_iox);
}
void sort_c_iox(t_node_stack **a, t_node_stack **b, size_t *stack_length, size_t flag)
{
	size_t tmp_len;
	t_node_stack *actual;
	t_node_stack *biggest;
	int c_iox;// = choose_wise(*a, flag);

	c_iox = choose_wise(*a, flag);
	
	initialize_sorter(a, stack_length, &actual, &biggest);
	tmp_len = *stack_length;
  
	while ( c_iox != 0 && tmp_len > 3)//3 && *c_iox != 0)
	{
		actual = process_iteration(a, &tmp_len, flag);
		c_iox = choose_wise(*a, flag);
		if (!actual)
			return ;
		if (actual == biggest && flag >= 2)
		{
			handle_biggest(a, actual, biggest);
			actual = process_iteration(a, &tmp_len, flag);
		}
		process_execution(a, b, /*c_iox,*/ actual, &tmp_len);
		actual = *a;
		update_chunk_index(*a, &c_iox, flag);
		*stack_length = tmp_len;
	  
	}

}


int first_sort(t_node_stack **a, t_node_stack **b)
{
	size_t slen_a;
	size_t tmp_slen_a;
  
	slen_a = stack_len(*a);
	tmp_slen_a = slen_a;    
	print_chunks(*a);
	sort_c_iox(a, b, &tmp_slen_a, 1);
	sort_c_iox(a, b, &tmp_slen_a, 2);
	sort_c_iox(a, b, &tmp_slen_a, 3);
	three(a);
	return(0);
}


//sixth
void assign_flag_to_node(t_node_stack *node, size_t min, size_t mid, size_t max)
{
	if (node->tar_index >= max)
	{
		node->flag_0_3 = 3;
		node->max = true;
	}
	else if (node->tar_index >= mid && node->tar_index < max)
	{
		node->flag_0_3 = 2;
		node->mid = true;
	}
	else if (node->tar_index >= min && node->tar_index < mid)
	{
		node->flag_0_3 = 1;
		node->min = true;
	}
	else
	{
		node->flag_0_3 = 0;
		node->def = true;
	}
}

void flag_stack_nodes(t_node_stack *stack, size_t min, size_t mid, size_t max)
{
	while (stack != NULL)
	{
		assign_flag_to_node(stack, min, mid, max);
		stack = stack->next;
	}
}

void calculate_chunks(size_t stacklen, size_t *min, size_t *mid, size_t *max)
{
	size_t len_of_chunk;
	int remainder; 
	
	len_of_chunk = stacklen / 3;
	remainder = stacklen % 3;
	*min = 0;
	*mid = *min + len_of_chunk;
	*max = *mid + len_of_chunk;

	if (remainder > 0)
	{
		(*max) += 1;
		remainder--;
	}
	if (remainder > 0)
	{
		(*mid) += 1;
	}
}

void set_price(t_node_stack *stack)
{
	size_t len_a;
	size_t median;

	len_a = stack_len(stack);
	median = len_a / 2;
	while (stack != NULL)
	{   
		if(stack->flag_0_3 < 4 )
		{
			(*stack).cost = (*stack).index;
			if ((*stack).index <= median) //<
			{
				(*stack).cost = (*stack).cost;
			}
			else if((*stack).index > median) //>=
			{   
				(*stack).cost = len_a - (*stack).cost;
			  
			}
		}
		stack = (*stack).next;
	}    
}

void actindex(t_node_stack *stack)
{
	size_t i;

	i = 0;
	if (stack == NULL)
	{
		return;
	}
	while (stack != NULL)
	{
		((*stack).index) = i;
		stack = (*stack).next;
		i++;
	}
} 

void flag_stack(t_node_stack *stack, size_t stacklen)
{
	size_t min; 
	size_t mid; 
	size_t max;
	
	calculate_chunks(stacklen, &min, &mid, &max);
	flag_stack_nodes(stack, min, mid, max);
}

void default_flag(t_node_stack *stack)
{
	while (stack != NULL)
	{
		if((*stack).flag_0_3 != 0 && (*stack).flag_0_3 <= 3)
		{
			(*stack).flag_0_3 = 0;
		}
		stack = stack->next;
	}
}

void defaults(t_node_stack *stack)
{
	default_flag(stack);
	flag_stack(stack, stack_len(stack));
	actindex(stack);
	set_price(stack);
}


//fifth
void three(t_node_stack **a)
{
	t_node_stack *bigboy;

	bigboy = find_biggest(*a);
	if (bigboy == *a)
		ra(a);
	else if (bigboy == (**a).next)
		rra(a);
	if ((**a).tar_index > (*(**a).next).tar_index)
		sa(a);

}

void others(t_node_stack **a, t_node_stack **b)
{
	int tracker;
	size_t total_len;

	total_len = stack_len(*a);
	if(*b == NULL)
	{
		defaults(*a);
		tracker = first_sort(a, b);
		if (tracker == 0)
		{
			sort_blok(a, b, total_len);
		}
		if (!sorted_stack(*a))
		{
			final_sort(a);
		}
		ft_stack_free(b);
	}
}

//forth
void handle_error(t_node_stack **a)
{
	ft_stack_free(a);
	ft_putstr("Error\n");
	exit(1);
}

void ft_putstr(char *str)
{
	size_t count;
	count = 0;
	if (str == NULL) {
		return;
	}
	while(str[count])
		count++;
	size_t result = write(1, str, count);
	if (result == 0) {
		//perror("write failed"); // Print error message if write fails
	} else if (result < count) {
		// Handle partial write if needed
		//perror("write did not write all bytes");
	}
 }

static void rev_rot(t_node_stack **stack)
{
	t_node_stack *last_node;


	if (!*stack || !(**stack).next)
	{
		return;
	}
	last_node = find_last_node(*stack);
	(*last_node).next = *stack;
	(*(*last_node).prev).next = NULL;
	(*last_node).prev = NULL;
	(**stack).prev = last_node;
	*stack = (**stack).prev;
}

static void rot(t_node_stack **stack)
{
	t_node_stack *last_node;

	if(!*stack || !(**stack).next)
	{
		return;
	}
	last_node = find_last_node(*stack);
	(*last_node).next = *stack;
	(*stack)->prev = last_node;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	(*(*last_node).next).next = NULL;
}

static void push(t_node_stack **from, t_node_stack **to)
{
	t_node_stack *pushed;

	if (!*from)
		return;
	pushed = *from;
	*from = (**from).next;
	if(*from)
	{
		(**from).prev = NULL;
	}
	(*pushed).prev = NULL;
	if (!*to)
	{
		*to = pushed;
		(*pushed).next = NULL;
	}
	else
	{
		(**to).prev = pushed;
		(*pushed).next = *to;
		*to = (**to).prev;   
	}   
}

static void swap(t_node_stack **top) {
	if (!*top || !(**top).next)
		return;
	*top = (**top).next;
	(*(**top).prev).prev = *top;
	(*(**top).prev).next = (**top).next;
	if ((**top).next)
		(*(**top).next).prev = (**top).prev;
	(**top).next = (**top).prev;
	(**top).prev = NULL;
}

void sa(t_node_stack **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void sb(t_node_stack **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void ss(t_node_stack **a, t_node_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}

void pa(t_node_stack **b, t_node_stack **a)
{
	push(b, a);
	ft_putstr("pa\n");
}

void pb(t_node_stack **a, t_node_stack **b)
{
	push(a, b);
	ft_putstr("pb\n");
}

void ra(t_node_stack **a)
{
	rot(a);
	ft_putstr("ra\n");
}

void rb(t_node_stack **b)
{
	rot(b);
	ft_putstr("rb\n");
}

void rr(t_node_stack **a, t_node_stack **b)
{
	rot(a);
	rot(b);
	ft_putstr("rr\n");
}

void rra(t_node_stack **a)
{
	rev_rot(a);
	ft_putstr("rra\n");
}

void rrb(t_node_stack **b)
{
	rev_rot(b);
	ft_putstr("rrb\n");
}

void rrr(t_node_stack **a, t_node_stack **b)
{
	rev_rot(a);
	rev_rot(b);
	ft_putstr("rrr\n");
}

//third
t_node_stack *find_next_bigboy(t_node_stack *stack, int currentMax)
{
	t_node_stack *next_Bigboy = NULL;
	while (stack) {
		if (stack->value < currentMax && (next_Bigboy == NULL || stack->value > next_Bigboy->value)) {
			next_Bigboy = stack;
		}
		stack = stack->next;
	}
	return next_Bigboy;
}

t_node_stack *find_biggest(t_node_stack *stack)
{
	long    num;
	t_node_stack *bigboy;

	num = LONG_MIN;
	if (!stack)
		return(NULL);
	while (stack != NULL)
	{
		if(num < (*stack).value)
		{
			num = (*stack).value;
			bigboy = stack;
		}
		stack = (*stack).next;
	}
	return(bigboy);
}

t_node_stack *find_lowest(t_node_stack *stack)
{
	long	num;
	t_node_stack *smallboy;

	num = LONG_MAX;
	if (!stack)
		return(NULL);
	while (stack)
	{
		if (num > (*stack).value)
		{
			num = (*stack).value;
			smallboy = stack;
		}
		stack = (*stack).next;
	}
	return(smallboy);
}

size_t stack_len(t_node_stack *stack)
{
	size_t  counter;

	counter = 0;
	if (!stack)
		return(0);   
	while (stack)
	{
		stack = stack->next;
		counter++;
	}
	return(counter);
 }

void initialize_target_indices(t_node_stack *a, size_t *min_index, size_t *max_index)
{
	t_node_stack *smallest;
	t_node_stack *biggest;  
	
	biggest = find_biggest(a); 
	smallest  = find_lowest(a);
	*min_index = 0;
	*max_index = stack_len(a) - 1;

	if (smallest)
		smallest->tar_index = *min_index;
	if (biggest)
		biggest->tar_index = *max_index;
}

void assign_target_indices(t_node_stack *a, size_t *max_index, int currentMax)
{
	t_node_stack *nextBiggest;

	nextBiggest = find_next_bigboy(a, currentMax);
	while (nextBiggest)
	{
		if (nextBiggest->tar_index == 0)
		{
			currentMax = nextBiggest->value;
			nextBiggest->tar_index = --(*max_index);
			nextBiggest = find_next_bigboy(a, currentMax);
		}
		else
			a = a->next;
	}
}

void target_index(t_node_stack **a)
{
	size_t min_index;
	size_t max_index;
	t_node_stack *biggest;
	int currentMax;

	initialize_target_indices(*a, &min_index, &max_index);

	biggest = find_biggest(*a);
	if (biggest)
	{
		currentMax = biggest->value;
		assign_target_indices(*a, &max_index, currentMax);
	}
}



// void   target_index(t_node_stack **a)
//  {
//     size_t min_index = 0;
//     size_t max_index = stack_len(*a) - 1;
//     size_t currentMax;
//     t_node_stack *smallest = find_lowest(*a);
//     t_node_stack *biggest = find_biggest(*a);
//     t_node_stack *current = *a;
//     t_node_stack *nextBiggest;

//     currentMax = (*biggest).value;
//     biggest->tar_index = max_index;
//     smallest->tar_index = min_index;
//     nextBiggest = find_next_bigboy(current, currentMax);
//    while (nextBiggest) {
//         if (nextBiggest->tar_index == 0 && (*current).value == nextBiggest->value) {
//             currentMax = nextBiggest->value;
//             current->tar_index = --max_index;
//             nextBiggest = find_next_bigboy(*a, currentMax);
//             current = *a;
//         }
//         else if (current != NULL)
//         {
//             current = (*current).next; 
//         }
//     }
//  }

//second
bool sorted_stack(t_node_stack *stack)
{
	if (!stack)
		return(1);
	while (stack->next)
	{
		if (stack->tar_index > stack->next->tar_index)
		{
			return(false);
		}
		stack = stack->next;
	}
	return(true);
}

t_node_stack *find_last_node(t_node_stack *stack) 
{
	if(!(stack))
		return(NULL);
	while (stack->next)
		stack = stack->next;
	return(stack);
}
static void in_node(t_node_stack *node)
{
	node->index = 0;
	node->tar_index = 0;
	node->node_tar_index = 0;
	node->cost = 0;
	node->flag_0_3 = 0;
	node->cx = 0;
	node->co = 0;
	node->ci = 0;
	node->max = false;
	node->mid = false;
	node->min = false;
	node->def = false;
	node->abov_median = false;
	node->cheapest = false;
}
static void add_node(t_node_stack **stack, int num)
{
	t_node_stack *new_node;
	t_node_stack *last_node;

	if (!(stack))
		return;
	new_node = malloc(sizeof(t_node_stack));
	if (!(new_node))
		return;
	new_node ->next = NULL;
	new_node->value = num;
	in_node(new_node);
	if (!(*stack)) 
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else 
	{
		last_node = find_last_node(*stack);
		last_node->next = new_node; 
		new_node->prev = last_node; 
	}
}

int ft_dup_err(t_node_stack *a, int num)
{
	if(!a)
		return(0);
	while (a)
	{
		if(a -> value == num)
			return(1);
		a = a -> next;
	}
	return(0);
}

static long ft_atol(const char *str)
{
	long res;
	int sign;

	res = 0;
	sign = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n' || 
			*str == '\v' || *str == '\f' || *str == '\r')
	str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			sign = -1;
		}
		str++;
	}
	while (*str >= 48 && *str <= 57 && *str)
	{
		res = res * 10 + (*str++ - '0');
	}
	return(res * sign);    
}

void ft_stack_free(t_node_stack **stack)
{
	t_node_stack *nxt_tmp;
	t_node_stack *actual;

	if (!stack || !*stack)
		return;

	actual = *stack;
	while (actual)
	{
		nxt_tmp = actual->next;
		free(actual);
		actual = nxt_tmp;
	}
	*stack = NULL;
}

int ft_syntax_err(char *str)
{

	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return 1;
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return 1;
	++str;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return 1;
		str++;
	}
	return 0;
}

void stack_init(t_node_stack **a, char **argv)
{
	long    num;
	size_t  i;

	i = 0;

	while (argv[i])
	{
		if (ft_syntax_err(argv[i]))
			handle_error(a);
		num = ft_atol(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			handle_error(a);
		if (ft_dup_err(*a, (int)num))
			handle_error(a);
		add_node(a,(int)num);  
		i++;
	}
	
}

//first
static char *get_word(char *str, char c, bool yes)
{
	static size_t position = 0;
	char *next;
	size_t len;
	size_t i;
	
	len = 0;
	i = 0;
	if (yes)
	{
		while (str[position] == c)
		position++;
		while (str[position + len] != c && str[position + len])
		len++;
		next = malloc(len * sizeof(char) + 1);
		if(!next)
			return(NULL);
		 while (str[position] != c && str[position])
			next[i++] = str[position++];
		next[i] = '\0';
		return(next);
	}
	return(NULL);
 }

 bool ft_printable(char *str)
 {
	bool yes;

	yes = false;
	if(!str)
		return(0);
	while (*str)
	{
		if (*str >= 32 && *str <= 126)
		{
			yes = true;
		}
		str++;
	}
	return(yes);
 }

static size_t   word_counter(char *str, char c)
{
	size_t counter;
	bool in_word; 

	counter = 0;
	if (!str)
		return(0);
	while (*str)
	{
		in_word = false;
		while (*str == c)
			str++;
		while (*str && *str != c)
		{
			if(!in_word)
			{
				counter++;
				in_word = true;
			}
			str++;
		}
	}
	return(counter);
}

char	**ft_spliter(char *str, char c)
{
	size_t index;
	int word_count; 
	char **new_array;

	word_count = word_counter(str, c);
	index = 0;
	if (word_count == 0)
		exit(1);
	new_array = malloc(sizeof(char*) * (size_t)(word_count + 2));
	if (!new_array)
		return(NULL);
	while (word_count-- >= 0)
	{
		if (str[index] == 0)
		{
			new_array[index] = malloc(sizeof(char));
			if (new_array[index] == NULL)
				return (NULL);
			new_array[index++][0] = '\0';
			continue ;
		}
		new_array[index++] = get_word(str, c, ft_printable(str));
	}
	new_array[index] = NULL;
	return(new_array);  
}

int main(int argc, char **argv)
{
	t_node_stack *a;
	t_node_stack *b;

	a = NULL;
	b = NULL;
	if((argc == 1 || (argc == 2 && !argv[1][0])))
		argv = ft_spliter(argv[1], ' ');
	stack_init(&a, argv + 1);

	//  if((argc == 2))
	//     argv = ft_spliter(argv[1], ' ');
	// stack_init(&a, argv);

	target_index(&a);
	if (!((sorted_stack(a))))
	{ 
		if((stack_len(a) == 2))
		{
			sa(&a);
		}
		else if((stack_len(a) == 3))
		{
			three(&a);
		}
		else
		{
			others(&a, &b);
		}
	}
	actindex(a);
	// print_stack(a);
   // ft_stack_free(&b);
	ft_stack_free(&a);
	
	return (1);

}

