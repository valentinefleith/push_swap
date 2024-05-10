/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 17:01:35 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/10 17:27:57 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

void small_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	if (size == 3)
		return sort_three(stack_a, size);
	return;	
}
