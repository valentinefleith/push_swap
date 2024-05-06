/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:05:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/06 11:39:09 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_valid_one(char *str)
{
	int	i;

	i = 0;
	if (!ft_strncmp(str, "-0", 2))
		return (0);
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && str[i] != '-') || (str[i] == '-' && i != 0))
			return (0);
		i++;
	}
	return (1);
}

static int	are_valid_mult(char **strs)
{
	int	i;
	int	j;

	i = 0;
	while (strs[i])
	{
		if (!is_valid_one(strs[i]))
			return (0);
		j = i;
		while (strs[j])
		{
			if (i != j && ft_strlen(strs[i]) == ft_strlen(strs[j])
				&& !ft_strncmp(strs[i], strs[j], ft_strlen(strs[i])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static t_stack	**parse_one_arg(char *argv)
{
	char	**args;
	int		*tab;
	t_stack	**stack;

	args = ft_split(argv, ' ');
	if (args == NULL)
		exit(MALLOC_ERROR);
	if (!are_valid_mult(args))
	{
		ft_printf("Format error.\n");
		free(args);
		exit(ARGUMENT_ERROR);
	}
	tab = ft_atoi_tab(args);
	free(args);
	if (tab == NULL)
		exit(MALLOC_ERROR);
	stack = arr_to_linked_list(tab);
	free(tab);
	if (stack == NULL)
		exit(MALLOC_ERROR);
	return (stack);
}

static t_stack	**parse_several_args(char **argv)
{
	int		*tab;
	t_stack	**stack;

	argv++;
	if (!are_valid_mult(argv))
	{
		ft_printf("Format error.\n");
		exit(ARGUMENT_ERROR);
	}
	tab = ft_atoi_tab(argv);
	if (tab == NULL)
		exit(MALLOC_ERROR);
	stack = arr_to_linked_list(tab);
	free(tab);
	if (stack == NULL)
		exit(MALLOC_ERROR);
	return (stack);
}

t_stack	**parse_args(int argc, char **argv)
{
	if (argc < 2)
		exit(ARGUMENT_ERROR);
	if (argc == 2)
		return (parse_one_arg(argv[1]));
	return (parse_several_args(argv));
}
