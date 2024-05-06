/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 12:14:32 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 12:17:00 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_strs(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	*print_error_and_free_tab(int *tab)
{
	ft_printf("Format error.\n");
	free(tab);
	return (NULL);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*next;

	while (*stack)
	{
		next = (*stack)->next;
		free(*stack);
		*stack = next;
	}
	free(stack);
}
