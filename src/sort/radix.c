/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:23:45 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/10 14:28:01 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int get_max_bits(size_t size)
{
	unsigned int max_bits;
	unsigned int max_nb;

	max_nb = size - 1;
	max_bits = 0;
	while(max_nb >> max_bits)
		max_bits++;
	return max_bits;
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	unsigned int max_bits;
	unsigned int i;
	unsigned int j;
	size_t size;
	
	size = ft_stacklen(*stack_a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		if (is_sorted(*stack_a))
			return;
		j = 0;
		while (j < size)
		{
			if ((*stack_a)->sorted_index >> i & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		i++;
	}
}
