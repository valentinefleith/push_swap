/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:49:17 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/06 16:27:14 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include "libft.h"
#include <stdlib.h>

# define MALLOC_ERROR 1
# define ARGUMENT_ERROR 2

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack 	*previous;
}					t_stack;

t_stack *parse_args(int argc, char **argv);
t_stack *arr_to_linked_list(char **strs);

// DOUBLY LINKED LISTS UTILS
t_stack *ft_stacknew(int content);
t_stack *ft_stacklast(t_stack *stack);
void ft_stackadd_back(t_stack **stack, t_stack **new);


// prototypes here

#endif
