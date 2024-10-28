#include "../42/push_swap_final/push_swap.h"
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
void chasfe(t_node_stack **stack, t_node_stack *current)
{
    if (current->index == 0 && current->tar_index == 1)
    {
        sa(stack);
    }
}

void process_stack(t_node_stack **stack, size_t median)
{
    t_node_stack *current = *stack;

    while (current)
    {
        // chasfe(stack, current);
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
static void *set_target_node_b_test(t_node_stack *a, t_node_stack *b, size_t stack_len)
{
    t_node_stack *current_a;
    t_node_stack *target_node;
    size_t    best_index;
     
    target_node = NULL;
    while (b != NULL)
    {
        best_index = stack_len;
        current_a = a;
        while (current_a)
        {
            if ((*current_a).tar_index > (*b).tar_index 
                && (*current_a).tar_index < best_index)
            {
                best_index = (*current_a).tar_index;
                target_node = current_a;
            }
            current_a = (*current_a).next;
        }
        if(target_node != NULL)
        {
            (*b).node_tar_index = (*target_node).tar_index;
            (*b).target = (target_node);
        }
        b = (*b).next;
    }
    return target_node;
}
void median_flag(t_node_stack *stack, size_t median)
{
    while (stack)
    {
        if (stack->index >= median)
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
    while (stack)
    {
        stack->cheapest = false;
        stack = stack->next;
    }
}

void set_total_price(t_node_stack **b)
{
    t_node_stack *actual = *b;

    while (actual)
    {
        actual->cost += actual->target->cost;
        actual = actual->next;
    }
}
void prepare_stack_b(t_node_stack **a, t_node_stack **b, size_t total_len)
{
    reset_stack(*b);
    actindex(*b);
    set_price(*b);
    median_flag(*b, stack_len(*b) / 2);
    set_target_node_b_test(*a, *b, total_len);
}

void prepare_stack_a(t_node_stack **a)
{
    default_flag(*a);
    reset_stack(*a);
    actindex(*a);
    median_flag(*a, stack_len(*a) / 2);
    set_price(*a);
}

void case_1_op(t_node_stack **b, t_node_stack *cheapest)
{
    if (cheapest->abov_median)
        rb(b);
    else
        rrb(b);
}

void case_2_op(t_node_stack **a, t_node_stack *target)
{
    if (target->abov_median)
        ra(a);
    else
        rra(a);
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
            case_1_op(b, cheapest);
        else if (cheapest->index == 0 && target->index != 0)
            case_2_op(a, target);
        else if (cheapest->index != 0 && target->index != 0)
            case_3_op(a, b, cheapest, target);

        actindex(*a);
        actindex(*b);
    }
}

void psafch(t_node_stack **a, t_node_stack **b, size_t total_len, t_node_stack **cheapest, size_t flag)
{
    prepare_stack_a(a);
    prepare_stack_b(a, b, total_len);
    set_total_price(b);
    set_cheapest(*b, total_len, flag);
    *cheapest = retrun_cheapest(*b);
}

void sort_blok(t_node_stack **a, t_node_stack **b, size_t total_len)
{
    t_node_stack *target;
    t_node_stack *cheapest;
    size_t flag = 3;

    while (*b)
    {
        psafch(a, b, total_len, &cheapest, flag);
        target = cheapest->target;
        perform_operations(a, b, cheapest, target);

        if (target->index == 0 && cheapest->index == 0)
            pa(b, a);

        flag = check_flag(*b, &flag);
    }
}

//seventh
bool is_cheaper(t_node_stack *current_node, size_t *cheapest_index, t_node_stack *cheapest_node, size_t tmp_len)
{
    if (current_node->cost < *cheapest_index)
        return true;
    else if (current_node->cost == *cheapest_index)
    {
        if (current_node->index >= tmp_len / 2)
            return (!cheapest_node || current_node->tar_index > cheapest_node->tar_index);
        else
            return (!cheapest_node || current_node->tar_index < cheapest_node->tar_index);
    }
    return false;
}

size_t set_median(t_node_stack *stack, size_t flag)
{
    size_t sum = 0, counter = 0;

    while (stack)
    {
        if (stack->flag_0_3 == flag)
        {
            sum += stack->tar_index;
            counter++;
        }
        stack = stack->next;
    }
    return (counter > 0) ? sum / counter : 0;
}

void mark_as_cheapest(t_node_stack *cheapest_node)
{
    if (cheapest_node)
        cheapest_node->cheapest = true;
}

t_node_stack *find_cheapest_node(t_node_stack *stack, size_t flag, size_t total_len)
{
    size_t cheapest_index = total_len;
    size_t tmp_len = stack_len(stack);
    t_node_stack *cheapest_node = NULL;

    while (stack)
    {
        if (stack->flag_0_3 == flag && is_cheaper(stack, &cheapest_index, cheapest_node, tmp_len))
        {
            cheapest_index = stack->cost;
            cheapest_node = stack;
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

void print_chunks(t_node_stack *stack, int *cx, int *co, int *ci)
{
    *cx = 0;
    *co = 0;
    *ci = 0;
    while (stack)
    {
        if (stack->min)
            (*ci)++;
        else if (stack->mid)
            (*co)++;
        else if (stack->max)
            (*cx)++;
        stack = stack->next;
    }
}

void push_operation_ci(t_node_stack *cheapest_node, t_node_stack **a, t_node_stack **b, int *ci_iox, size_t *tmp_slen_a)
{
    static size_t chunk_median;
    static size_t flag;

    if (!chunk_median || flag != (*a)->flag_0_3)
    {
        flag = (*a)->flag_0_3;
        chunk_median = set_median(*a, flag);
    }

    if ((*a)->cheapest && *ci_iox != 0)
    {
        if (cheapest_node->tar_index >= chunk_median)
        {
                pb(a, b);
                (*tmp_slen_a)--;
        }
        else
        {   
            pb(a, b);
            rb(b); 
            (*tmp_slen_a)--;
        }
    }
}

void rotate_operation_ci(t_node_stack **a, t_node_stack *cheapest, int *ci, size_t median)
{
    while (!(*a)->cheapest && *ci != 0)
    {
        if (cheapest->index < median)
            ra(a);
        else
            rra(a);
    }
}

t_node_stack *retrun_cheapest(t_node_stack *stack)
{
    while (stack)
    {
        if (stack->cheapest)
            return stack;
        stack = stack->next;
    }
    return NULL;
}

void set_cheapest(t_node_stack *stack, size_t total_len, size_t flag)
{
    flag = check_flag(stack, &flag);
    t_node_stack *cheapest_node = find_cheapest_node(stack, flag, total_len);
    mark_as_cheapest(cheapest_node);
}

void update_chunk_index(t_node_stack *a, int **c_iox, size_t flag)
{
    if (flag == 1)
        *c_iox = &a->ci;
    else if (flag == 2)
        *c_iox = &a->co;
    else if (flag == 3)
        *c_iox = &a->cx;
}

void process_execution(t_node_stack **a, t_node_stack **b, int *c_iox, t_node_stack *cheapest, size_t *stack_length)
{
    size_t median = *stack_length / 2;
    rotate_operation_ci(a, cheapest, c_iox, median);
    push_operation_ci(cheapest, a, b, c_iox, stack_length);
    print_chunks(*a, &(*a)->cx, &(*a)->co, &(*a)->ci);
}

t_node_stack *process_iteration(t_node_stack **a, t_node_stack **b, int *c_iox, size_t *stack_length, size_t flag)
{
    actindex(*a);
    set_price(*a);
    set_cheapest(*a, *stack_length, flag);
    return retrun_cheapest(*a);
}

void handle_biggest(t_node_stack **a, t_node_stack *actual, t_node_stack *biggest)
{
    if (actual->tar_index == biggest->tar_index)
        ra(a);
}

void initialize_sorter(t_node_stack **a, size_t *stack_length, t_node_stack **actual, t_node_stack **biggest)
{
    *biggest = find_biggest(*a);
    (*biggest)->flag_0_3 = 0;
    *actual = *a;
    *stack_length = stack_len(*a);
}

void sort_c_iox(t_node_stack **a, t_node_stack **b, int *c_iox, size_t *stack_length, size_t flag)
{
    size_t tmp_len = *stack_length;
    t_node_stack *actual, *biggest;

    initialize_sorter(a, stack_length, &actual, &biggest);

    while (tmp_len > 3 && *c_iox != 0)
    {
        actual = process_iteration(a, b, c_iox, &tmp_len, flag);
        if (actual == biggest && flag >= 2)
            handle_biggest(a, actual, biggest);
        
        process_execution(a, b, c_iox, actual, &tmp_len);
        update_chunk_index(*a, &c_iox, flag);
    }
    *stack_length = tmp_len;
}

int first_sort(t_node_stack **a, t_node_stack **b)
{
    size_t slen_a = stack_len(*a);
    int cx, co, ci;

    print_chunks(*a, &cx, &co, &ci);
    sort_c_iox(a, b, &ci, &slen_a, 1);
    sort_c_iox(a, b, &co, &slen_a, 2);
    sort_c_iox(a, b, &cx, &slen_a, 3);
    three(a);
    return 0;
}



//sixth
void assign_flag_to_node(t_node_stack *node, size_t min, size_t mid, size_t max)
{
    if (node->tar_index >= max)
    {
        node->flag_0_3 = 3;
        node->max = true;
    }
    else if (node->tar_index >= mid)
    {
        node->flag_0_3 = 2;
        node->mid = true;
    }
    else if (node->tar_index >= min)
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
    while (stack)
    {
        assign_flag_to_node(stack, min, mid, max);
        stack = stack->next;
    }
}

void set_price(t_node_stack *stack)
{
    size_t len_a = stack_len(stack);
    size_t median = len_a / 2;

    while (stack)
    {   
        if (stack->flag_0_3 < 4)
        {
            stack->cost = stack->index;
            if (stack->index >= median)
                stack->cost = len_a - stack->index;
        }
        stack = stack->next;
    }
}

void actindex(t_node_stack *stack)
{
    size_t i = 0;

    while (stack)
    {
        stack->index = i;
        stack = stack->next;
        i++;
    }
}
void flag_stack(t_node_stack *stack, size_t stacklen)
{
    size_t min, mid, max;

    calculate_chunks(stacklen, &min, &mid, &max);
    flag_stack_nodes(stack, min, mid, max);
}

void default_flag(t_node_stack *stack)
{
    while (stack)
    {
        if (stack->flag_0_3 != 0 && stack->flag_0_3 <= 3)
            stack->flag_0_3 = 0;
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

void calculate_chunks(size_t stacklen, size_t *min, size_t *mid, size_t *max)
{
    size_t len_of_chunk = stacklen / 3;
    int remainder = stacklen % 3;

    *min = 0;
    *mid = *min + len_of_chunk;
    *max = *mid + len_of_chunk;

    if (remainder > 0)
    {
        (*max)++;
        remainder--;
    }
    if (remainder > 0)
    {
        (*mid)++;
    }
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
    
    if (!*b)
    {
        defaults(*a);
        tracker = first_sort(a, b);

        if (tracker == 0)
            sort_blok(a, b, total_len);

        if (!sorted_stack(*a))
            final_sort(a);
    }
}

//instructions
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
    ft_putstr_fd("sa\n", 2);
    
}

void sb(t_node_stack **b)
{
    swap(b);
    ft_putstr_fd("sb\n", 2);
    
}

void ss(t_node_stack **a, t_node_stack **b)
{
    swap(a);
    swap(b);
    ft_putstr_fd("ss\n", 2);
    
}

void pa(t_node_stack **b, t_node_stack **a)
{
    push(b, a);
    ft_putstr_fd("pa\n", 2);
    
}

void pb(t_node_stack **a, t_node_stack **b)
{
    push(a, b);
    ft_putstr_fd("pb\n", 2);
    
}

void ra(t_node_stack **a)
{
    rot(a);
    ft_putstr_fd("ra\n", 2);
    
}

void rb(t_node_stack **b)
{
    rot(b);
    ft_putstr_fd("rb\n", 2);
    
}

void rr(t_node_stack **a, t_node_stack **b)
{
    rot(a);
    rot(b);
    ft_putstr_fd("rr\n", 2);
    
}

void rra(t_node_stack **a)
{
    rev_rot(a);
    ft_putstr_fd("rra\n", 2);
    
}

void rrb(t_node_stack **b)
{
    rev_rot(b);
    ft_putstr_fd("rrb\n", 2);
    
}

void rrr(t_node_stack **a, t_node_stack **b)
{
    rev_rot(a);
    rev_rot(b);
    ft_putstr_fd("rrr\n", 2);
    
}


//forth

void free_args(char **args)
{
    size_t i;

    if (!args)
        return;
    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
}

void process_stack(t_node_stack **a, t_node_stack **b)
{
    int len;

    len = stack_len(*a);
    if (len == 2)
        sa(a);
    else if (len == 3)
        three(a);
    else
        others(a, b);
}

//third
t_node_stack *find_next_bigboy(t_node_stack *stack, int currentMax)
{
    t_node_stack *next_Bigboy;

    next_Bigboy = NULL;
    while (stack)
    {
        if (stack->value < currentMax &&
            (!next_Bigboy || stack->value > next_Bigboy->value))
            next_Bigboy = stack;
        stack = stack->next;
    }
    return next_Bigboy;
}

t_node_stack *find_biggest(t_node_stack *stack)
{
    long num;
    t_node_stack *bigboy;

    num = LONG_MIN;
    bigboy = NULL;

    while (stack)
    {
        if (num < stack->value)
        {
            num = stack->value;
            bigboy = stack;
        }
        stack = stack->next;
    }
    return bigboy;
}

t_node_stack *find_lowest(t_node_stack *stack)
{
    long num;
    t_node_stack *smallboy;

    num = LONG_MAX;
    smallboy = NULL;

    while (stack)
    {
        if (num > stack->value)
        {
            num = stack->value;
            smallboy = stack;
        }
        stack = stack->next;
    }
    return smallboy;
}

void initialize_target_indices(t_node_stack *a, size_t *min_index, size_t *max_index)
{
    t_node_stack *smallest = find_lowest(a);
    t_node_stack *biggest = find_biggest(a);

    *min_index = 0;
    *max_index = stack_len(a) - 1;

    if (smallest)
        smallest->tar_index = *min_index;
    if (biggest)
        biggest->tar_index = *max_index;
}

void assign_target_indices(t_node_stack *a, size_t *max_index, int currentMax)
{
    t_node_stack *nextBiggest = find_next_bigboy(a, currentMax);

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
    int currentMax;

    initialize_target_indices(*a, &min_index, &max_index);

    t_node_stack *biggest = find_biggest(*a);
    if (biggest)
    {
        currentMax = biggest->value;
        assign_target_indices(*a, &max_index, currentMax);
    }
}


size_t stack_len(t_node_stack *stack)
{
    size_t counter;

    counter = 0;
    while (stack)
    {
        stack = stack->next;
        
    }
    return counter;
}

//second
bool sorted_stack(t_node_stack *stack)
{
    if (!stack)
        return 1;

    while (stack->next)
    {
        if (stack->tar_index > stack->next->tar_index)
            return 0;
        stack = stack->next;
    }
    return 1;
}

t_node_stack *find_last_node(t_node_stack *stack) 
{
    if (!stack)
        return NULL;

    while (stack->next)
        stack = stack->next;
    return stack;
}

static void add_node(t_node_stack **stack, int num)
{
    t_node_stack *new_node;
    t_node_stack *last_node;

    if (!stack)
        return;
    
    new_node = malloc(sizeof(t_node_stack));
    if (!new_node)
        return;

    new_node->value = num;
    new_node->next = NULL;

    if (!*stack)
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
    if (!a)
        return 1;

    while (a)
    {
        if (a->value == num)
            return 1;
        a = a->next;
    }
    return 0;
}

static long ft_atol(const char *str)
{
    long res = 0;
    int sign = 1;

    while (*str == ' ' || *str == '\t' || *str == '\n' ||
           *str == '\v' || *str == '\f' || *str == '\r')
        str++;
    
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    
    while (*str >= '0' && *str <= '9')
        res = res * 10 + (*str++ - '0');
    
    return res * sign;
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

    str++;
    while (*str)
    {
        if (!(*str >= '0' && *str <= '9'))
            return 1;
        str++;
    }
    return 0;
}

int stack_init(t_node_stack **a, char **argv)
{
    long num;
    size_t i; 
    i = 0;
    while (argv[i])
    {
        if (ft_syntax_err(argv[i]))
        {
            ft_stack_free(a);
            return(0);
        }
        num = ft_atol(argv[i]);
        if (num < INT_MIN || num > INT_MAX)
        {
            ft_stack_free(a);
            return(0);
        }
        if (ft_dup_err(*a, (int)num))
        {
            ft_stack_free(a);
            return(0);
        }
        add_node(a,(int)num);  
        i++;
    }
    return(1);
}



//first
static char *get_word(char *str, char c, bool yes)
{
    static size_t pos;
    size_t len;
    size_t i;
    char *next;

    pos = 0;
    len = 0;
    i = 0;

    if (!yes)
        return NULL;

    while (str[pos] == c)
        pos++;
    while (str[pos + len] && str[pos + len] != c)
        len++;

    next = malloc((len + 1) * sizeof(char));
    if (!next)
        return NULL;

    while (i < len)
        next[i++] = str[pos++];
    next[i] = '\0';

    return next;
}

int ft_printable(char *str)
{
    while (*str)
    {
        if (*str >= 32 && *str <= 126)
            return 1;
        str++;
    }
    return 0;
}

static size_t word_counter(char *str, char c)
{
    size_t counter;
    bool in_word;

    counter = 0;
    in_word = false;

    while (*str)
    {
        if (*str != c && !in_word)
        {
            
            in_word = true;
        }
        else if (*str == c)
            in_word = false;
        str++;
    }
    return counter;
}

char **ft_spliter(char *str, char c)
{
    int word_count;
    size_t index;
    char **new_array;

    word_count = word_counter(str, c);
    index = 0;

    if (word_count <= 0)
        return NULL;

    new_array = malloc(sizeof(char*) * (size_t)(word_count + 1));
    if (!new_array)
        return NULL;

    while (word_count-- > 0)
    {
        new_array[index] = get_word(str, c, ft_printable(str));
        if (!new_array[index])
        {
            while (index > 0)
                free(new_array[--index]);
            free(new_array);
            return NULL;
        }
        index++;
    }
    new_array[index] = NULL;
    return new_array;
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}

void handle_error(void)
{
    ft_putstr_fd("Error\n", 2);
}

char **get_arguments(int argc, char **argv)
{
    char **args;

    if (argc == 2)
    {
        args = ft_spliter(argv[1], ' ');
        if (!args)
            handle_error();
        return args;
    }
    else
    {
        return argv + 1;
    }
}

int main(int argc, char **argv)
{
    t_node_stack *a;
    t_node_stack *b;
    char **args;

    a = NULL;
    b = NULL;

    if (argc == 1)
        return 0;
    if (argc == 2 && !argv[1][0])
    {
        handle_error();
        return 1;
    }

    args = get_arguments(argc, argv);
    if (!stack_init(&a, args))
    {
        handle_error();
        return 1;
    }
    if (argc == 2)
        free_args(args);
    target_index(&a);
    if (!sorted_stack(a))
        process_stack(&a, &b);
    actindex(a);
    ft_stack_free(&b);
    ft_stack_free(&a);

    return 0;
}

