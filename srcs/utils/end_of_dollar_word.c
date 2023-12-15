/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_dollar_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:55:21 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:55:22 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	end_of_dollar_word(char *str, int i)
{
	if (str[i] == '$')
	{
		i++;
		if (str[i] == '?')
			return (i + 1);
        else
        {
		    while (str[i] && (ft_isalpha(str[i]) || str[i] == '_'))
		    	i++;
        }
	}
	else
		while (str[i] && str[i] != '$')
			i++;
	return (i);
}
