/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:49:17 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/12 00:05:47 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "libft.h"
#include <stdlib.h>

# define MALLOC_ERROR 1
# define ARGUMENT_ERROR 2

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack 	*prev;
}					t_stack;

t_stack **parse_args(int argc, char **argv);
t_stack **arr_to_linked_list(int *tab);
int *ft_atoi_tab(char **strs);

// DOUBLY LINKED LISTS UTILS
t_stack *ft_stacknew(int content);
t_stack *ft_stacklast(t_stack *stack);
void ft_stackadd_back(t_stack **stack, t_stack *new);



#endif
