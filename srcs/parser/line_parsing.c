/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:50:58 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:26:20 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	line_parsing(char *str)
{
	if (*str == '\0')
		return (ERROR);
	if (check_spaces(str) == 1)
		return (ERROR);
	if (check_quotes(str) == 0)
		return (ERROR);
	if (str_to_token(str))
		return (ERROR);
	return (SUCCESS);
}
