/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:48:17 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/10 17:23:34 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = parse_args(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = malloc(sizeof(t_stack *));
	if (stack_b == NULL)
		return (1);
	*stack_b = NULL;
	//ft_print_stacks(*stack_a, *stack_b);
	fill_presort_indices(*stack_a, ft_stacklen(*stack_a));
	sort_stack(stack_a, stack_b);
	ft_print_stacks(*stack_a, *stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
}
