/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:05:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/05 13:56:19 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static t_stack *parse_one_arg(char *argv)
{
	char **args;
	t_stack *stack;

	if (!is_valid_one(argv))
	{
		ft_printf("Fromat error.\n");
		exit(ARGUMENT_ERROR);
	}
	args = ft_split(argv);
	if (args == NULL)
		exit(MALLOC_ERROR);
	stack = load_data(args);
	free(args);
	if (stack == NULL)
		exit(MALLOC_ERROR);
	return to_linked_list(args);
}

static t_stack *parse_several_args(char **argv)
{
	if (!is_valid_several(argv))
	{
		ft_printf("Format error.\n");
		exit(ARGUMENT_ERROR);
	}
	return (argv);
}

char **parse_args(int argc, char **argv)
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
