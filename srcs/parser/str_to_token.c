/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:51:30 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:51:33 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int str_to_token(char *str)
{
    char    **tab;
    t_token *token;

    tab = str_to_tab(str);
    if (tab == NULL)
        return (ERROR);
    token = tab_to_token(tab);
    free(tab);
    if (token == NULL)
        return (ERROR);
    if (conv_in_token(token) == ERROR)
    {
        free_all_token(&token);
        return (ERROR);
    }
    return (SUCCESS);
}
