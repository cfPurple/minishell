/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_to_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfelix <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:45:33 by cfelix            #+#    #+#             */
/*   Updated: 2023/12/24 14:22:35 by cfelix           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*var_to_value(char *str)
{
	char	*new_str;

	if (ft_strlen(str) == 2 && str[1] == '?')
	{
		new_str = ft_itoa(g_error);
		return (new_str);
	}
	else
		new_str = var_to_env_value(str);
	return (new_str);
}
