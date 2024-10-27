#include "push_swap.h"
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

