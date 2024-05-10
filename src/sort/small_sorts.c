/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:01:35 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/10 19:50:07 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int get_target_pos(t_stack *stack, unsigned int target)
{
	int pos;

	pos = 0;
	while (stack)
	{
		if (stack->sorted_index == target)
		   return pos;
		pos++;
		stack = stack->next;
	}
	return pos;
}

static void sort_three(t_stack **stack, size_t size)
{
	if ((*stack)->sorted_index == size - 1)
		rotate_a(stack);
	if ((*stack)->next->sorted_index == size - 1)
		reverse_rotate_a(stack);
	if ((*stack)->sorted_index < (*stack)->next->sorted_index)
		return;
	return swap_a(stack);
}

static void sort_four(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	int min_pos;
	unsigned int target;
	
	if (size == 5)
		target = 1;
	else
		target = 0;
	min_pos = get_target_pos(*stack_a, target);
	if (min_pos < 2)
	{
		if (min_pos == 1)
			swap_a(stack_a);
	}
	else
	{
		if (min_pos == 2)
			reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	sort_three(stack_a, size);
	push_a(stack_a, stack_b);
}

static void sort_five(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	int min_pos;

	min_pos = get_target_pos(*stack_a, 0);
	if (min_pos < 3)
	{
		if (min_pos >= 1)
			rotate_a(stack_a);
		if (min_pos == 2)
			rotate_a(stack_a);
	}
	else
	{
		if (min_pos == 3)
			reverse_rotate_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	push_b(stack_a, stack_b);
	sort_four(stack_a, stack_b, size);
	push_a(stack_a, stack_b);
}

void small_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	if (size == 3)
		return sort_three(stack_a, size);
	if (size == 4)
		return sort_four(stack_a, stack_b, size);
	return sort_five(stack_a, stack_b, size);	
}
