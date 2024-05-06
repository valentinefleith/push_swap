/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:22:13 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 20:30:14 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_a(t_stack **stack)
{
	ft_rotate(stack);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack)
{
	ft_rotate(stack);
	ft_printf("rb\n");
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
