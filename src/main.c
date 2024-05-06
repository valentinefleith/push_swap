/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:48:17 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 17:45:34 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = parse_args(argc, argv);
	stack_b = malloc(sizeof(t_stack *));
	if (stack_b == NULL)
		return (1);
	*stack_b = NULL;
	ft_printf("BEFORE PUSH:\n");
	ft_print_stacks(*stack_a, *stack_b);
	ft_push(stack_a, stack_b);
	ft_printf("AFTER PUSH:\n");
	ft_print_stacks(*stack_a, *stack_b);
	ft_push(stack_a, stack_b);
	ft_printf("PUSH AGAIN:\n");
	ft_print_stacks(*stack_a, *stack_b);
	// ft_printf("AFTER SWAP A:\n")
	// ft_swap_2_first_elems(stack_a);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
