/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:37:51 by vafleith          #+#    #+#             */
/*   Updated: 2024/04/10 03:02:52 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


void	ft_print_lst(t_stack *stack)
{
	while (stack)
	{
		if (stack->next)
		{
			ft_printf("%i -> ", stack->content);
			stack = stack->next;
		}
		else
		{
			ft_printf("%i\n", stack->content);
			break;
		}
	}
	while (stack)
	{
		if (stack->prev)
			ft_printf("%i -> ", stack->content);
		else
			ft_printf("%i\n", stack->content);
		stack = stack->prev;
	}
}


static void ft_print_stack_values(t_stack *longest, t_stack *shortest)
{
	int i;
	int len_long;
	int len_short;

	len_long = ft_stacklen(longest);
	len_short = ft_stacklen(shortest);
	i = 0;
	while (longest)
	{
		if (i < len_short)
		{
			ft_printf("%i\t%i\n", longest->content, shortest->content);
			shortest = shortest->next;
		}
		else
			ft_printf("%i\n", longest->content);
		longest = longest->next;
		i++;
	}
	ft_printf("-\t-\na\tb\n");	
}

void ft_print_stacks(t_stack *a, t_stack *b)
{
	int len_a;
	int len_b;

	len_a = ft_stacklen(a);
	len_b = ft_stacklen(b);
	if (len_a >= len_b)
		return ft_print_stack_values(a, b);
	return ft_print_stack_values(b, a);
}

