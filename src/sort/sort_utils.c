/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:45:48 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/08 16:30:12 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack *stack)
{
	int	current;

	if (!stack || !stack->next)
		return (1);
	current = stack->content;
	while (stack->next)
	{
		if (current > stack->next->content)
			return (0);
		stack = stack->next;
		current = stack->content;
	}
	return (1);
}

static int	get_min(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

static t_stack	*get_next_min(t_stack *stack, int absolute_min)
{
	t_stack	*min_node;

	while (stack)
	{
		if (stack->content != absolute_min && stack->sorted_index == 0)
		{
			min_node = stack;
			break ;
		}
		stack = stack->next;
	}
	while (stack)
	{
		if (stack->content < min_node->content && stack->content != absolute_min
			&& stack->sorted_index == 0)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

void	fill_presort_indices(t_stack *stack, size_t len)
{
	unsigned int	sorted_index;
	int				min_val;
	t_stack			*current_min_node;

	sorted_index = 1;
	min_val = get_min(stack);
	while (sorted_index < len)
	{
		current_min_node = get_next_min(stack, min_val);
		current_min_node->sorted_index = sorted_index;
		sorted_index++;
	}
}
