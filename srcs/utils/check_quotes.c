/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:52:39 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:52:40 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_quotes(char *str)
{
    int i;
    int squote;
    int dquote;

    i = 0;
	squote = 0;
	dquote = 0;
    if (!str)
        return (0);
	while (str[i])
	{
		if (str[i] == '\'' && dquote == 0)
			squote = !squote;
		else if (str[i] == '\"' && squote == 0)
			dquote = !dquote;
        i++;
	}
    if (squote || dquote)
        return (0);
    else
	    return (1);
}
