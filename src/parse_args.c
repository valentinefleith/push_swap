/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:05:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/06 12:24:00 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"


static int is_valid_one(char *str)
{
	int i;
	int at_least_one_dg;

	i = 0;
	at_least_one_dg = 0;
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-') || (str[i] == '-' && i != 0))
			return 0;
		if (ft_isdigit(str[i]))
			at_least_one_dg = 1;
		i++;
	}
	return at_least_one_dg; 
}

static t_stack *parse_one_arg(char *argv)
{
	char **args;
	t_stack *stack;

	if (!is_valid_one(argv))
	{
		ft_printf("Fromat error.\n");
		exit(ARGUMENT_ERROR);
	}
	args = ft_split(argv, ' ');
	if (args == NULL)
		exit(MALLOC_ERROR);
	stack = load_data(args);
	free(args);
	if (stack == NULL)
		exit(MALLOC_ERROR);
	return arr_to_linked_list(args);
}

// FOR TESTING :
// still one bug : verify number after split

//static void parse_one_arg(char *argv)
//{
//	char **args;
//
//	if (!is_valid_one(argv))
//	{
//		ft_printf("Fromat error.\n");
//		exit(ARGUMENT_ERROR);
//	}
//	args = ft_split(argv, ' ');
//	if (args == NULL)
//		exit(MALLOC_ERROR);
//	int i = 0;
//	while (args[i])
//	{
//		ft_printf("%i eme nombre : %s\n", i, args[i]);
//		i++;
//	}
//	free(args);
//}

static t_stack *parse_several_args(char **argv)
{
	if (!is_valid_several(argv)) // NOT IMPLEMENTED
	{
		ft_printf("Format error.\n");
		exit(ARGUMENT_ERROR);
	}
	return arr_to_linked_list(argv); // NOT IMPLEMENTED
}

void parse_args(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_printf("Error. You need to enter numbers in argument\n");
		exit(ARGUMENT_ERROR);
	}
	if (argc == 2)
		return parse_one_arg(argv[1]);
		//parse_one_arg(argv[1]); FOR TESTING
	return parse_several_args(argv);
}
