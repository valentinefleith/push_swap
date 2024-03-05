/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:49:17 by vafleith          #+#    #+#             */
/*   Updated: 2024/03/05 13:56:22 by vafleith         ###   ########.fr       */
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
	void			*content;
	struct s_stack	*next;
	struct s_stack 	*previous;
}					t_stack;

void parse_args(int argc, char **argv);
// prototypes here

#endif
