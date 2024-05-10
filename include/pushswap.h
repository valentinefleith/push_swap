/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:49:17 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/10 13:16:16 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft.h"
# include <stdlib.h>

# define MALLOC_ERROR 1
# define ARGUMENT_ERROR 2

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int				content;
	unsigned int	sorted_index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

// PARSING
t_stack				**parse_args(int argc, char **argv);
t_stack				**arr_to_linked_list(int *tab, int size);
int					*ft_atoi_tab(char **strs);
int					get_tab_size(char **strs);
size_t				ft_superstrlen(char *str, char c);
int					is_full_space(char *str);
int					are_unique_nb(int *tab, int len);
char				*ft_join_args(int argc, char **argv);

// STACK OPERATIONS
void				ft_swap_2_first_elems(t_stack **stack);
void				ft_push(t_stack **from, t_stack **to);
void				ft_rotate(t_stack **stack);
void				ft_reverse_rotate(t_stack **stack);

void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);
void				swap_a(t_stack **stack);
void				swap_b(t_stack **stack);
void				swap_swap(t_stack **stack_a, t_stack **stack_b);
void				rotate_a(t_stack **stack);
void				rotate_b(t_stack **stack);
void				rotate_both(t_stack **stack_a, t_stack **stack_b);
void				reverse_rotate_a(t_stack **stack);
void				reverse_rotate_b(t_stack **stack);
void				reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

// SORT
int					is_sorted(t_stack *stack);
void				fill_presort_indices(t_stack *stack, size_t len);
void radix_sort(t_stack **stack_a, t_stack **stack_b);

// DOUBLY LINKED LISTS UTILS
t_stack				*ft_stacknew(int content);
int					ft_stacklen(t_stack *stack);
t_stack				*ft_stacklast(t_stack *stack);
void				ft_stackadd_back(t_stack **stack, t_stack *new);
void				ft_print_lst(t_stack *stack);
void				ft_print_reverse_lst(t_stack *stack);
void				ft_print_stacks(t_stack *a, t_stack *b);
void				ft_print_indices(t_stack *stack);

// FREE FUNCTIONS
void				ft_free_stack(t_stack **stack);
int					*print_error_and_free_tab(int *tab);
void				ft_free_strs(char **args);

#endif
