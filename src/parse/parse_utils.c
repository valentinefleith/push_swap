/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:07:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/09 14:09:31 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t ft_superstrlen(char *str, char c)
{
	size_t len;

	if (!str)
		return 0;
	len = 0;
	while (*str == c)
		str++;
	while (str[len])
		len++;
	return len;
}
