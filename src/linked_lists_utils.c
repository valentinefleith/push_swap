/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:13:32 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/12 00:26:56 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = new;
	new->prev = last;
}

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		if (stack->next)
			ft_printf("%i -> ", stack->content);
		else
			ft_printf("%i\n", stack->content);
		stack = stack->next;
	}
	while (stack->prev)
	{
		if (stack->prev)
			ft_printf("%i ->", stack->content);
		else
			ft_printf("%i\n", stack->content);
		stack = stack->prev;
	}
}
