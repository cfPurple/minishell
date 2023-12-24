/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:53:29 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:58:40 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_word(char *str)
{
	int	i;
	int	j;
	int	state;

	i = 0;
	j = 1;
	state = open_quote(str, i);
	while (str[i])
	{
		if (open_quote(str, i) != state)
		{
			state = !state;
			j++;
		}
		i++;
	}
	return (j);
}
