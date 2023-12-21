/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_and_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:50:49 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/15 10:50:51 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int display_and_read(void)
{
    char *str;

    while(1)
    {
        str = readline("$> ");
        if (str == NULL)
            break;
        line_parsing(str);
        add_history(str);
        rl_on_new_line();
        free(str);
    }
    return (SUCCESS);
}
