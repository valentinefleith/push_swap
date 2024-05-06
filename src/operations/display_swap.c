/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:17:33 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 20:20:12 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_stack **stack)
{
	ft_swap_2_first_elems(stack);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack)
{
	ft_swap_2_first_elems(stack);
	ft_printf("sb\n");
}

void	swap_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
