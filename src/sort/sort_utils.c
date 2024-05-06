/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:45:48 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 20:50:47 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack *stack)
{
	int	current;

	if (!stack || !stack->next)
		return (1);
	current = stack->content;
	while (stack->next)
	{
		if (current > stack->next->content)
			return (0);
		stack = stack->next;
		current = stack->content;
	}
	return (1);
}
