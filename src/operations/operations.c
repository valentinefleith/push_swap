/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:10:23 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 20:12:09 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap_2_first_elems(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	*stack = second;
	first->prev = second;
	second->prev = NULL;
}

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*from_first;
	t_stack	*to_first;

	if (!*from)
		return ;
	from_first = (*from)->next;
	if (from_first)
		from_first->prev = NULL;
	to_first = *from;
	to_first->next = *to;
	if (*to)
		(*to)->prev = to_first;
	*to = to_first;
	(*from) = from_first;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_stacklast(*stack);
	last->next = first;
	(first->next)->prev = NULL;
	first->prev = last;
	*stack = first->next;
	first->next = NULL;
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_stacklast(*stack);
	last->next = first;
	first->prev = last;
	(last->prev)->next = NULL;
	last->prev = NULL;
	*stack = last;
}
