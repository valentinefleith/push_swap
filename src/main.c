/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:48:17 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 14:45:17 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	*stack_b;

	stack_a = parse_args(argc, argv);
	stack_b = NULL;
	ft_printf("BEFORE SWAP:\n");
	ft_print_stacks(*stack_a, stack_b);
	ft_swap_2_first_elems(stack_a);
	ft_printf("AFTER SWAP:\n");
	ft_print_stacks(*stack_a, stack_b);
	ft_free_stack(stack_a);
}
