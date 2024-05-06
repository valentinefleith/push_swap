/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_reverse_rotate.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:24:31 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 20:26:27 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	reverse_rotate_a(t_stack **stack)
{
	ft_reverse_rotate(stack);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack)
{
	ft_reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
	ft_printf("rrr\n");
}
