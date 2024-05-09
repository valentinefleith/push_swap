/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:05:41 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/09 15:58:03 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_valid_one(char *str)
{
	int	i;
	size_t len;

	len = ft_strlen(str);
	i = 0;
	if ((len == 1 && ft_strchr("+-", *str)) || (ft_superstrlen(str, '0') > 11))
		return (0);
	if (len == 2 && !ft_strncmp(str, "-0", 2))
		return (0);
	while (str[i])
	{
		if ((!ft_isdigit(str[i]) && !ft_strchr("+-", str[i])) || (ft_strchr("+-", str[i]) && i != 0))
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
	int		size;

	args = ft_split(argv, ' ');
	if (args == NULL)
		exit(MALLOC_ERROR);
	size = get_tab_size(args);
	if (!are_valid_mult(args))
	{
		ft_printf("Error.\n");
		ft_free_strs(args);
		exit(ARGUMENT_ERROR);
	}
	tab = ft_atoi_tab(args);
	ft_free_strs(args);
	if (tab == NULL)
		exit(MALLOC_ERROR);
	stack = arr_to_linked_list(tab, size);
	free(tab);
	if (stack == NULL)
		exit(MALLOC_ERROR);
	return (stack);
}

static t_stack	**parse_several_args(int argc, char **argv)
{
	int		*tab;
	t_stack	**stack;
	
	argv++;
	if (!are_valid_mult(argv))
	{
		ft_printf("Error.\n");
		exit(ARGUMENT_ERROR);
	}
	tab = ft_atoi_tab(argv);
	if (tab == NULL)
		exit(MALLOC_ERROR);
	stack = arr_to_linked_list(tab, argc - 1);
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
	{
		if (!argv[1][0] || is_full_space(argv[1]))
		{
			ft_printf("Error.\n");
			exit(ARGUMENT_ERROR);
		}
		return (parse_one_arg(argv[1]));
	}
	return (parse_several_args(argc, argv));
}
