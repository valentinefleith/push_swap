/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vafleith <vafleith@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:07:11 by vafleith          #+#    #+#             */
/*   Updated: 2024/05/09 17:01:09 by vafleith         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t ft_superstrlen(char *str, char c)
{
	size_t len;

	if (!str)
		return 0;
	len = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == c)
		str++;
	while (str[len])
		len++;
	return len;
}

int	are_unique_nb(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i;
		while (j < len)
		{
			if (i != j && tab[i] == tab[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}


int is_full_space(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return 0;
		str++;
	}
	return 1;
}
