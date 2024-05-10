/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 02:37:51 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/10 14:28:35 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_print_lst(t_stack *stack)
{
	if (!stack)
	{
		ft_printf("NULL\n");
		return ;
	}
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
			break ;
		}
	}
}

void	ft_print_reverse_lst(t_stack *stack)
{
	if (!stack)
	{
		ft_printf("NULL\n");
		return ;
	}
	while (stack->next)
		stack = stack->next;
	while (stack)
	{
		if (stack->prev)
			ft_printf("%i -> ", stack->content);
		else
			ft_printf("%i\n", stack->content);
		stack = stack->prev;
	}
}

void	ft_print_indices(t_stack *stack)
{
	if (!stack)
	{
		ft_printf("NULL\n");
		return ;
	}
	while (stack)
	{
		if (stack->next)
		{
			ft_printf("%i -> ", stack->sorted_index);
			stack = stack->next;
		}
		else
		{
			ft_printf("%i\n", stack->sorted_index);
			break ;
		}
	}
}

void	ft_print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("stack a: ");
	ft_print_lst(a);
	//ft_print_reverse_lst(a);
	//ft_printf("stack b: ");
	//ft_print_lst(b);
	//ft_print_reverse_lst(b);
}
