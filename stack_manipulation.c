/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:42:46 by matus             #+#    #+#             */
/*   Updated: 2024/10/29 17:45:32 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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