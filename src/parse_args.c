/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:05:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/06 15:55:12 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO : check -0

#include "pushswap.h"

static int is_valid_one(char *strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		if ((!ft_isdigit(strs[i]) && strs[i] != '-') || (strs[i] == '-' && i != 0))
			return 0;
		i++;
	}
	return 1; 
}

static int are_valid_mult(char **strs)
{
	int i;

	i = 0;
	while (strs[i])
	{
		if (!is_valid_one(strs[i]))
			return 0;
		i++;
	}
	return 1;
}

static t_stack *parse_one_arg(char *argv)
{
	char **args;

	args = ft_split(argv, ' ');
	if (args == NULL)
		exit(MALLOC_ERROR);
	if (!are_valid_mult(args))
	{
		ft_printf("Format error.\n");
		exit(ARGUMENT_ERROR);
	}
	stack = arr_to_linked_list(args);
	free(args);
	if (stack == NULL)
		exit(MALLOC_ERROR);
	return stack;
}

static t_stack *parse_several_args(char **argv)
{
	argv++;
	if (!are_valid_mult(argv))
	{
		ft_printf("Format error.\n");
		exit(ARGUMENT_ERROR);
	}
	return arr_to_linked_list(argv); // NOT IMPLEMENTED
}

t_stack *parse_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error. You need to enter numbers in argument\n");
		exit(ARGUMENT_ERROR);
	}
	if (argc == 2)
		return parse_one_arg(argv[1]);
	return parse_several_args(argv);
}
