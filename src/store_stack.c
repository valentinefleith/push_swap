/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 15:56:16 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 19:43:16 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static long	ft_atol(char *str)
{
	long	output;
	int		is_neg;

	if (!*str)
		return (0);
	while (ft_strchr(" \t\n\r\v\f", *str))
		str++;
	is_neg = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_neg = 1;
		str++;
	}
	output = 0;
	while (ft_isdigit(*str))
	{
		output = output * 10 + (*str - '0');
		str++;
	}
	if (is_neg)
		return (-output);
	return (output);
}

int	get_tab_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

static int	are_unique_nb(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (i != j && tab[i] == tab[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_atoi_tab(char **strs)
{
	int		i;
	long	current;
	int		*tab;
	int		size;

	size = get_tab_size(strs);
	tab = malloc(size * sizeof(int));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		current = ft_atol(strs[i]);
		if (current > INT_MAX || current < INT_MIN)
			return (print_error_and_free_tab(tab));
		tab[i] = (int)current;
		i++;
	}
	if (!are_unique_nb(tab, i))
		return (print_error_and_free_tab(tab));
	return (tab);
}

t_stack	**arr_to_linked_list(int *tab, int size)
{
	t_stack	**stack;
	t_stack	*new;
	int		i;

	i = 0;
	stack = malloc(sizeof(t_stack *));
	if (stack == NULL)
		return (NULL);
	*stack = NULL;
	while (i < size)
	{
		new = ft_stacknew(tab[i]);
		if (new == NULL)
		{
			ft_free_stack(stack);
			return (NULL);
		}
		ft_stackadd_back(stack, new);
		i++;
	}
	return (stack);
}
